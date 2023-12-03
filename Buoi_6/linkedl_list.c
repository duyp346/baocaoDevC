#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nhanVien
{
    char hoTen[20];
    char maNhanVien[10];
    int luong;
    struct nhanVien *next;
} nhanVien;

void nhap(nhanVien *nv)
{
    while (getchar() != '\n');
    printf("Nhap ho ten nhan vien: ");
    fgets(nv->hoTen, sizeof(nv->hoTen), stdin);
    nv->hoTen[strcspn(nv->hoTen, "\n")] = '\0'; 
    printf("Nhap ma nhan vien: ");
    fgets(nv->maNhanVien, sizeof(nv->maNhanVien), stdin);
    nv->maNhanVien[strcspn(nv->maNhanVien, "\n")] = '\0';

    printf("Nhap luong nhan vien: ");
    scanf("%d", &nv->luong);
    nv->next = NULL; 
}

void xuat(nhanVien nv)
{
    printf("\tHo ten nhan vien: %s\n", nv.hoTen);
    printf("\tMa nhan vien: %s\n", nv.maNhanVien);
    printf("\tLuong nhan vien: %d VND\n", nv.luong);
}

void nhapDanhSach(nhanVien **danhSach, int *soNhanVien)
{
    int dem = *soNhanVien;
    int dem2;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", soNhanVien);
    dem2 = *soNhanVien;
    int i;

    if (dem >= 1)
    {
        *soNhanVien = dem + dem2;
        for (i = dem; i < *soNhanVien; i++)
        {
            nhanVien *nv = (nhanVien *)malloc(sizeof(nhanVien));
            nhap(nv);

            nhanVien *temp = *danhSach;
            if (temp == NULL)
            {
                *danhSach = nv;
            }
            else
            {
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = nv;
            }
        }
    }
    else
    {
        for (i = 0; i < *soNhanVien; i++)
        {
            nhanVien *nv = (nhanVien *)malloc(sizeof(nhanVien));
            nhap(nv);

            nhanVien *temp = *danhSach;
            if (temp == NULL)
            {
                *danhSach = nv;
            }
            else
            {
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = nv;
            }
            dem++;
        }
    }
}

void xuatDanhSach(nhanVien *danhSach)
{
    nhanVien *temp = danhSach;
    int i = 1;

    while (temp != NULL)
    {
        printf("Thong tin nhan vien: %d\n", i++);
        xuat(*temp);
        temp = temp->next;
    }
}

void timNhanVienTheoMa(nhanVien *ds, char ma[])
{
    nhanVien *temp = ds;

    while (temp != NULL)
    {
        if (strcmp(ma, temp->maNhanVien) == 0)
        {
            printf("\nNhan vien co ma so %s:\n", ma);
            xuat(*temp);
        }
        temp = temp->next;
    }
}

void timNhanVienTheoTen(nhanVien *ds, char ten[])
{
    nhanVien *temp = ds;
    int dem = 0;

    while (temp != NULL)
    {
        if (strstr(temp->hoTen, ten) != NULL)
        {
            printf("\nNhan vien co ten <%s> ben trong:\n", ten);
            xuat(*temp);
            dem++;
        }
        temp = temp->next;
    }

    if (dem == 0)
    {
        printf("\nKhong tim duoc nhan vien co ten nay\n");
    }
}

void xoaNhanVienTheoTen(nhanVien **danhSach, char ten[])
{
    nhanVien *current = *danhSach;
    nhanVien *prev = NULL;
    int dem = 0;

    while (current != NULL)
    {
        if (strstr(current->hoTen, ten) != NULL)
        {
            printf("\nNhan vien co ten <%s> ben trong:\n", ten);
            xuat(*current);
            printf("\nBan co xac nhan xoa nhan vien nay\n");

            char luaChon;
            printf("\nNhan phim 'y' de xac nhan xoa: ");
            scanf(" %c", &luaChon);

            if (luaChon == 'y' || luaChon == 'Y')
            {
                if (prev != NULL)
                {
                    prev->next = current->next;
                    free(current);
                    dem++;
                }
                else
                {
                    *danhSach = current->next;
                    free(current);
                    dem++;
                }
            }
        }

        prev = current;
        current = current->next;
    }

    if (dem == 0)
    {
        printf("\nKhong tim duoc nhan vien co ten nay\n");
    }
}

void menu()
{
    nhanVien *danhSach = NULL;
    int soNhanVien = 0;
    char ma[10];
    char ten[20];

    int luaChon;

    do
    {
        printf("\n---------------MENU-------------");
        printf("\n1.Them nhan vien moi");
        printf("\n2.Tim nhan vien theo ma so");
        printf("\n3.Tim nhan vien theo ten");
        printf("\n4.Xoa nhan vien theo ma so");
        printf("\n5.Xoa nhan vien theo ten");
        printf("\n6.Hien thi danh sach nhan vien");
        printf("\n0.Thoat chuong trinh");
        printf("\nChon 1 trong cac chuc nang tren: ");
        scanf("%d", &luaChon);

        switch (luaChon)
        {
        case 0:
            printf("\n\tBan da chon thoat! ");
            printf("\n\t    TAM BIET!");
            break;
        case 1:
            nhapDanhSach(&danhSach, &soNhanVien);
            xuatDanhSach(danhSach);
            break;
        case 2:
            while (getchar() != '\n')
                ;
            printf("Nhap ma can tim: ");
            scanf("%s", ma);
            timNhanVienTheoMa(danhSach, ma);
            break;
        case 3:
            while (getchar() != '\n')
                ;
            printf("Nhap ten can tim: ");
            fgets(ten, sizeof(ten), stdin);
            ten[strcspn(ten, "\n")] = '\0'; 
            timNhanVienTheoTen(danhSach, ten);
            break;
        case 4:
            while (getchar() != '\n')
                ;
            printf("Nhap ma nhan vien can xoa: ");
            scanf("%s", ma);
            xoaNhanVienTheoTen(&danhSach, ma);
            xuatDanhSach(danhSach);
            break;
        case 5:
            while (getchar() != '\n')
                ;
            printf("Nhap ten nhan vien can xoa: ");
            fgets(ten, sizeof(ten), stdin);
            ten[strcspn(ten, "\n")] = '\0'; 
            xoaNhanVienTheoTen(&danhSach, ten);
            xuatDanhSach(danhSach);
            break;
        case 6:
            printf("Hien thi danh sach nhan vien hien tai:\n");
            xuatDanhSach(danhSach);
            break;
        default:
            printf("Vui long chon chuc nang tuong ung tai MENU!\n");
            break;
        }
    } while (luaChon);
}

int main()
{
    menu();
    return 0;
}
