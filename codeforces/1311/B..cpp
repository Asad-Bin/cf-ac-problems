#include<bits/stdc++.h>
using namespace std;

void task()
{
    int t, m, n, k, swa, i;
    int a[100], p[100];
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(i=0; i<=100; i++){
            p[i]=0;
        }
        for(i=0; i<n; i++){
            cin>>a[i];
        }
        for(i=0; i<m; i++){
            cin>>k;
            p[k-1]=1;
        }

        bool flag=0;
        for(int i=1; i<n; i++){
            int pos = i;
            for(int j=i-1; j>=0; j--){

                if(a[j]>a[pos]){
                    if(p[j]==0){
                        flag=1;
                        break;
                    }

                    swa = a[pos];
                    a[pos] = a[j];
                    a[j] = swa;
                    pos=j;
                }
                else{
                    break;
                }
            }
            if(flag==1) break;
        }
        if(flag==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}

int main()
{
    task();

    return 0;
}

