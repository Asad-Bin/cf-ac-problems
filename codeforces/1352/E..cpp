//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 09 05 2020

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
    //code here...

    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        int ara[n];
        vector<bool> need(8010, 0);
        int mid, ans=0;

        for(int K=0; K<n; K++){
            cin >> ara[K];
            mid = ara[K];
            for(int L=K-1; L>=0; L--){
                mid+=ara[L];
                if(mid<=n) need[mid] = 1;
            }
        }

        /*for(int K=0; K<n; K++){
            for(int L=K+1; L<n; L++){
                for(int M=K; M<=L; M++){
                    mid += ara[M];
                }

                need.PB(mid);
                mid=0;
            }
        }*/

        for(int K=0; K<n; K++){
            mid = ara[K];
            if(need[mid]) ans++;
        }

        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
