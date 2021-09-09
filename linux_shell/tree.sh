#!/bin/bash 

read L M 
ans=0
declare -a tree
for (( i=0; i<${L}+1; i++)); do
    tree[${i}]=1
done

for (( j=0; j<M; j++ )); do
    read a b
    for (( k=${a}; k<=${b}; k++ ));do 
        tree[${k}]=0;
    done
done

for (( l=0; l<${L}+1; l++ ));do
    if [[ ${tree[${l}]} == 1 ]];then
        ans=$[${ans}+1]
    fi
done

echo ${ans}
