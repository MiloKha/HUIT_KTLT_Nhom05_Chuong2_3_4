#include <stdio.h>
#include <stdlib.h> // Bao gồm thư viện cần thiết cho malloc và free
#include <stdbool.h>

// Hàm kiểm tra số nguyên tố
bool la_so_nguyen_to(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra các chữ số của số có phải là số lẻ không
bool tat_ca_chu_so_le(int x) {
    while (x > 0) {
        int digit = x % 10;
        if (digit % 2 == 0) return false; 
        x /= 10;
    }
    return true;
}

int main() {
    int lua_chon, n;

    printf("Nhap so phan tu cua mang: ");
    if (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("Nhap sai! Vui long nhap lai.\n");
        return 1;
    }

    int* a = (int*)malloc(n * sizeof(int)); 
    if (a == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }


    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        if (scanf_s("%d", &a[i]) != 1) {
            printf("Nhap sai! Vui long nhap lai.\n");
            while (getchar() != '\n'); 
            i--; 
        }
    }

    do {
        printf("\nMenu\n");
        printf("1. Dem so phan tu la so nguyen to\n");
        printf("2. Xuat cac phan tu co cac chu so la so le\n");
        printf("3. Tim vi tri cuoi cung cua so lon nhat trong mang\n");
        printf("4. Kiem tra mang co toan la so chan khong\n");
        printf("5. Kiem tra mang co phai la day so chan le xen ke khong\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        if (scanf_s("%d", &lua_chon) != 1) {
            printf("Lua chon khong hop le! Vui long nhap lai.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (lua_chon) {
        case 1: {
            int dem = 0;
            for (int i = 0; i < n; i++) {
                if (la_so_nguyen_to(a[i])) dem++;
            }
            printf("So phan tu la so nguyen to: %d\n", dem);
            break;
        }
        case 2: {
            printf("Cac phan tu co cac chu so la so le: ");
            for (int i = 0; i < n; i++) {
                if (tat_ca_chu_so_le(a[i])) {
                    printf("%d ", a[i]);
                }
            }
            printf("\n");
            break;
        }
        case 3: {
            int max = a[0];
            int vi_tri_cuoi = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] >= max) {
                    max = a[i];
                    vi_tri_cuoi = i;
                }
            }
            printf("Vi tri cuoi cung cua so lon nhat: %d\n", vi_tri_cuoi);
            break;
        }
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (lua_chon != 0);

    free(a); 
    return 0;
}
