#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[64];
    // 不检查输入长度，直接将数据拷贝到缓冲区，导致可能的缓冲区溢出
    strcpy(buffer, input);
    printf("You entered: %s\n", buffer);
}

int main() {
    char user_input[256];
    
    printf("Enter some text: ");
    fgets(user_input, sizeof(user_input), stdin);
    
    // 去掉输入末尾的换行符
    user_input[strcspn(user_input, "\n")] = 0;
    
    // 调用存在漏洞的函数
    vulnerable_function(user_input);
    
    return 0;
}
