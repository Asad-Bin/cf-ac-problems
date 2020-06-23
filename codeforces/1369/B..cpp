//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 22 06 2020

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
        string s;
        cin >> s;
        vector<bool> mark(n);

        int l = n, r = -1;

        for(int K=0; K<n; K++){
            if(s[K]=='1'){
                l = K;
                break;
            }
        }
        for(int K=n-1; K>=0; K--){
            if(s[K]=='0'){
                r = K-1;
                break;
            }
        }

        if(r>=l){
            s.erase(l, r-l+1);
        }

        cout << s << "\n";

        /*bool f = 0;
        for(int K=0; K<n-1; K++){
            if(s[K]=='1' && s[K+1]=='0'){
                f = 1;
                break;
            }
        }

        if(f){
            int l = -1;
            for(int K=0; K<n-1; K++){
                //cout << K << ' ' << l << ' ' << s[K] << " " << K-l << ' ' << s << "\n";
                if(l==-1 && s[K]=='1'){
                    l = K;
                    //r = -1;
                }
                if(s[K]=='0' && l!=-1 && (K+1==n-1 || s[K+1]=='1')){
                    for(int L=l; L<K; L++) mark[L] = 1;
                    //s.erase(l, K-l);
                    //K = max(0, K-l);
                    l = -1;
                }
            }
        }

        for(int K=0; K<n; K++){
            if(!mark[K]) cout << s[K];
        }
        cout << "\n";*/
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

