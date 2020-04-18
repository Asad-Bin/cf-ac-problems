//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 18 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define    pi    acos(-1.0)

void task()
{
    int n, m, x;

    cin >> n >> m;
    vector<int> ara(n);
    vector<int> calc(n+1, 0);
    set<int> ss;

    for(int K=0; K<n; K++){
        cin >> ara[K];
    }

    for(int K=n-1; K>=0; K--){
        ss.insert(ara[K]);
        calc[K] = ss.size();
    }

    for(int K=0; K<m; K++){
        cin >> x;

        cout << calc[x-1] << endl;

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
