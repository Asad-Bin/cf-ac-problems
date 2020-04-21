//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 21 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    ll t, n, ans, mid;

    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> ara(n);
        ans = 0;

        for(ll K=0; K<n; K++) cin >> ara[K];

        for(ll K=0; K<n; K++){
            mid = ara[K];
            if(ara[K]>0){
                for(ll L=K+1; L<n; L++){
                    if(ara[L]<0){
                        K = L-1;
                        break;
                    }
                    if(L==n-1) K = n-1;
                    mid = max(mid, ara[L]);
                }
            }
            else{
                for(int L=K+1; L<n; L++){
                    if(ara[L]>0){
                        K = L-1;
                        break;
                    }
                    if(L==n-1) K = n-1;
                    mid = max(mid, ara[L]);
                }
            }
            ans += mid;
        }

        cout << ans << "\n";
    }
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

