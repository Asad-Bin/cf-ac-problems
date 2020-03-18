#include <bits/stdc++.h>

using namespace std;

void task()
{
    int n, sum=0, own=0, record=0;
    int ara[100];

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ara[i];
        sum += ara[i];
    }

    sort(ara, ara+n);

    //for(int i=n-1; i>=0; i--) cout<<ara[i]<<endl;

    for(int i=n-1; i>=0; i--){
        //cout<<ara[i]<<endl;
        own += ara[i];
        record++;
        sum -= ara[i];
        if(own>sum) break;
    }

    cout<<record<<endl;
}

int main()
{
    task();

    return 0;
}
