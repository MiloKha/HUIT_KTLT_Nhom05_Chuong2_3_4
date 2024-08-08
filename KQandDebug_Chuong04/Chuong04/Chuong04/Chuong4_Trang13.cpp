#include <stdio.h>

// Hàm tính tổng S(n) = 1 + 2 + 3 + ... + n
int tinh_tong_1_den_n(int n) {
    return n * (n + 1) / 2;
}

// Hàm tính tổng S(n) = 1 + 1/2 + 1/3 + ... + 1/n
double tinh_tong_1_den_n_phan_so(int n) {
    double tong = 0;
    for (int i = 1; i <= n; ++i) {
        tong += 1.0 / i;
    }
    return tong;
}

// Hàm tính tổng S(n) = 1*2 + 2*3 + 3*4 + ... + n*(n+1)
int tinh_tong_nhan(int n) {
    int tong = 0;
    for (int i = 1; i <= n; ++i) {
        tong += i * (i + 1);
    }
    return tong;
}

// Hàm tính phần tử thứ n của cấp số cộng
int cap_so_cong(int a, int r, int n) {
    return a + (n - 1) * r;
}

// Hàm tính phần tử thứ n của cấp số nhân
double cap_so_nhan(double a, double q, int n) {
    if (n == 1) return a;
    double u = a;
    for (int i = 1; i < n; ++i) {
        u *= q;
    }
    return u;
}

// Hàm chính của chương trình
int main() {
    int lua_chon;
    int n, a, r;
    double q;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Tinh S(n) = 1 + 2 + 3 + ... + n\n");
        printf("2. Tinh S(n) = 1 + 1/2 + 1/3 + ... + 1/n\n");
        printf("3. Tinh S(n) = 1*2 + 2*3 + 3*4 + ... + n*(n+1)\n");
        printf("4. Tinh phan tu thu n cua cap so cong\n");
        printf("5. Tinh phan tu thu n cua cap so nhan\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &lua_chon);

        switch (lua_chon) {
        case 1:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("S(%d) = %d\n", n, tinh_tong_1_den_n(n));
            break;
        case 2:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("S(%d) = %.2f\n", n, tinh_tong_1_den_n_phan_so(n));
            break;
        case 3:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("S(%d) = %d\n", n, tinh_tong_nhan(n));
            break;
        case 4:
            printf("Nhap so hang dau a: ");
            scanf_s("%d", &a);
            printf("Nhap cong sai r: ");
            scanf_s("%d", &r);
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("Phan tu thu %d cua cap so cong = %d\n", n, cap_so_cong(a, r, n));
            break;
        case 5:
            printf("Nhap so hang dau a: ");
            scanf_s("%lf", &a);
            printf("Nhap cong boi q: ");
            scanf_s("%lf", &q);
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("Phan tu thu %d cua cap so nhan = %.2f\n", n, cap_so_nhan(a, q, n));
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (lua_chon != 0);

    return 0;
}
