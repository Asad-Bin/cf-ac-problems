//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 01 05 2020

#include <bits/stdc++.h>

using namespace std;

// typedefs...
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

// constants...
const double PI = acos(-1);

// defines...
#define MP make_pair
#define PB push_back
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b))
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

void task()
{
    int t, n, k, x;

    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> ara;
        vector<bool> mark(n+1);

        for(int K=0; K<n; K++){
            cin >> x;
            if(!mark[x]) ara.PB(x);
            mark[x] = 1;
        }

        if(ara.size()>k){
            cout << "-1\n";
            continue;
        }

        int i = 1;
        while(ara.size()!=k){
            if(!mark[i]) ara.PB(i);
            i++;
        }
        sort(ara.begin(), ara.end());

        cout << n*k << "\n";
        for(int K=0; K<n; K++){
            for(int L=0; L<k; L++){
                cout << ara[L] << ' ';
            }
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}

