#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[64];  // 固定大小的缓冲区

    // 直接将用户输入的字符串复制到缓冲区
    strcpy(buffer, input);  // 这里没有检查输入长度，导致溢出漏洞

    printf("You entered: %s\n", buffer);
}

int main() {
    char user_input[128];

    printf("Enter a string: ");
    fgets(user_input, sizeof(user_input), stdin);  // 获取用户输入

    // 去除输入中的换行符
    user_input[strcspn(user_input, "\n")] = 0;

    vulnerable_function(user_input);  // 调用存在漏洞的函数

}
