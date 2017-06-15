#!/bin/sh
cat < testFile
cat < testFile2 > output
cat < file3 | tr A-Z a-z
touch out.txt
echo hello > out.txt
echo my world >> out.txt
echo bye >> out.txt
sort < out.txt
rm out.txt
exit