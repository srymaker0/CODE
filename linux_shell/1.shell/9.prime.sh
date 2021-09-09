#!/bin/bash
function Usage(){
    echo "Usage : $0 start_num end_num" #$0获取当前执行shell脚本的文件名，包括路径
    exit
}

function is_prime(){
    num=$1
    local i
    for (( i=2; i<${num}; i++ ));do
        if [[ $[ ${num} % $i ] -eq 0 ]];then
            return 1
        fi
    done
    return 0
}

if [[ $# -ne 2 ]];then # $#得到执行当前脚本的参数个数
    Usage
fi

Start=$1
End=$2

for ((i=${Start}; i<=${End}; i++));do
    is_prime $i  #函数的调用
    if [[ $? -eq 0 ]];then
        sum=$[ ${sum} + $i ]
    fi
done

echo $sum
