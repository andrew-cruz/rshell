#!/bin/sh
cd ..
make clean
make
clear
bin/rshell << starting program
echo date
date
echo ps
ps
echo ls
ls
echo touch text.txt
touch text.txt
echo ls
ls
echo mkdir temp
mkdir temp
echo ls -l
ls -l
echo mv text.txt /temp
mv text.txt /temp
echo ls -a
ls -a
echo ls -l
ls -l
echo rm text.txt
rm text.txt
echo ls -l -a
ls -l -a
echo rmdir temp
rmdir temp
echo ls -l -a #comment
ls -l -a #comment
make clean
exit
