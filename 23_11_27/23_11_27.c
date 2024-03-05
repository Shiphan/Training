#include <stdio.h> 
#include <stdlib.h>

int main()
{
    int number, i, a;


 
    printf("請輸入一個大於1的正整數\n");
    scanf("%d",&number);

	for(i=1; i<number; i++) {
        if(number%i==0) {
        	a = i;
		}
    }
	
	if (a == 1) {
		printf("質數!\n");
	}
	else
    	for(i=1; i<=number; i++) {
        	if(number%i==0)
        	printf("%d ",i);
    	}	


    system("PAUSE");
    return 0;
}
