#include <stdio.h>
int dayso(int n) {
    unsigned long f0 = 0;
    unsigned long f1 = 1;
    unsigned long fn = 1;

     if ( n == 1) {
        return n;
    } else {
        for (int i = 2; i < n; i++) {
            f0 = f1;
            f1 = fn;
            fn = f0 + f1;
        }
    }
    return fn;
}
int main() {
    for (int i = 1; i < 71; i++) {
        printf("%lu ", dayso(i));
    }
}