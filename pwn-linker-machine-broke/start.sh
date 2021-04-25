#!/bin/bash

while [ true ]; do
	su -l $USER -c "socat -dd TCP4-LISTEN:9000,fork,reuseaddr SYSTEM:'env LD_LIBRARY_PATH=/build /build/$USER 2>&1',pty,echo=0,rawer,iexten=0"
done;
