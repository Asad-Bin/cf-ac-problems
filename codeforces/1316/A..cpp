#include<bits/stdc++.h>

using namespace std;

void task()
{
    int t, n, m;
    long long total, x;
    cin>>t;
    while(t--){
        total = 0;
        cin>>n>>m;

        while(n--){
            cin>>x;
            total+=x;
        }

        if(m>total){
            cout<<total<<endl;
        }
        else{
            cout<<m<<endl;
        }
    }
}

int main()
{
    task();

    return 0;
}
