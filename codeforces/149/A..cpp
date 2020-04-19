//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 19 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define    pi    acos(-1.0)

void task()
{
    int k, grow=0, ans=0;
    vector<int> ara(12);

    cin >> k;

    for(int K=0; K<12; K++) cin >> ara[K];

    if(k==0){
        cout << '0' << "\n";
        return;
    }

    sort(ara.rbegin(), ara.rend());

    for(int K=0; K<12; K++){
        grow += ara[K];
        ans++;
        if(grow>=k) break;
    }

    if(grow<k) cout << "-1" << "\n";
    else cout << ans << "\n";
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

