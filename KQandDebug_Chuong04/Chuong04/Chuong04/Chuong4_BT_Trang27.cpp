#include <stdio.h>
#include <math.h>

// Hàm tính giai th?a
double tinhGiaThua(int n) {
    double giaThua = 1;
    for (int i = 1; i <= n; i++) {
        giaThua *= i;
    }
    return giaThua;
}

// Bài 1: Tong tu 1 den n
int tinhTongTu1DenN(int n) {
    int tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += i;
    }
    return tong;
}

// Bài 2: Can bac n cua 2 cong can bac n cua 2...
double tinhCanBacN(int n) {
    double ketQua = 0;
    for (int i = 0; i < n; i++) {
        ketQua = sqrt(2 + ketQua);
    }
    return ketQua;
}

// Bài 3: Tong cac phan so tu 1/2 den n/(n+1)
double tinhTongPhanSo(int n) {
    double tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += (double)i / (i + 1);
    }
    return tong;
}

// Bài 4: Tong cac phan so le tu 1 den 1/(2n+1)
double tinhTongPhanSoLe(int n) {
    double tong = 1;
    for (int i = 1; i <= n; i++) {
        tong += 1.0 / (2 * i + 1);
    }
    return tong;
}

// Bài 5: Tong cac tich tu 1*2 den n*(n+1)
int tinhTongTich(int n) {
    int tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += i * (i + 1);
    }
    return tong;
}

// Bài 6: Tong cac phan so theo tich tu 1/(1*2*3) den 1/(n*(n+1)*(n+2))
double tinhTongPhanSoTich(int n) {
    double tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += 1.0 / (i * (i + 1) * (i + 2));
    }
    return tong;
}

// Bài 7: Tong cac binh phuong tu 1^2 den n^2
int tinhTongBinhPhuong(int n) {
    int tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += i * i;
    }
    return tong;
}

// Bài 8: Tong cac day tu 1 den n
int tinhTongDay(int n) {
    int tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += i * (i + 1) / 2;
    }
    return tong;
}

// Bài 9: Tong day theo cong thuc (1+2)/2! + (3+4)/4! + ...
double tinhTongDayDacBiet(int n) {
    double tong = 0;
    for (int i = 1; i <= n; i++) {
        int tuSo = (2 * i - 1) + (2 * i);
        double mauSo = tinhGiaThua(2 * i);
        tong += pow(-1, i) * tuSo / mauSo;
    }
    return tong;
}

// Bài 10: Tong day theo cong thuc 1.2!/(2+sqrt(3)) + ...
double tinhTongDayTinhTien(int n) {
    double tong = 0;
    for (int i = 1; i <= n; i++) {
        double tuSo = i * tinhGiaThua(i + 1);
        double mauSo = (i + 1) + sqrt(i + 2);
        tong += tuSo / mauSo;
    }
    return tong;
}

// Bài 11: Tong day theo cong thuc (1+sqrt(1+2))/(2+sqrt(3!)) + ...
double tinhTongDayCanBac(int n) {
    double tong = 0;
    for (int i = 1; i <= n; i++) {
        double tuSo = i + sqrt(i + i + 1);
        double mauSo = (i + 1) + sqrt(tinhGiaThua(i + 2));
        tong += tuSo / mauSo;
    }
    return tong;
}

int main() {
    int luaChon, n;

    while (1) {
        printf("\nChon bai toan de tinh S(n):\n");
        printf("1. Tong tu 1 den n\n");
        printf("2. Can bac n cua 2 cong can bac n cua 2...\n");
        printf("3. Tong cac phan so tu 1/2 den n/(n+1)\n");
        printf("4. Tong cac phan so le tu 1 den 1/(2n+1)\n");
        printf("5. Tong cac tich tu 1*2 den n*(n+1)\n");
        printf("6. Tong cac phan so theo tich tu 1/(1*2*3) den 1/(n*(n+1)*(n+2))\n");
        printf("7. Tong cac binh phuong tu 1^2 den n^2\n");
        printf("8. Tong cac day tu 1 den n\n");
        printf("9. Tong day theo cong thuc dac biet\n");
        printf("10. Tong day theo cong thuc tinh tien\n");
        printf("11. Tong day theo cong thuc can bac\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        if (luaChon == 0) {
            break;
        }

        printf("Nhap gia tri n: ");
        scanf("%d", &n);

        switch (luaChon) {
        case 1:
            printf("Ket qua: %d\n", tinhTongTu1DenN(n));
            break;
        case 2:
            printf("Ket qua: %.6f\n", tinhCanBacN(n));
            break;
        case 3:
            printf("Ket qua: %.6f\n", tinhTongPhanSo(n));
            break;
        case 4:
            printf("Ket qua: %.6f\n", tinhTongPhanSoLe(n));
            break;
        case 5:
            printf("Ket qua: %d\n", tinhTongTich(n));
            break;
        case 6:
            printf("Ket qua: %.6f\n", tinhTongPhanSoTich(n));
            break;
        case 7:
            printf("Ket qua: %d\n", tinhTongBinhPhuong(n));
            break;
        case 8:
            printf("Ket qua: %d\n", tinhTongDay(n));
            break;
        case 9:
            printf("Ket qua: %.6f\n", tinhTongDayDacBiet(n));
            break;
        case 10:
            printf("Ket qua: %.6f\n", tinhTongDayTinhTien(n));
            break;
        case 11:
            printf("Ket qua: %.6f\n", tinhTongDayCanBac(n));
            break;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    }

    return 0;
}

