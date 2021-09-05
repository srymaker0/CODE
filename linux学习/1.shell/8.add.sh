#!/bin/bash
#for i in `seq 1 100`  #seq表示生成1-100的序列 但是效率低下 因为seq是个进程 系统会每次调用
sum=0
for (( i=1; i<=100; i++ ));do
    if [[ $[ ${i} % 2 ] -eq 0 ]];then
        sum=$[ ${sum} + ${i}]
    fi
done

echo "sum = ${sum}"
