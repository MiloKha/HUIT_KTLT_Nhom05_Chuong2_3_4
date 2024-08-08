#include <stdio.h>
#include <stdlib.h> // Thư viện cần thiết cho malloc và free
#include <stdbool.h>
#include <math.h>

// Hàm kiểm tra số nguyên tố
bool la_so_nguyen_to(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra mảng có chứa toàn bộ số nguyên tố
bool mang_toan_so_nguyen_to(int* a, int n) {
    for (int i = 0; i < n; i++) {
        if (!la_so_nguyen_to(a[i])) return false;
    }
    return true;
}

// Hàm kiểm tra mảng có đối xứng không
bool mang_doi_xung(int* a, int n) {
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - 1 - i]) return false;
    }
    return true;
}

// Hàm kiểm tra mảng có tăng dần không
bool mang_tang_dan(int* a, int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) return false;
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

    // Nhap mang
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
        printf("1. Kiem tra mang co chua toan bo so nguyen to hay khong\n");
        printf("2. Kiem tra mang co doi xung hay khong\n");
        printf("3. Kiem tra mang co tang dan/giam dan/khong tang khong giam\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        if (scanf_s("%d", &lua_chon) != 1) {
            printf("Lua chon khong hop le! Vui long nhap lai.\n");
            while (getchar() != '\n'); // Xoa bo dem
            continue;
        }

        switch (lua_chon) {
        case 1: {
            if (mang_toan_so_nguyen_to(a, n)) {
                printf("Mang chua toan bo so nguyen to.\n");
            }
            else {
                printf("Mang khong chua toan bo so nguyen to.\n");
            }
            break;
        }
        case 2: {
            if (mang_doi_xung(a, n)) {
                printf("Mang doi xung.\n");
            }
            else {
                printf("Mang khong doi xung.\n");
            }
            break;
        }
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (lua_chon != 0);

    free(a); // Giải phóng bộ nhớ sau khi sử dụng
    return 0;
}
