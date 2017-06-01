#!/bin/sh
cd ..
make clean
make
clear
bin/rshell << starting program
(echo A && echo B) || (echo C && echo D)
(echo this || echo doesnt) && echo work
ls -l || (echo this && echo should) && (echo work);
(echo A || echo B) && ls -l || (echo C && echo D)
(echo A || echo B) && ls -l
(echo A || echo B) && ls -l || (echo C && echo D) && echo hi
exit
make clean
