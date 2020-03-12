#include <bits/stdc++.h>

using namespace std;

void task()
{
    int t, n;
    cin>>t;
    while(t--){
        int ara[5001];
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>ara[i];
        }

        int count=0;
        bool flag=0;
        for(int i=0; i<n; i++){
            for(int j=n-1; j>i; j--){
                if(ara[i]==ara[j] && (j-i)>=2){
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }

        if(flag==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int main()
{
    task();

    return 0;
}
