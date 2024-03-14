# 定义变量
# 源文件列表
sources = list-test.c list.c
# 可执行文件的基础名
execbase = list

# 编译器名
CC = gcc
# 编译标志
CCFLAG = -g -Wall -std=c2x

# 检测是否是在Windows环境下
ifdef windir
# 在Windows下
# 可执行文件的后缀是.exe
target = $(execbase).exe
# 不支持内存消毒器
ASAN =
# 删除命令
RM = del
else
# 在Linux下
# 可执行文件没有后缀
target = $(execbase)
# 启用内存消毒器
ASAN = -fsanitize=address
# 删除命令
RM = rm
endif

# 声明clean是个伪任务
.PHONY: clean

# 任务all：启动编译器，用给定编译标志编译链接程序，生成指定名字的可执行文件
all:
# 除非指定用什么符号，任务名下的每条命令都**必须**用tab缩进，不能用空格！
# @符号：禁止显示命令本身
	@$(CC) $(sources) $(CCFLAG) $(ASAN) -o $(target) 

# 任务clean：清除可执行文件
clean:
	@$(RM) $(target)