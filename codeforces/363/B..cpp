//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 19 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define    pi    acos(-1.0)

void task()
{
    int n, k, save=1, x, total;
    ll ans=2*1e18;

    cin >> n >> k;
    vector<int> ara(n);

    cin >> ara[0];
    for(int K=1; K<n; K++){
        cin >> x;

        ara[K] = ara[K-1]+x;
    }

    for(int K=0; K<n-k+1; K++){
        if(K==0) total = ara[K+k-1];
        else total = ara[K+k-1] - ara[K-1];
        //cout << total << endl;

        if(total<ans){
            ans = total;
            save = K+1;
        }
    }

    cout << save << "\n";
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
