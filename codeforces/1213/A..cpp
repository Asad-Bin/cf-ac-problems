//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 22 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    ll n, even=0, odd=0, x;

    cin >> n;
    vector<ll> ara(n);

    for(ll K=0; K<n; K++){
        cin >> x;
        if(x%2==0) even++;
        else odd++;
    }

    cout << min(even, odd) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
