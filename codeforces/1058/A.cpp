#include<stdio.h>
int main()
{
    int n, i, a, p=0;

    scanf("%d", &n);

    for(i=1;i<=n; i++)
    {
        scanf("%d", &a);

        if(a == 1)
            p = 1;
        else
            continue;
    }

    if(p == 1)
        printf("HARD");
    else
        printf("EASY");

    return 0;
}
