//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 16 06 2020

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
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return (a*b/gcd(a, b));
}
ll comb(ll a, ll b)
{
    ll x = max(a-b, b), ans=1;

    for(ll K=a, L=1; K>=x+1; K--, L++){
        ans *= K;
        ans /= L;
    }

    return ans;
}


void bruce()
{
    cout << "\nExpected answer:\n";
    cout << "\nAnswer recieved:\n";
}

void task()
{
    //code here...

    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vi ara(n);
        for(int K=0; K<n; K++) cin >> ara[K];

        int ans = 0, f; bool flag = 0;
        for(int K=0; K<n; K++){
            if(K%2==ara[K]%2) continue;
            //cout << "K= " << K << ' ' << f << ' ' << ans << "\n";
            for(int L=K+1; L<n; L++){
                if(ara[L]%2!=L%2 && K%2==ara[L]%2){
                    swap(ara[K], ara[L]);
                    ans++;
                    break;
                }
            }
            if(K%2!=ara[K]%2){
                flag = 1;
                break;
            }
        }

        if(flag==1) cout << "-1\n";
        else cout << ans << "\n";
    }
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

