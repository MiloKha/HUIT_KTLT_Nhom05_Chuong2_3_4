#include <stdio.h>

// Hàm tính giá trị Xn theo cách đệ quy
int tinhXnDeQuy(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 1;
    }
    else {
        return tinhXnDeQuy(n - 1) + (n - 1) * tinhXnDeQuy(n - 2);
    }
}

// Hàm tính giá trị Xn theo cách khử đệ quy
int tinhXnKhongDeQuy(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    int x1 = 1, x2 = 1;
    int xn;

    for (int i = 3; i <= n; i++) {
        xn = x2 + (i - 1) * x1;
        x1 = x2;
        x2 = xn;
    }

    return xn;
}

int main() {
    int n;

    printf("Nhap so nguyen n (n >= 1): ");
    scanf_s("%d", &n);

    if (n < 1) {
        printf("Gia tri n phai lon hon hoac bang 1.\n");
        return 1;
    }

    printf("Gia tri Xn tai vi tri thu %d (de quy) la: %d\n", n, tinhXnDeQuy(n));
    printf("Gia tri Xn tai vi tri thu %d (khong de quy) la: %d\n", n, tinhXnKhongDeQuy(n));

    return 0;
}
