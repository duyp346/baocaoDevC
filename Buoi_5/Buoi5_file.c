#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *filegoc, *fileso, *filechu, *filekytu;
    int kytu;

    filegoc = fopen("C:\\Users\\Admin\\Desktop\\baitest.txt", "r");

    if (filegoc == NULL) {
        perror("error");
        return 1;
    }

    fileso = fopen("C:\\Users\\Admin\\Desktop\\numbers.txt", "w");
    filechu = fopen("C:\\Users\\Admin\\Desktop\\letters.txt", "w");
    filekytu = fopen("C:\\Users\\Admin\\Desktop\\special_chars.txt", "w");

    if (fileso == NULL || filechu == NULL || filekytu == NULL) {
        perror("error");
        fclose(filegoc);
        return 1;
    }

    while ((kytu = fgetc(filegoc)) != EOF) {
        printf("%c", kytu);

        if (isdigit(kytu)) {
            fprintf(fileso, "%c",kytu); 
        } else if (isalpha(kytu)) {
            fprintf(filechu, "%c",kytu); 
        } else if (ispunct(kytu)) {
            fprintf(filekytu, "%c",kytu); 
        }
    }

    fclose(filegoc);
    fclose(fileso);
    fclose(filechu);
    fclose(filekytu);

    printf("Hoan thanh.\n");

    return 0;
}
