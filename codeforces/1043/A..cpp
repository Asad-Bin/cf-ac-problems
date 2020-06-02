//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 02 06 2020

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

void bruce(int n, vi v)
{
    cout << "\nExpected answer:\n";

    int k=0,  total=0, sum=0;
    for(int K=0; K<n; K++) {
        k = max(k, v[K]);
    }
    for(int K=0; K<n; K++) total += v[K];
    for(int K=0; K<n; K++){
        v[K] = k - v[K];
        sum += v[K];
    }

    for(int K=k; ; K++){
        if(sum>total){
            cout << K << "\n";
            break;
        }
        sum += n;
    }

    cout << "\nAnswer recieved:\n";
}

void task()
{
    //code here...

    int n, k=0, ans, total=0, sum=0;

    cin >> n;
    vector<int> ara(n);
    for(int K=0; K<n; K++) cin >> ara[K];
    //bruce(n, ara);

    for(int K=0; K<n; K++) {
        k = max(k, ara[K]);
        total += ara[K];
    }

    for(int K=0; K<n; K++){
        ara[K] = k - ara[K];
        sum += ara[K];
    }
    //cout << total << ' ' << sum << ' ' << k << "\n";

    if(sum>total){
        cout << k << "\n";
        return;
    }
    ans = (int)(total-sum)/n;
    ans++;
    ans += k;

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

