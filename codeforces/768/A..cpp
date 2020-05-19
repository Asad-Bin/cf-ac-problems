//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 19 05 2020

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
    int n;

    cin >> n;
    vector<int> ara(n);
    int ans = n-2;

    for(int K=0; K<n; K++){
        cin >> ara[K];
    }

    if(n==1){
        cout << '0' << "\n";
        return;
    }

    sort(ara.begin(), ara.end());

    for(int K=1; K<n; K++){
        if(ara[K]!=ara[K-1] || ans==0) break;
        ans--;
    }
    for(int K=n-2; K>=0; K--){
        if(ara[K]!=ara[K+1] || ans==0) break;
        ans--;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
