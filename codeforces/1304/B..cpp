#include<bits/stdc++.h>
using namespace std;

void task()
{
    int n, m, flag1, flag2, count=0, special=-1;
    cin>>n>>m;
    char str[n+1][m+1];
    int ara[n+1][n+1], ara_list[n+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            ara[i][j]=0;
        }
    }

    for(int i=0; i<n; i++){
        scanf(" %[^\n]", str[i]);
    }

    for(int i=0; i<n; i++){
        if(i==(n-1)){
            flag2=1;
            for(int k=0; k*2<=m; k++){
                if(str[i][k]!=str[i][m-k-1]){
                    flag2=0;
                    break;
                }
            }
            if(flag2==1){
                special=i;
            }
            continue;
        }
        for(int j=i+1; j<n; j++){
            flag1=1; flag2=1;
            for(int k=0; k<m; k++){
                if(str[i][k]!=str[j][m-k-1]){
                    flag1=0; //flag2=0;
                    //break;
                }
                if(k*2<=m){
                    if(str[i][k]!=str[i][m-k-1]){
                        flag2=0;
                    }
                }
            }
            if(flag1==1){
                ara[i][j]=1;
                count++;
            }

            if(flag2==1){
                special=i;
            }
        }
    }

    int k=0;

    if(special>=0)
        printf("%d\n", (count*2+1)*m);
    else printf("%d\n", (count*2)*m);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ara[i][j]==1){
                printf("%s", str[i]);
                ara_list[k]=j;
                k++;
            }
        }
    }

    if(special>=0) printf("%s", str[special]);

    for(int i=count-1; i>=0; i--){
        printf("%s", str[ara_list[i]]);
    }
    printf("\n");

}

int main()
{
    task();

    return 0;
}
