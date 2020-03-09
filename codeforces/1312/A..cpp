#include<bits/stdc++.h>

using namespace std;

void task()
{
    long int t;

    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;

        if(n%m==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int main()
{
    task();

    return 0;
}
