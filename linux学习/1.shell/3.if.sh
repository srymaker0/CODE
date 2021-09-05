#!/bin/bash
TargetFile="a.c"
if [[ -r ${TargetFile} ]];then
    gcc a.c -o a
    ./a
else
    echo "${TargetFile} not Found!"
fi
