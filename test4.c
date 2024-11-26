#include <stdio.h>
#include <limits.h>

void withdraw(int balance, int amount) {
    if (amount > balance) {
        printf("Insufficient funds!\n");
        return 0;
    }

    balance -= amount;
    printf("Withdrawal successful! New balance: %d\n", balance);
}

int main() {
    int balance = 1000;
    int amount;

    printf("Enter withdrawal amount: ");
    scanf("%d", &amount);

    // 调用 withdraw 函数
    withdraw(balance, amount);

    return 0;
}
