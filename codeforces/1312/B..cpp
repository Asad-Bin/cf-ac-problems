#include<bits/stdc++.h>

using namespace std;

void task()
{
    int t, n, x;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> ara(n);
        for(int i=0; i<n; i++){
            cin>>x;
            ara[i]=x;
        }

        sort(ara.begin(), ara.end());
        //ara.reverse();

        for(int i=n-1; i>=0; i--){
            cout<<ara[i]<<' ';
        }
        cout<<endl;
    }
}

int main()
{
    task();

    return 0;
}
