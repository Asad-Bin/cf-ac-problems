//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 22 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    ll n, ans=-1;

    cin >> n;
    vector<ll> ara(n);

    for(ll K=0; K<n; K++) cin >> ara[K];

    if(n==1){
        cout << "1\n";
        return;
    }
    else if(n==2){
        if(ara[0]<ara[1])cout << "2\n";
        else cout << "1\n";

        return;
    }

    for(ll K=0; K<n-1; K++){
        for(ll L=K; L<n-1; L++){
            if(ara[L+1]<=ara[L]){
                ans = max(ans, L-K+1);
                //cout << ans << ' ' << L << "\n";
                K = L;
                break;
            }
            if(L==n-2){
                ans = max(ans, n-K);
                K = L;
            }
        }
    }

    cout << ans << "\n";
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
