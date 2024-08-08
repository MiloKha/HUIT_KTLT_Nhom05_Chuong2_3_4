#include <stdio.h>
#include <stdlib.h>

// Khai báo cấu trúc phân số
typedef struct {
    int tu_so;
    int mau_so;
} PhanSo;

// Hàm nhập phân số
void nhap_phan_so(PhanSo* ps) {
    printf("Nhap tu so: ");
    scanf_s("%d", &ps->tu_so);
    printf("Nhap mau so: ");
    scanf_s("%d", &ps->mau_so);
    while (ps->mau_so == 0) {
        printf("Mau so phai khac 0. Vui long nhap lai mau so: ");
        scanf_s("%d", &ps->mau_so);
    }
}

// Hàm xuất phân số
void xuat_phan_so(PhanSo ps) {
    if (ps.mau_so == 1) {
        printf("%d\n", ps.tu_so);
    }
    else {
        printf("%d/%d\n", ps.tu_so, ps.mau_so);
    }
}


void menu() {
    PhanSo ps1, ps2, ket_qua;
    int lua_chon;

    do {
        printf("\nMenu\n");
        printf("1. Nhap phan so 1\n");
        printf("2. Nhap phan so 2\n");
        printf("3. Xuat phan so 1\n");
        printf("4. Xuat phan so 2\n");
        printf("5. Tinh tong hai phan so\n");
        printf("6. Tinh hieu hai phan so\n");
        printf("7. Tinh tich hai phan so\n");
        printf("8. Tinh thuong hai phan so\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf_s("%d", &lua_chon);

        switch (lua_chon) {
        case 1:
            nhap_phan_so(&ps1);
            break;
        case 2:
            nhap_phan_so(&ps2);
            break;
        case 3:
            printf("Phan so 1: ");
            xuat_phan_so(ps1);
            break;
        case 4:
            printf("Phan so 2: ");
            xuat_phan_so(ps2);
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
