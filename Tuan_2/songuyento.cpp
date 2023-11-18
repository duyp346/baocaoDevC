#include<stdio.h>
int kiemtra;

int main()
{	
	unsigned long x;
	printf("Nhap x: ");
	while(1){
	scanf("%d",&x);
	if(x >= 1 && x <= 100000){
//Kiem tra x co phai so nguyen to hay khong
		for(int j=2 ; j<x;j ++){
			if( x % j == 0) {
				kiemtra++;
			}
		}
		if(kiemtra < 2) printf("x la 1 so nguyen to\n");
		else printf("x khong phai la 1 so nguyen to\n");
// tim kiem nhung so nguyen to nho hon x
		for(int sonho = 2; sonho< x; sonho++){
				kiemtra=0;
				for(int j=2 ; j<=sonho;j++){
				if( sonho % j == 0) {
				kiemtra++;
			}
		}
			if(kiemtra <2) printf("%d ",sonho);
			}
	return 0;		
	}
	else printf("Nhap lai x: ");
}
}

