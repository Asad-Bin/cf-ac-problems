//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 18 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define    pi    acos(-1.0)

void task()
{
    int n, m, k, mid, ans=0, count;

    cin >> n >> m >> k;
    vector<int> ara(m+1);

    for(int K=0; K<=m; K++) cin >> ara[K];

    for(int K=m-1; K>=0; K--){
        mid = ara[m];
        mid = ara[K]^mid;
        count=0;
        while(1){
            if(mid&1) count++;
            mid >>= 1;
            if(!mid) break;
        }

        if(count<=k) ans++;
    }

    cout<< ans << "\n";
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
