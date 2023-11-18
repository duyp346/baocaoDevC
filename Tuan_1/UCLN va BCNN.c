#include <stdio.h>
#include <math.h>
int a,b;

int main()
{   while(1){

	 printf("Nhap a ");
	 scanf("%d",&a);
	 printf("Nhap b ");
	 scanf("%d",&b);
	 
	 if(a>=1 && b<=10000 && a<b){
	 	
	 	int ucln[b],bcnn;
	 	int j=0;
	 	for(int i = 1;i<b+1;i++){
		if(a % i ==0 && b% i == 0) ucln[j++]=i;
		
		}
	
		int max=ucln[0];
	 	for(int i = 0;i<j;i++){
	 		if(max<ucln[i]) max=ucln[i]; //tim UCLN
		}
		bcnn = (a*b)/max; //tim BCNN
		printf("UCLN LA %d\n",max);
		printf("BCNN LA %d",bcnn);
		
		return 0;
	}
	else 
	printf("Nhap lai a va b\n ");
}
}
