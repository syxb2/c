# 指定编译器
CC = gcc
# 指定编译选项
CFLAGS = -Wall -g -fsanitize=address
# 目标文件
TARGET = main
# 依赖的源文件
SRCS = main.c FileOperation.c

# 生成目标文件
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) 

# 清理目标文件和中间文件
clean:
	rm -f $(TARGET) *.o
