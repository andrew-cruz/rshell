#!/bin/sh
cd ..
make clean
make
clear
bin/rshell << starting program
echo A #echo B
echo A #&& echo B
echo A && echo B #&& echo C
echo A #; echo B
echo A #|| echo B
#echo A
echo A #ehiaohehihfih
echo #Ahoefhiehf
echo B && echo B #ahfoiheihih
echo Hello World #
