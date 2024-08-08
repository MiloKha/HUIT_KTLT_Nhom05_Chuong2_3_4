#include <math.h>
#include <stdio.h>

// Bài 2: Tính m^n v?i m và n là s? nguyên
int tinhLuyThua(int m, int n) {
    int ketQua = 1;
    for (int i = 0; i < n; i++) {
        ketQua *= m;
    }
    return ketQua;
}

// Bài 3: T?m ý?c chung l?n nh?t c?a hai s? a và b
int timUocChungLonNhat(int a, int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

// Bài 4: T?m giá tr? ph?n t? th? n c?a c?p s? c?ng
int tinhCapSoCong(int a, int r, int n) {
    if (n == 1) return a;
    return tinhCapSoCong(a, r, n - 1) + r;
}

// Bài 5: T?m giá tr? ph?n t? th? n c?a c?p s? nhân
int tinhCapSoNhan(int a, int q, int n) {
    if (n == 1) return a;
    return tinhCapSoNhan(a, q, n - 1) * q;
}

// Bài 6: Tính bi?u th?c U(n)
int tinhUn(int n) {
    if (n < 6) {
        return n;
    }
    else {
        return tinhUn(n - 5) + tinhUn(n - 4) + tinhUn(n - 3) + tinhUn(n - 2) + tinhUn(n - 1);
    }
}

// Bài 7: Tính s? h?ng th? n c?a d?y An
int tinhAn1(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return -1;
    return 2 * tinhAn1(n - 1) - 3 * tinhAn1(n - 2) - tinhAn1(n - 3);
}

int tinhAn2(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    return 2 * tinhAn2(n - 2) + tinhAn2(n - 1) - 3 * tinhAn2(n);
}

// Bài 8: Tính giá tr? hàm f(n)
int tinhFn(int n) {
    if (n == 1) return 1;
    if (n % 2 == 0) return 2 * tinhFn(n / 2);
    return 2 * tinhFn(n / 2) + 3 * tinhFn(n / 2 + 1);
}

// Bài 10: T?m ki?m nh? phân b?ng ð? quy
int timKiemNhiPhan(int a[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return timKiemNhiPhan(a, left, mid - 1, x);
        return timKiemNhiPhan(a, mid + 1, right, x);
    }
    return -1;
}

// Bài 11: Tính d?y Fibonacci
int tinhFibonacci(int n) {
    if (n <= 2) return 1;
    return tinhFibonacci(n - 1) + tinhFibonacci(n - 2);
}

int main() {
    int luaChon, m, n, a, b, r, q, x, kq;
    int array[100], size;

    while (1) {
        printf("\nChon bai toan:\n");
        printf("1. Tinh m^n\n");
        printf("2. Tim uoc chung lon nhat cua hai so\n");
        printf("3. Tinh phan tu thu n cua cap so cong\n");
        printf("4. Tinh phan tu thu n cua cap so nhan\n");
        printf("5. Tinh bieu thuc U(n)\n");
        printf("6. Tinh so hang thu n cua day An - cong thuc 1\n");
        printf("7. Tinh so hang thu n cua day An - cong thuc 2\n");
        printf("8. Tinh ham f(n)\n");
        printf("9. Tim kiem nhi phan\n");
        printf("10. Tinh so Fibonacci\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        if (luaChon == 0) {
            break;
        }

        switch (luaChon) {
        case 1:
            printf("Nhap m: ");
            scanf("%d", &m);
            printf("Nhap n: ");
            scanf("%d", &n);
            printf("Ket qua: %d\n", tinhLuyThua(m, n));
            break;

        case 2:
            printf("Nhap so a: ");
            scanf("%d", &a);
            printf("Nhap so b: ");
            scanf("%d", &b);
            printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, timUocChungLonNhat(a, b));
            break;

        case 3:
            printf("Nhap gia tri dau tien a: ");
            scanf("%d", &a);
            printf("Nhap cong sai r: ");
            scanf("%d", &r);
            printf("Nhap phan tu thu n: ");
            scanf("%d", &n);
            printf("Gia tri phan tu thu %d cua cap so cong la: %d\n", n, tinhCapSoCong(a, r, n));
            break;

        case 4:
            printf("Nhap gia tri dau tien a: ");
            scanf("%d", &a);
            printf("Nhap cong boi q: ");
            scanf("%d", &q);
            printf("Nhap phan tu thu n: ");
            scanf("%d", &n);
            printf("Gia tri phan tu thu %d cua cap so nhan la: %d\n", n, tinhCapSoNhan(a, q, n));
            break;

        case 5:
            printf("Nhap n: ");
            scanf("%d", &n);
            printf("Gia tri U(%d) la: %d\n", n, tinhUn(n));
            break;

        case 6:
            printf("Nhap n: ");
            scanf("%d", &n);
            printf("So hang thu %d cua day An (cong thuc 1) la: %d\n", n, tinhAn1(n));
            break;

        case 7:
            printf("Nhap n: ");
            scanf("%d", &n);
            printf("So hang thu %d cua day An (cong thuc 2) la: %d\n", n, tinhAn2(n));
            break;

        case 8:
            printf("Nhap n: ");
            scanf("%d", &n);
            printf("Gia tri f(%d) la: %d\n", n, tinhFn(n));
            break;

        case 9:
            printf("Nhap so phan tu trong mang: ");
            scanf("%d", &size);
            printf("Nhap cac phan tu cua mang (da sap xep): ");
            for (int i = 0; i < size; i++) {
                scanf("%d", &array[i]);
            }
            printf("Nhap so can tim: ");
            scanf("%d", &x);
            kq = timKiemNhiPhan(array, 0, size - 1, x);
            if (kq != -1)
                printf("Tim thay %d tai vi tri %d\n", x, kq);
            else
                printf("Khong tim thay %d trong mang\n", x);
            break;

        case 10:
            printf("Nhap n: ");
            scanf("%d", &n);
            printf("So Fibonacci thu %d la: %d\n", n, tinhFibonacci(n));
            break;

        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    }

    return 0;
}

