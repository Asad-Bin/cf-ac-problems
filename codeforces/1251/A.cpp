#include<stdio.h>
#include<string.h>

int main()
{
    int i, j, t;
    int ara[123];
    char str[501];
    scanf("%d", &t);
    
    for(i=0; i<t; i++){
        for(j=97; j<=122; j++) ara[j]=0;
        scanf("%s", str);
        
        for(j=0; j<strlen(str); ){
            if(str[j]!=str[j+1]){
                
                ara[str[j]] = 1;
                j++;
            }
            else j+=2;
        }
        
        for(j=97; j<=122; j++){
            if(ara[j] == 1) printf("%c", j);
        }
        printf("\n");
    }
    
    return 0;
}