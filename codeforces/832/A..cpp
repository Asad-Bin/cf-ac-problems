#include <bits/stdc++.h>

using namespace std;

void task()
{
    long long n, k, mid;

    cin>>n>>k;

    mid = n / k;

    if(mid%2==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    task();

    return 0;
}
