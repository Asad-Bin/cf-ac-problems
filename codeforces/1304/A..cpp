#include<bits/stdc++.h>
using namespace std;

void task()
{
    int t, a, b, x, y, result;

    cin>>t;
    while(t--){
        cin>>x>>y>>a>>b;

        if((y-x)%(a+b)==0) cout<<(y-x)/(b+a)<<endl;
        else cout<<"-1"<<endl;
    }
}

int main()
{
    task();

    return 0;
}
