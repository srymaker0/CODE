#!/bin/bash 


read num
declare -a Prime
function init() {
    for (( i=2; i<=10000; i++ )); do
        if [[ ${Prime[${i}]}x == x ]];then
            Prime[0]=$[ ${Prime[0]} + 1 ]
            Prime[${Prime[0]}]=${i}
        fi
        for (( j=1; j<=${Prime[0]}; j++ )); do 
            if [[ $[ ${Prime[${j}]} * ${i} ] -gt 100000 ]];then
                break
            fi
            Prime[$[ ${i} * ${Prime[${j}]} ]]=1
            if [[ $[ ${i} % ${Prime[${j}]} ] -eq 0 ]];then
                break
            fi
        done
    done
}

init 


echo ${Prime[${num}]}




