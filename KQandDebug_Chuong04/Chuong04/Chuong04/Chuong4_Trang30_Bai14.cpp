#include <stdio.h>

// Hàm tính tổng của dãy từ A1 đến An-1
int tinhTong(int n);

// Hàm tính giá trị của An
int tinhAn(int n) {
    if (n == 1) {
        return 1; // A1 = 1
    }
    else {
        int tong = tinhTong(n - 1);
        return n * tong; // An = n * (A1 + A2 + ... + An-1)
    }
}

// Hàm tính tổng của dãy từ A1 đến An-1
int tinhTong(int n) {
    if (n == 1) {
        return 1; // A1 = 1
    }
    else {
        return tinhAn(n - 1) + tinhTong(n - 1); // Tong = A1 + A2 + ... + An-1
    }
}

int main() {
    int n;

    printf("Nhap so nguyen n (n >= 1): ");
    scanf_s("%d", &n);

    if (n < 1) {
        printf("Gia tri n phai lon hon hoac bang 1.\n");
        return 1;
    }

    printf("Gia tri An tai vi tri thu %d la: %d\n", n, tinhAn(n));

    return 0;
}
