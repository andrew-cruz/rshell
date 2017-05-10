#!/bin/sh
cd ..
make clean; make; ./rshell
ls -a; echo hello && mkdir test || echo world
echo where are you || ls -a && mkdir testing
