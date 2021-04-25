#!/bin/bash

#Copy binary from temporary container
docker-compose up --no-start --build
docker cp $(docker ps -alq):/build .
docker cp -L $(docker ps -alq):/lib/x86_64-linux-gnu/libc.so.6 build

