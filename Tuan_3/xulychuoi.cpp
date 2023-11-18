#include <stdio.h>
#include <string.h>

void xulychuoi(char *chuoi, char *chuoiMoi) {
    int i, j, x;
    for (i = 0, j = 0; chuoi[i] != '\0'; i++) {
        if ((chuoi[i] != ' ') && (chuoi[i] >= 'a' && chuoi[i] <= 'z') || (chuoi[i] >= 'A' && chuoi[i] <= 'Z')) {
            chuoiMoi[j++] = chuoi[i];
            x = 0;
        }
        if ((chuoi[i] == ' ')) {
            if (x == 0) {
                chuoiMoi[j++] = chuoi[i];
                x = 1;
            }
        }
    }
}

void daoNguocChuoi(char *chuoiMoi, char *chuoiNguoc) {
    int len = strlen(chuoiMoi);
    int i, j = 0;

    for (i = 0; i < len; i++) {
        chuoiNguoc[j++] = chuoiMoi[(len - 1) - i];
    }

}

void chuoiInHoa(char *chuoiMoi) {
    int i;

    for (i = 0; chuoiMoi[i] != '\0'; i++) {
        if ((chuoiMoi[i] >= 'a' && chuoiMoi[i] <= 'z'))
            chuoiMoi[i] = chuoiMoi[i] - 32;
    }
}

int main() {
    char chuoi[100];
    char chuoiMoi[100];
    char chuoiNguoc[100];

    printf("Nhap chuoi vao: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    xulychuoi(chuoi, chuoiMoi);
    printf("Chuoi moi la %s", chuoiMoi);

    daoNguocChuoi(chuoiMoi, chuoiNguoc);
    printf("\nChuoi dao nguoc la: %s\n", chuoiNguoc);

    chuoiInHoa(chuoiMoi);
    printf("Chuoi in hoa la: %s\n", chuoiMoi);

    return 0;
}
