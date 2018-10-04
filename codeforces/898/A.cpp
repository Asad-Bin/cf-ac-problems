#include<stdio.h>

int main()
{
	long int n;
	
	scanf("%ld", &n);
	
	if(n%10==0)
	    printf("%ld", n);
	else if(n%10 != 0 && n%5==0)
	    printf("%ld", n-5);
	else if(n%5 != 0 && n%10>5)
	    printf("%ld", n+10-(n%10));
	else if(n%5 != 0 && n%10<5)
		printf("%ld", n-(n%10));
		
    return 0;
}
