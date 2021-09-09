#!/bin/bash 
if [[ $# -ne 2 ]];then
    echo "Usage : $0 start end"
    exit
fi


Start=$1
End=$2
declare -a Prime

function init() {
    local end=$1
    local i
    Prime[1]=1
    for (( i=2; i<=${end}; i++ )); do
        if [[ ${Prime[${i}]}x == x ]];then
            Prime[0]=$[ ${Prime[0]} + 1 ]
            Prime[${Prime[0]}]=${i}
        fi
        for (( j=1; j<=${Prime[0]}; j++ )); do 
            if [[ $[ ${Prime[j]} * ${i} ] -gt ${end} ]];then
                break
            fi
            Prime[$[ ${i} * ${Prime[j]} ]]=1
            if [[ $[ ${i} % ${Prime[j]} ] -eq 0 ]];then
                break
            fi
        done
    done
}

init ${End}
sum=0

for (( i=1; i<=${Prime[0]}; i++));do
    sum=$[ ${sum} + ${Prime[${i}]} ]
done

echo ${sum}
echo ${Prime[1000]}
