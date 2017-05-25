#!/bin/sh
cd ..
make clean
make
clear
bin/rshell << starting program
(echo hi && ls -l || ( ls -m && echo bye && ( ls -l || mkdir b) ) )
(echo hi && ls -l || ( ls -m && echo bye && ( ls -l || mkdir b) ) ); (echo hi && ls -l || ( ls -m && echo bye && ( ls -l || mkdor b) ) ); (echo hi && ls -l || ( ls -m && echo bye && ( ls -l || mkdor b) ) )
echo hi && (ls -l || mkdir hi); exit;

make clean
