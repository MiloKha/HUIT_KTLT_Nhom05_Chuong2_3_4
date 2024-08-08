#include <stdio.h>

// Khai báo các hàm trước khi sử dụng
int tinhXn(int n);
int tinhYn(int n);

// Hàm đệ quy để tính Xn
int tinhXn(int n) {
    if (n == 0) {
        return 1; // X0 = 1
    }
    else {
        return tinhXn(n - 1) + tinhYn(n - 1); // Xn = Xn-1 + Yn-1
    }
}

// Hàm đệ quy để tính Yn
int tinhYn(int n) {
    if (n == 0) {
        return 0; // Y0 = 0
    }
    else {
        return 3 * tinhXn(n - 1) + 2 * tinhYn(n - 1); // Yn = 3*Xn-1 + 2*Yn-1
    }
}

int main() {
    int n;

    printf("Nhap so nguyen n: ");
    scanf_s("%d", &n);

    printf("Gia tri Xn tai vi tri thu %d la: %d\n", n, tinhXn(n));
    printf("Gia tri Yn tai vi tri thu %d la: %d\n", n, tinhYn(n));

    return 0;
}
