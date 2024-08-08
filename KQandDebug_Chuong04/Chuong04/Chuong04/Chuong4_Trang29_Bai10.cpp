#include <stdio.h>

// Hàm đệ quy tìm kiếm nhị phân
int timKiemNhiPhan(int a[], int x, int left, int right) {
    if (left > right) {
        return -1; // Không tìm thấy
    }
    int mid = (left + right) / 2;
    if (a[mid] == x) {
        return mid; // Tìm thấy tại vị trí mid
    }
    else if (a[mid] > x) {
        return timKiemNhiPhan(a, x, left, mid - 1); // Tìm trong nửa bên trái
    }
    else {
        return timKiemNhiPhan(a, x, mid + 1, right); // Tìm trong nửa bên phải
    }
}

int main() {
    int n, x, ketQua;
    int a[50]; // Giả sử mảng chứa tối đa 50 phần tử

    printf("Nhap so phan tu cua mang: ");
    scanf_s("%d", &n);

    printf("Nhap cac phan tu cua mang da sap xep: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }

    printf("Nhap gia tri can tim: ");
    scanf_s("%d", &x);

    ketQua = timKiemNhiPhan(a, x, 0, n - 1);

    if (ketQua != -1) {
        printf("Tim thay x tai vi tri %d\n", ketQua);
    }
    else {
        printf("Khong tim thay x trong mang\n");
    }

    return 0;
}
