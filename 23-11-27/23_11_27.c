#include <stdio.h> 
#include <stdlib.h>

int main()
{
    int number, i, a;


 
    printf("�п�J�@�Ӥj��1�������\n");
    scanf("%d",&number);

	for(i=1; i<number; i++) {
        if(number%i==0) {
        	a = i;
		}
    }
	
	if (a == 1) {
		printf("���!\n");
	}
	else
    	for(i=1; i<=number; i++) {
        	if(number%i==0)
        	printf("%d ",i);
    	}	


    system("PAUSE");
    return 0;
}
