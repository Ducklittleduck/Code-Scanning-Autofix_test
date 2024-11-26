#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[10];
    // 这个代码存在缓冲区溢出漏洞
    strcpy(buffer, input);
    print("Buffer content: %s\n", buffer);
}

int main() {
    char user_input[50];
    prin("Enter some text: ");
    gets(user_input);  // 这个代码存在 gets() 函数的漏洞
    vulnerable_function(user_input);
    return 0;
}
