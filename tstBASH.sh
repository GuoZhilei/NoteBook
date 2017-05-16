#!/bin/bash

echo -e "Test Case & bash example by GuoZhilei";date

##使用终端打印
#echo "guozhilei"
#echo 'GUOZHILEI'
#echo guo zhilei
#echo '!!!'
#echo "!! ! "
##双引号不能加！？
#echo "can not include - ! - within double quotes"
#str=guozhilei
#echo "${str}"  #变量替换不能使用单引号
#

##printf打印的使用
#printf "%-5s %-10s %-4s\n" No Name Mark
#printf "%-5s %-10s %-4s\n" 1 guozhilei 100
#

##echo使用转义字符
#echo -e "\t1\t2\t3"
#

##打印颜色:
##重置0，黑色30，红色31，绿色32，黄色33 蓝色34
##洋红35，青色36，白色37
#echo -e "\e[1;0mThis is Reset（0）\e[0m"
#echo -e "\e[1;30mThis is Black（30）\e[0m"
#echo -e "\e[1;31mThis is Red（31）\e[0m"
#echo -e "\e[1;32mThis is Green（32）\e[0m"
#echo -e "\e[1;33mThis is Yellow（33）\e[0m"
#echo -e "\e[1;34mThis is Blue（34）\e[0m"
#echo -e "\e[1;35mThis is Magenta（35）\e[0m"
#echo -e "\e[1;36mThis is cyan blue(36)\e[0m"
#echo -e "\e[1;37mThis is White(37)\e[0m"
#

##打印背景颜色
##重置0，黑色40，红色41，绿色42，黄色43 蓝色44
##洋红45，青色46，白色47
#echo -e "\e[1;0mThis is Reset（0）\e[0m"
#echo -e "\e[1;40mThis is Black（40）\e[0m"
#echo -e "\e[1;41mThis is Red（41）\e[0m"
#echo -e "\e[1;42mThis is Green（42）\e[0m"
#echo -e "\e[1;43mThis is Yellow（43）\e[0m"
#echo -e "\e[1;44mThis is Blue（44）\e[0m"
#echo -e "\e[1;45mThis is Magenta（45）\e[0m"
#echo -e "\e[1;46mThis is cyan blue(46)\e[0m"
#echo -e "\e[1;47mThis is White(47)\e[0m"
#

##获取某个进程运行时的环境变量，用tr命令将'\0' 
##替换成'\n'输出,$$获取本进程pid
#cat /proc/$$/environ | tr '\0' '\n'
#

##获取字符串长度
#echo  ${SHELL} length is  ${#SHELL}
#

##识别当前的shell
#echo $SHELL

##判断使用脚本的用户是否是root用户
#if [ $UID -ne 0 ]; then
#	echo Non root usr,Please run as root.
#else
#	echo Root usr
#fi
#

##使用shell 进行计算,
##var=value是赋值，var = value 是相等操作
#n1=1
#let n1++  	#2
#n2=2
#let n2-- 	#1
#let n1+=6 	#8
#let n2-=6 	#-5
#let result=n1+n2 	#3
#echo $result
#echo $[ $n1 + 5 ]
#echo $[ n1 + n2 ] 	#可不用$符号
#echo $((n1 + 100))
#ret=`expr 3 + 4` 	#注意符号，加号两边有空格
#echo 'with space '$ret
#echo 'with space '$(expr $n1 + $n2) #必须加$符号
#ret1=`expr 3+4` 
#echo 'without space '$ret1
#echo 'without space '$(expr $n1+$n2) 
#

##bc高级工具的使用

##文件描述符以及重定向
#echo "This is a sample text 1" > temp.txt 	#截断加入
#echo "look! ";ls;cat temp.txt
#
#echo "This is a sample text 2" >> temp.txt #追加
#echo "look! ";ls;cat temp.txt
#

##命令执行成功，返回0。失败是非零值
#ls +;
#echo "commond error return: "$?
#
#ls;
#echo "commond success return: "$?
#

## 0stdin，1stdout, 2stderr重定向到文件
#ls + 2>stderr.txt
#echo "##stderr >stderr.txt, done, check it"
#ls;cat stderr.txt
#

##也可以单独分开设置
#ls + 2>stderr.txt 1>stdout.txt
#echo "##stderr >stderr.txt, stdout > stdout.txt"
#ls;cat stderr.txt;cat stdout.txt
#

##把stderr 和stdout 重定向到一个文件
# ls + &> output.txt

##将数据重定向到文件，并且提供一份重定向数据
##的副本作为后续命令的stdin,使用tee
#echo '--------test file Redirection Start ------'
#rm -rf a1 a2 a3 
#echo abcdefg > a1
#cp a1 a2; cp a2 a3
#chmod 000 a1
#
###所有信息都直接打印在终端
#echo '----------cat a*-----------'
#cat a*
#
#echo '----------cat a* 2>error.txt 1>message.txt-----------'
#cat a* 2>error.txt 1>message.txt
#echo "##cat error.txt message.txt";
#cat error.txt;
#echo '--------------'
#cat message.txt
#
###把stderr转化为stdout。使得stderr和stdout被重定向到
###同一个文件
#echo '----------cat a* 2>&1 outputall.txt-----------'
#cat a* &> outputall.txt
#echo "##cat outputall.txt";cat outputall.txt
#
#echo '----------cat a* 2>err.txt-----------'
#cat a* 2>err.txt #把错误信息重定向掉
#echo "##error message, cat err.txt"; cat err.txt
#
#echo '----------cat a* 2>/dev/null-----------'
#cat a* 2>/dev/null #把错误信息扔掉
#
###tee 命令接收来自stdin的数据，将stdout的数据副本写入
###out.txt。将另一个副本作为后续命令的stdin.
###cat -n 给stdin接收的数据加行号。
#echo '----------cat a* 2>error.txt |tee out.txt | cat -n-----------'
#cat a* 2>error.txt |tee out.txt | cat -n
#echo '##cat out.txt file'; cat out.txt
#echo '##cat error.txt file'; cat error.txt
#echo '--------test file Redirection End ------'
#


