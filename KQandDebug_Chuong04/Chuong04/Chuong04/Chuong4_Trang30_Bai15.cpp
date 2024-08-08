#include <stdio.h>

// Hàm tính giá trị Yn theo cách đệ quy
int tinhYnDeQuy(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else if (n == 3) {
        return 3;
    }
    else {
        return tinhYnDeQuy(n - 1) + 2 * tinhYnDeQuy(n - 2) + 3 * tinhYnDeQuy(n - 3);
    }
}

// Hàm tính giá trị Yn theo cách khử đệ quy
int tinhYnKhongDeQuy(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else if (n == 3) {
        return 3;
    }

    int y1 = 1, y2 = 2, y3 = 3;
    int yn;

    for (int i = 4; i <= n; i++) {
        yn = y1 + 2 * y2 + 3 * y3;
        y1 = y2;
        y2 = y3;
        y3 = yn;
    }

    return yn;
}

int main() {
    int n;

    printf("Nhap so nguyen n (n >= 1): ");
    scanf_s("%d", &n);

    if (n < 1) {
        printf("Gia tri n phai lon hon hoac bang 1.\n");
        return 1;
    }

    printf("Gia tri Yn tai vi tri thu %d (duy tri de quy) la: %d\n", n, tinhYnDeQuy(n));
    printf("Gia tri Yn tai vi tri thu %d (khong de quy) la: %d\n", n, tinhYnKhongDeQuy(n));

    return 0;
}
