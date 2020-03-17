#include<bits/stdc++.h>

using namespace std;

void task()
{
    int n, k, count=0, min;
    int ara[50];

    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>ara[i];
    }

    min = ara[k-1];
    for(int i=n-1; i>=0; i--){
        if(ara[i]>=min && ara[i]>0) break;
        else count++;
    }

    cout<<n-count<<endl;
}

int main()
{
    task();

    return 0;
}
