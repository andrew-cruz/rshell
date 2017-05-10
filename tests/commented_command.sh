#!/bin/sh
make clean; make; ./rshell
echo hello world
#this shouldn't be outputted
ls -a
exit
