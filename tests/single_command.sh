#!/bin/sh
make clean; make; ./rshell
ls -l
echo hello
mkdir test
pwd
ls
rm test
touch text.txt
echo take a look
rm text.txt
