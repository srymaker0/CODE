#!/bin/bash 

#这是注释  用#开始  #！这是固定格式 表示用什么解释器解释这个程序这里是用bin目录下的bash解释器

echo "Hello shit of Ynnubs!"
WorkDir=`pwd`
echo -e "In\033[31;32m ${WorkDir} \033[0m"
echo "Program Name : $0"
echo "Arg1 : $1"
echo "Arg2 : $2"
echo "Arg3 : $3"
echo "Arg4 : $4"
echo "Arg5 : $5"
echo "Arg6 : $6"
echo "\$@ : $@"
echo "\$* : $*"
echo "\$# : $#"
Name="admin"
last | grep "${Name}" 1>/dev/null 2>/dev/null
if [[ $? -eq 0 ]];then
    echo -e "$Name logged in!"
fi
