#!/bin/sh
cat < existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2
ls -al | sort
ls -l | tr A-Z a-z
ps aux | tr a-z A-Z
ls | sort | tr a-z A-Z
(ls -l && echo hello) | tr a-z A-Z
exit