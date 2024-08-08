#include <stdio.h>

// Hàm đệ quy để tính số Fibonacci tại vị trí thứ n
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Hàm xuất dãy số Fibonacci có n phần tử
void xuatDayFibonacci(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int main() {
    int n;

    printf("Nhap so luong phan tu cua day Fibonacci: ");
    scanf_s("%d", &n);

    printf("Day Fibonacci co %d so la: ", n);
    xuatDayFibonacci(n);

    return 0;
}
