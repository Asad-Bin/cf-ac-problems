#include<bits/stdc++.h>

using namespace std;

void task()
{
    long long n, m, a, rem_1, rem_2, ans=1;

    cin>>n>>m>>a;

    //ans = n * m / (a*a);
    rem_1 = n % a;
    if(rem_1 !=0) n = n - rem_1 + a;
    //ans = (ans * n) / a;
    rem_2 = m % a;
    if(rem_2 !=0) m = m - rem_2 + a; /*
    //ans = (ans * m) / a;

    //cout<<rem_1<<' '<<rem_2<<endl;
    if(rem_1!=0){
        ans = ans + (m/a);
        //cout<<ans<<endl;
    }

    if(rem_2!=0){
        ans = ans + (n/a);
        //cout<<ans<<endl;
    }

    if(rem_1!=0 && rem_2!=0) ans++;*/

    cout<<n*m/(a*a)<<endl;
}

int main()
{
    task();

    return 0;
}
