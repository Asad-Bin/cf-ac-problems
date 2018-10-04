#include<stdio.h>
int main()
{
	int n, i, a, count=0;
	char s[101];
	
	scanf("%d", &n);
	scanf(" %[^\n]", s);
	
	for(i=0; i<n; i++)
	{
		if(s[i] == '8')
			count++;
	}
	
	a = n / 11;
	
	if(a <= count)
		printf("%d", a);
    else
    	printf("%d", count);
	
	return 0;
}
