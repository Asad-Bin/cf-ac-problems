//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 21 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    ll t, s;

    cin >> t;
    while(t--){
        cin >> s;

        ll ans=0, mid;

        while(1){
            if(s<10) {
                ans += s;
                break;
            }
            ans += (s - s%10);
            s = s/10 + s%10;
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

