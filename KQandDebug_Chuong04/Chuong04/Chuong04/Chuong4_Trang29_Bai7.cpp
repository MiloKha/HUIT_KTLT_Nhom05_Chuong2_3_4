#include <stdio.h>

int tinh_A1(int n);
int tinh_A2(int n);

int tinh_A1(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return -1;
    return 2 * tinh_A1(n - 1) - 3 * tinh_A1(n - 2) - tinh_A1(n - 3);
}

int tinh_A2(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    return 2 * tinh_A2(n - 1) + tinh_A2(n - 2) - 3 * tinh_A2(n - 3);
}

int main() {
    int choice, n;
    printf("Chon chuong trinh can tinh:\n");
    printf("1. Tinh A1(n) voi cong thuc A1(0) = 1, A1(1) = 0, A1(2) = -1, A1(n) = 2*A1(n-1) - 3*A1(n-2) - A1(n-3)\n");
    printf("2. Tinh A2(n) voi cong thuc A2(1) = 1, A2(2) = 2, A2(3) = 3, A2(n) = 2*A2(n-1) + A2(n-2) - 3*A2(n-3)\n");
    printf("Nhap lua chon (1 hoac 2): ");
    scanf_s("%d", &choice);

    printf("Nhap n: ");
    scanf_s("%d", &n);

    if (choice == 1) {
        printf("Gia tri cua A1(%d) = %d\n", n, tinh_A1(n));
    }
    else if (choice == 2) {
        printf("Gia tri cua A2(%d) = %d\n", n, tinh_A2(n));
    }
    else {
        printf("Lua chon khong hop le!\n");
    }

    return 0;
}
