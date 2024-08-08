#include <stdio.h>

// Hàm đệ quy để tính số Fibonacci tại vị trí thứ n
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Hàm đệ quy để tìm số Fibonacci lớn nhất nhỏ hơn n
int timFibonacciLonNhatDeQuy(int n) {
    int i = 0;
    while (fibonacci(i) < n) {
        i++;
    }
    return fibonacci(i - 1);
}

// Hàm khử đệ quy để tìm số Fibonacci lớn nhất nhỏ hơn n
int timFibonacciLonNhatKhongDeQuy(int n) {
    int a = 0, b = 1, c = 1;
    while (c < n) {
        a = b;
        b = c;
        c = a + b;
    }
    return b;
}

int main() {
    int n;

    printf("Nhap so nguyen n: ");
    scanf_s("%d", &n);

    printf("So Fibonacci lon nhat nho hon %d (su dung de quy): %d\n", n, timFibonacciLonNhatDeQuy(n));
    printf("So Fibonacci lon nhat nho hon %d (khong su dung de quy): %d\n", n, timFibonacciLonNhatKhongDeQuy(n));

    return 0;
}
