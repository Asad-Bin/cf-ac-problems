//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 22 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    int t, n, mid, x;

    cin >> t;
    while(t--){
        cin >> n;

        cin >> x;
        mid = x%2;
        bool flag = 0;

        for(int K=0; K<n-1; K++){
            cin >> x;
            if(x%2!=mid){
                flag = 1;
            }
        }

        if(flag==1) cout << "NO\n";
        else cout << "YES\n";
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
