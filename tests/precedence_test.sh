#!/bin/sh
cd ..
make clean
make
clear
bin/rshell << starting program
(echo A && echo B) || (echo C && echo D)
(echo this || echo doesnt) && echo work
exit
make clean
