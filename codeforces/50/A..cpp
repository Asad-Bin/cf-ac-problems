#include <bits/stdc++.h>

using namespace std;

void task()
{
    int m, n, rem_1, rem_2, ans_1, ans_2;
    cin>>m>>n;

    rem_1 = n%2;
    ans_1 = n / 2;
    ans_1 *= m;
    if(rem_1==1) ans_1 += m/2;

    rem_2 = m%2;
    ans_2 = m / 2;
    ans_2 *= n;
    if(rem_2==1) ans_2 += n/2;

    cout<<max(ans_1, ans_2);
}

int main()
{
    task();

    return 0;
}
