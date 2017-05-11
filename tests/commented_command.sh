#!/bin/sh
cd ..
make clean
make
clear
bin/rshell << starting program
echo date #comment
#comment date
echo ps
ps #comment
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
ls #comment -a
echo  temp
 temp
echo ls -l
ls -l
echo rm text.txt
rm text.txt
echo ls -l #comment -a
ls -l #comment -a
echo rmdir temp
rmdir temp
echo ls -l -a #comment
#commentls -l -a #comment
make clean
exit
