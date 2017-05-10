#!/bin/sh
cd ..
make clean; make; ./rshell
ls -l
echo hello
mkdir test
pwd
ls
rm test
