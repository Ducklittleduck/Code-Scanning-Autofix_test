# 编译器和编译选项
CC = gcc
CFLAGS = -Wall -g

# 目标文件
TARGET = my_project

# 源文件
SRC = main.c utils.c
OBJ = $(SRC:.c=.o)

# 默认目标
all: $(TARGET)

# 链接目标
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# 编译源文件为目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理编译结果
clean:
	rm -f $(OBJ) $(TARGET)

# 安装目标（可选）
install:
	cp $(TARGET) /usr/local/bin/

.PHONY: all clean install
