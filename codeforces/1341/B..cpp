//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 23 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    ll test, n, k, l, p, save, pick, mid;

    cin >> test;
    while(test--){
        cin >> n >> k;
        vector<ll> ara(n+1);
        vector<ll> mark(n+1);
        pick = 0;
        p = -1;

        for(ll K=1; K<=n; K++) cin >> ara[K];

        for(ll K=1; K<=n; K++){
            if(K!=1 && K!=n && ara[K-1]<ara[K] && ara[K]>ara[K+1]) pick=1;
            mark[K] = mark[K-1]+pick;
            pick = 0;
        }
        for(ll K=1; K<=n; K++){
            if(K+k-1>n) break;
            mid = mark[K+k-2] - mark[K];
            if(mid>p){
                p = mid;
                save = K;
            }
        }

        cout << p+1 << ' ' << save << "\n";
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
