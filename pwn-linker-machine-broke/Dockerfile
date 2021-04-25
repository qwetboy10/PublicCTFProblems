FROM ubuntu:20.04

RUN apt-get update
RUN apt-get update && apt-get install -y build-essential socat libseccomp-dev

ARG FLAG
ARG USER
ENV USER $USER
ENV FLAG $FLAG

WORKDIR /
COPY start.sh /start.sh
RUN chmod 755 /start.sh

RUN useradd -m $USER

RUN echo "$FLAG" > /home/$USER/flag.txt
RUN chown root:root /home/$USER/flag.txt
RUN chmod 644 /home/$USER/flag.txt

EXPOSE 9000

WORKDIR /build
COPY client/linker .
COPY lib_v2/libflag.so .

WORKDIR /

ENV LD_LIBRARY_PATH=/build
CMD ["/start.sh"]
