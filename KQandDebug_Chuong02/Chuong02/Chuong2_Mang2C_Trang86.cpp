#include <stdio.h>
#include <stdbool.h>

#define MAX_M 50
#define MAX_N 50

// Ham hoan doi hai gia tri
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Ham sap xep mang theo thu tu tang dan
void sapXepTang(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// Ham sap xep mang theo thu tu giam dan
void sapXepGiam(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// Bai 1: Sap xep cac phan tu trong ma tran sao cho dong chan tang, dong le giam
void sapXepDongChanLe(int mat[MAX_M][MAX_N], int n, int m) {
    for (int i = 0; i < n; i++) {
        int row[m];
        for (int j = 0; j < m; j++) {
            row[j] = mat[i][j];
        }
        if (i % 2 == 0) {
            sapXepTang(row, m);
        }
        else {
            sapXepGiam(row, m);
        }
        for (int j = 0; j < m; j++) {
            mat[i][j] = row[j];
        }
    }
}

// Bai 2: Sap xep cac phan tu trong ma tran sao cho cot chan tang, cot le giam
void sapXepCotChanLe(int mat[MAX_M][MAX_N], int n, int m) {
    for (int j = 0; j < m; j++) {
        int col[n];
        for (int i = 0; i < n; i++) {
            col[i] = mat[i][j];
        }
        if (j % 2 == 0) {
            sapXepTang(col, n);
        }
        else {
            sapXepGiam(col, n);
        }
        for (int i = 0; i < n; i++) {
            mat[i][j] = col[i];
        }
    }
}

// Bai 3: Sap xep ma tran tang dan/giam dan theo zic-zac
void sapXepZicZac(int mat[MAX_M][MAX_N], int n, int m, bool tangDan) {
    int arr[n * m];
    int index = 0;

    // Chuyen ma tran thanh mang
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[index++] = mat[i][j];
        }
    }

    // Sap xep mang
    if (tangDan) {
        sapXepTang(arr, n * m);
    }
    else {
        sapXepGiam(arr, n * m);
    }

    // Chuyen mang tro lai ma tran theo kieu zic-zac
    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = arr[index++];
            }
        }
        else {
            for (int j = m - 1; j >= 0; j--) {
                mat[i][j] = arr[index++];
            }
        }
    }
}

// Ham nhap ma tran
void nhapMaTran(int mat[MAX_M][MAX_N], int* n, int* m) {
    printf("Nhap so hang (n): ");
    scanf("%d", n);
    printf("Nhap so cot (m): ");
    scanf("%d", m);
    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            printf("Nhap mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Ham xuat ma tran
void xuatMaTran(int mat[MAX_M][MAX_N], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Ham menu
void menu(int mat[MAX_M][MAX_N], int n, int m) {
    int luaChon, k;
    bool tangDan;

    while (1) {
        printf("\nChon bai: \n");
        printf("1. Sap xep cac phan tu trong ma tran sao cho dong chan tang, dong le giam\n");
        printf("2. Sap xep cac phan tu trong ma tran sao cho cot chan tang, cot le giam\n");
        printf("3. Sap xep ma tran tang dan/ giam dan theo zic-zac\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            sapXepDongChanLe(mat, n, m);
            xuatMaTran(mat, n, m);
            break;
        case 2:
            sapXepCotChanLe(mat, n, m);
            xuatMaTran(mat, n, m);
            break;
        case 3:
            printf("Chon cach sap xep: 1 - Tang dan, 0 - Giam dan: ");
            scanf("%d", &tangDan);
            sapXepZicZac(mat, n, m, tangDan);
            xuatMaTran(mat, n, m);
            break;
        case 0:
            return;
        default:
            printf("Lua chon khong hop le.\n");
            break;
        }
    }
}

int main() {
    int mat[MAX_M][MAX_N];
    int n, m;

    nhapMaTran(mat, &n, &m);
    xuatMaTran(mat, n, m);

    menu(mat, n, m);

    return 0;
}

