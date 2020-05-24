//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 24 05 2020

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
        vector<int> ara(n);
        vector<bool> mark(n);

        int even=0;
        for(int K=0; K<n; K++){
            cin >> ara[K];
            if(ara[K]%2==0) even++;
        }

        sort(ara.begin(), ara.end());

        if(even%2==1){
            for(int K=0; K<n-1; K++){
                if(ara[K+1]-ara[K]==1){
                    mark[K] = mark[K+1] = 1;
                    break;
                }
            }
        }
        for(int K=0; K<n-1; K++){
            if(mark[K]) continue;
            for(int L=K+1; L<n; L++){
                if(!mark[L] && (ara[L]%2==ara[K]%2)){
                    mark[K] = mark[L] = 1;
                    break;
                }
            }
        }

        bool flag = 0;
        for(int K=0; K<n; K++){
            if(!mark[K]){
                cout << "NO\n";
                flag=1;
                break;
            }
        }
        if(!flag) cout << "YES\n";
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

