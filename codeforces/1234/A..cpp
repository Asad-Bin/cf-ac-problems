//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 19 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define    pi    acos(-1.0)

void task()
{
    ll t, n, x, total;

    cin >> t;
    while(t--){
        cin >> n;
        total=0;

        for(int K=0; K<n; K++){
            cin >> x;

            total+=x;
        }

        double ans = 1.0 * total / n;

        if(ceil(ans)-floor(ans)<0.00001) cout << total/n << "\n";
        else cout << (int)(total/n)+1 << "\n";
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
