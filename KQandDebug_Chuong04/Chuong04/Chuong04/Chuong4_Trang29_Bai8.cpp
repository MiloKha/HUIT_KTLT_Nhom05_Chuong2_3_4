#include <stdio.h>

// Hàm đệ quy tính giá trị của f(n)
int f(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n % 2 == 0) {
        return 2 * f(n / 2);
    }
    else {
        return 2 * f(n / 2) + 3 * f(n / 2 + 1);
    }
}

int main() {
    int n, choice;
    do {
        printf("Menu:\n");
        printf("1. Tinh f(5)\n");
        printf("2. Nhap n va tinh f(n)\n");
        printf("3. Thoat\n");
        printf("Chon lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("f(5) = %d\n", f(5));
            break;
        case 2:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("f(%d) = %d\n", n, f(n));
            break;
        case 3:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice != 3);

    return 0;
}
