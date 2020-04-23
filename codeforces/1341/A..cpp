//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 23 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    int t, n, a, b, c, d, mid;

    cin >> t;
    while(t--){
        cin >> n >> a >> b >> c >> d;

        if(n*(a-b)<(c-d)){
            if(n*(a+b)>=(c-d)) cout << "YES\n";
            else cout << "NO\n";
        }
        else if(n*(a+b)>(c+d)){
            if(n*(a-b)<=(c+d)) cout << "YES\n";
            else cout << "NO\n";
        }
        else if(n*(a-b)>(c+d)) cout << "NO\n";
        else if(n*(a+b)<(c-d)) cout << "NO\n";
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
