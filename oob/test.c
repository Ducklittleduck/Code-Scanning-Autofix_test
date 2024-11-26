#include <stdio.h>

void bad_function() {
    int a[5];
    a[5] = 10;  // 错误：数组越界，访问未定义的内存
    
    int *ptr;
    *ptr = 42;  // 错误：指针未初始化，解引用未初始化指针
    
    printf("a[5] = %d\n", a[5]);  // 错误：访问数组越界的元素
    return;
}

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    
    if (x == 0) {
        printf("You entered zero\n");
    } else {
        printf("You entered non-zero\n");
    }
    
    bad_function();  // 调用包含错误的函数

    return 0;
}
