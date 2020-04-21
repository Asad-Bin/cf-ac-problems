//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 21 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    ll t, n, x, p, mid;

    cin >> t;
    while(t--){
        cin >> n;
        p = 2;

        while(1){
            mid = (int)pow(2,p)-1;
            if(n%mid==0){
                cout << (int)(n/mid) << "\n";
                break;
            }

            p++;
        }
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

