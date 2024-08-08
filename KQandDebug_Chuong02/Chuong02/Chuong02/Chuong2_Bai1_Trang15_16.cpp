#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Hàm nhập mảng
void nhap_mang(int a[], int n) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf_s("%d", &a[i]);
    }
}

// Hàm xuất mảng
void xuat_mang(int a[], int n) {
    printf("Cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm tìm max của mảng
int tim_max(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

// Hàm tìm min của mảng
int tim_min(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

// Hàm đếm số phần tử chẵn
int dem_chan(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

// Hàm đếm số phần tử lẻ
int dem_le(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

// Hàm tìm kiếm tuyến tính
int tim_kiem_tuyen_tinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

// Hàm tìm kiếm nhị phân (cần mảng đã sắp xếp)
int tim_kiem_nhi_phan(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// Hàm đếm số phần tử x trong mảng
int dem_phan_tu_x(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

// Hàm đếm số phần tử lớn hơn x trong mảng
int dem_lon_hon_x(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            count++;
        }
    }
    return count;
}

// Hàm tính tổng các phần tử của mảng
int tong_mang(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

// Hàm kiểm tra số nguyên tố
bool la_nguyen_to(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm xuất các số nguyên tố trong mảng
void xuat_nguyen_to(int a[], int n) {
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < n; i++) {
        if (la_nguyen_to(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// Hàm kiểm tra số hoàn thiện
bool la_hoan_thien(int n) {
    if (n < 1) return false;
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) sum += i;
    }
    return sum == n;
}

// Hàm xuất các số hoàn thiện trong mảng
void xuat_hoan_thien(int a[], int n) {
    printf("Cac so hoan thien trong mang: ");
    for (int i = 0; i < n; i++) {
        if (la_hoan_thien(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}





int main() {
    int lua_chon, n, x, vi_tri;
    printf("Nhap so phan tu cua mang: ");
    scanf_s("%d", &n);

    int* a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return -1;
    }

    nhap_mang(a, n);

    do {
        printf("\nMenu\n");
        printf("1. Xuat mang\n");
        printf("2. Tim max/min cua a\n");
        printf("3. Dem so phan tu chan/le trong a\n");
        printf("4. Tim kiem phan tu x trong a (tim kiem tuyen tinh/nhi phan)\n");
        printf("5. Dem tren a co bao nhieu phan tu x\n");
        printf("6. Dem tren a co bao nhieu phan tu lon hon x\n");
        printf("7. Tinh tong cac phan tu cua a\n");
        printf("8. Xuat cac so nguyen to trong a\n");
        printf("9. Xuat cac so hoan thien trong a\n");
        printf("10. Xuat cac phan tu o vi tri chan/le trong a\n");
        printf("11. Xuat gia tri max/min kem theo vi tri\n");
        printf("12. Ghep hai day tang dan thanh mot day tang dan\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf_s("%d", &lua_chon);

        switch (lua_chon) {
        case 1:
            xuat_mang(a, n);
            break;
        case 2:
            printf("Gia tri lon nhat cua mang: %d\n", tim_max(a, n));
            printf("Gia tri nho nhat cua mang: %d\n", tim_min(a, n));
            break;
        case 3:
            printf("So phan tu chan trong mang: %d\n", dem_chan(a, n));
            printf("So phan tu le trong mang: %d\n", dem_le(a, n));
            break;
        case 4:
            printf("Nhap gia tri can tim: ");
            scanf_s("%d", &x);
            vi_tri = tim_kiem_tuyen_tinh(a, n, x);
            if (vi_tri != -1) {
                printf("Tim kiem tuyen tinh: Gia tri %d o vi tri %d\n", x, vi_tri);
            }
            else {
                printf("Tim kiem tuyen tinh: Khong tim thay gia tri %d trong mang\n", x);
            }
            // Sắp xếp mảng trước khi tìm kiếm nhị phân
            // Lưu ý: cần thêm hàm sắp xếp tại đây
            // vi_tri = tim_kiem_nhi_phan(a, n, x);
            if (vi_tri != -1) {
                printf("Tim kiem nhi phan: Gia tri %d o vi tri %d\n", x, vi_tri);
            }
            else {
                printf("Tim kiem nhi phan: Khong tim thay gia tri %d trong mang\n", x);
            }
            break;
        case 5:
            printf("Nhap gia tri can dem: ");
            scanf_s("%d", &x);
            printf("So phan tu %d trong mang: %d\n", x, dem_phan_tu_x(a, n, x));
            break;
        case 6:
            printf("Nhap gia tri x: ");
            scanf_s("%d", &x);
            printf("So phan tu lon hon %d trong mang: %d\n", x, dem_lon_hon_x(a, n, x));
            break;
        case 7:
            printf("Tong cac phan tu trong mang: %d\n", tong_mang(a, n));
            break;
        case 8:
            xuat_nguyen_to(a, n);
            break;
        case 9:
            xuat_hoan_thien(a, n);
            break;
        case 0:
            printf("Thoat chuong trinh\n");
            break;
        default:
            printf("Lua chon khong hop le\n");
        }
    } while (lua_chon != 0);

    free(a);
    return 0;
}
