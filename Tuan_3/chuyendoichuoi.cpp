#include <stdio.h>
#include <string.h>

int main() {
  char a[100] = "fresher embedded";
  int len = strlen(a);
  
  for (int i = 0; i < len; i++) {
    if (a[i] == 'e') {
      for (int j = len; j > i; j--) {
        a[j+1] = a[j]; 
      }
      a[i] = 'e';
      a[i+1] = 'f';
      len++;
    }
  }
  
  printf("%s\n", a);
  
  return 0;
}