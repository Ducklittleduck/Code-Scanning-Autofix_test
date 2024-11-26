#include <stdio.h>

void vulnerable_function(char *user_input) {
    // 不安全地将用户输入传递给 printf，造成格式化字符串漏洞
    printf("%s", user_input);
}

int main() {
    char user_input[256];
    
    printf("Enter some text: ");
    fgets(user_input, sizeof(user_input), stdin);
    
    // 去掉输入末尾的换行符
    user_input[strcspn(user_input, "\n")] = 0;
    
    // 调用存在格式化字符串漏洞的函数
    vulnerable_function(user_input);
    
    return 0;
}
