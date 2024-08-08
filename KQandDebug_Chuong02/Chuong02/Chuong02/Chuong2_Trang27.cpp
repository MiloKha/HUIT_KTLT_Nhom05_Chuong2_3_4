#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void hoan_doi_int(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void hoan_doi_float(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void hoan_doi_char(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void hoan_doi_str(char* a, char* b) {
    char temp[100];
    strncpy_s(temp, sizeof(temp), a, _TRUNCATE);
    strncpy_s(a, sizeof(temp), b, _TRUNCATE);
    strncpy_s(b, sizeof(temp), temp, _TRUNCATE);
}

void sap_xep_tang_int(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                hoan_doi_int(&a[i], &a[j]);
            }
        }
    }
}

void sap_xep_giam_int(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                hoan_doi_int(&a[i], &a[j]);
            }
        }
    }
}

void sap_xep_tang_float(float* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                hoan_doi_float(&a[i], &a[j]);
            }
        }
    }
}

void sap_xep_giam_float(float* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                hoan_doi_float(&a[i], &a[j]);
            }
        }
    }
}

void sap_xep_tang_char(char* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                hoan_doi_char(&a[i], &a[j]);
            }
        }
    }
}

void sap_xep_giam_char(char* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                hoan_doi_char(&a[i], &a[j]);
            }
        }
    }
}

void sap_xep_tang_str(char** a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(a[i], a[j]) > 0) {
                hoan_doi_str(a[i], a[j]);
            }
        }
    }
}

void sap_xep_giam_str(char** a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(a[i], a[j]) < 0) {
                hoan_doi_str(a[i], a[j]);
            }
        }
    }
}

// Input functions
void nhap_mang_int(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        if (scanf_s("%d", &a[i]) != 1) {
            printf("Nhap sai! Vui long nhap lai.\n");
            while (getchar() != '\n'); 
        }
    }
}

void nhap_mang_float(float* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        if (scanf_s("%f", &a[i]) != 1) {
            printf("Nhap sai! Vui long nhap lai.\n");
            while (getchar() != '\n'); 
        }
    }
}

void nhap_mang_char(char* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        if (scanf_s(" %c", &a[i], 1) != 1) {
            printf("Nhap sai! Vui long nhap lai.\n");
            while (getchar() != '\n'); 
        }
    }
}

void nhap_mang_str(char** a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        if (scanf_s("%99s", a[i], 100) != 1) { 
            printf("Nhap sai! Vui long nhap lai.\n");
            while (getchar() != '\n'); 
        }
    }
}

void xuat_mang_int(const int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void xuat_mang_float(const float* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", a[i]);
    }
    printf("\n");
}

void xuat_mang_char(const char* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c ", a[i]);
    }
    printf("\n");
}

void xuat_mang_str(char** a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i]) { 
            printf("%s ", a[i]);
        }
        else {
            printf("NULL ");
        }
    }
    printf("\n");
}

int main() {
    int lua_chon, n;
    printf("Nhap so phan tu cua mang: ");
    if (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("Nhap sai! Vui long nhap lai.\n");
        return 1;
    }

    int* int_array = (int*)malloc(n * sizeof(int));
    float* float_array = (float*)malloc(n * sizeof(float));
    char* char_array = (char*)malloc(n * sizeof(char));
    char** str_array = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        str_array[i] = (char*)malloc(100 * sizeof(char));
    }

    if (!int_array || !float_array || !char_array || !str_array) {
        printf("Khong du bo nho!\n");
        return 1;
    }

    do {
        printf("\nMenu\n");
        printf("1. Nhap xuat va sap xep so nguyen\n");
        printf("2. Nhap xuat va sap xep so thuc\n");
        printf("3. Nhap xuat va sap xep ky tu\n");
        printf("4. Nhap xuat va sap xep chuoi ky tu\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        if (scanf_s("%d", &lua_chon) != 1) {
            printf("Lua chon khong hop le! Vui long nhap lai.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (lua_chon) {
        case 1: {
            printf("Nhap mang so nguyen:\n");
            nhap_mang_int(int_array, n);
            printf("Mang vua nhap: ");
            xuat_mang_int(int_array, n);
            sap_xep_tang_int(int_array, n);
            printf("Mang sap xep tang dan: ");
            xuat_mang_int(int_array, n);
            sap_xep_giam_int(int_array, n);
            printf("Mang sap xep giam dan: ");
            xuat_mang_int(int_array, n);
            break;
        }
        case 2: {
            printf("Nhap mang so thuc:\n");
            nhap_mang_float(float_array, n);
            printf("Mang vua nhap: ");
            xuat_mang_float(float_array, n);
            sap_xep_tang_float(float_array, n);
            printf("Mang sap xep tang dan: ");
            xuat_mang_float(float_array, n);
            sap_xep_giam_float(float_array, n);
            printf("Mang sap xep giam dan: ");
            xuat_mang_float(float_array, n);
            break;
        }
        case 3: {
            printf("Nhap mang ky tu:\n");
            nhap_mang_char(char_array, n);
            printf("Mang vua nhap: ");
            xuat_mang_char(char_array, n);
            sap_xep_tang_char(char_array, n);
            printf("Mang sap xep tang dan: ");
            xuat_mang_char(char_array, n);
            sap_xep_giam_char(char_array, n);
            printf("Mang sap xep giam dan: ");
            xuat_mang_char(char_array, n);
            break;
        }
        case 4: {
            printf("Nhap mang chuoi ky tu:\n");
            nhap_mang_str(str_array, n);
            printf("Mang vua nhap: ");
            xuat_mang_str(str_array, n);
            sap_xep_tang_str(str_array, n);
            printf("Mang sap xep tang dan: ");
            xuat_mang_str(str_array, n);
            sap_xep_giam_str(str_array, n);
            printf("Mang sap xep giam dan: ");
            xuat_mang_str(str_array, n);
            break;
        }
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (lua_chon != 0);

    free(int_array);
    free(float_array);
    free(char_array);
    for (int i = 0; i < n; i++) {
        free(str_array[i]);
    }
    free(str_array);

    return 0;
}
