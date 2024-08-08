#include <stdio.h>

#define MAX_SIZE 50

typedef struct {
    int tu_so;
    int mau_so;
} PhanSo;

// Hàm nhập danh sách các phân số
void nhap_danh_sach(PhanSo arr[], int* n) {
    printf("Nhap so luong phan so (toi da %d): ", MAX_SIZE);
    scanf_s("%d", n);
    if (*n > MAX_SIZE) {
        printf("So luong phan so vuot qua gioi han, gan max = %d\n", MAX_SIZE);
        *n = MAX_SIZE;
    }

    for (int i = 0; i < *n; ++i) {
        printf("Nhap tu so cho phan so %d: ", i + 1);
        scanf_s("%d", &arr[i].tu_so);
        printf("Nhap mau so cho phan so %d: ", i + 1);
        scanf_s("%d", &arr[i].mau_so);
        while (arr[i].mau_so == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai mau so: ");
            scanf_s("%d", &arr[i].mau_so);
        }
    }
}

// Hàm xuất danh sách các phân số
void xuat_danh_sach(PhanSo arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if (arr[i].mau_so == 1) {
            printf("Phan so %d: %d\n", i + 1, arr[i].tu_so);
        }
        else {
            printf("Phan so %d: %d/%d\n", i + 1, arr[i].tu_so, arr[i].mau_so);
        }
    }
}

// Hàm tìm phân số có giá trị lớn nhất
PhanSo tim_phan_so_lon_nhat(PhanSo arr[], int n) {
    PhanSo max = arr[0];
    for (int i = 1; i < n; ++i) {
        if ((arr[i].tu_so * max.mau_so) > (max.tu_so * arr[i].mau_so)) {
            max = arr[i];
        }
    }
    return max;
}

// Hàm tìm phân số có giá trị nhỏ nhất
PhanSo tim_phan_so_nho_nhat(PhanSo arr[], int n) {
    PhanSo min = arr[0];
    for (int i = 1; i < n; ++i) {
        if ((arr[i].tu_so * min.mau_so) < (min.tu_so * arr[i].mau_so)) {
            min = arr[i];
        }
    }
    return min;
}


void menu() {
    PhanSo arr[MAX_SIZE];
    int n, lua_chon;
    PhanSo ket_qua;

    do {
        printf("\nMenu\n");
        printf("1. Nhap danh sach phan so\n");
        printf("2. Xuat danh sach phan so\n");
        printf("3. Tim phan so lon nhat\n");
        printf("4. Tim phan so nho nhat\n");
        printf("5. Tinh tong cac phan so\n");
        printf("6. Tinh tich cac phan so\n");
        printf("7. Xuat nghich dao cac phan so\n");
        printf("8. Sap xep tang dan\n");
        printf("9. Sap xep giam dan\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf_s("%d", &lua_chon);

        switch (lua_chon) {
        case 1:
            nhap_danh_sach(arr, &n);
            break;
        case 2:
            xuat_danh_sach(arr, n);
            break;
        case 3:
            ket_qua = tim_phan_so_lon_nhat(arr, n);
            printf("Phan so lon nhat: ");
            xuat_danh_sach(&ket_qua, 1);
            break;
        case 4:
            ket_qua = tim_phan_so_nho_nhat(arr, n);
            printf("Phan so nho nhat: ");
            xuat_danh_sach(&ket_qua, 1);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (lua_chon != 0);
}

int main() {
    menu();
    return 0;
}
