//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 09 06 2020

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

ll gcd(ll a, ll b)
{
    if(a%b==0) return b;
    return gcd(b, a%b);
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

string s[50];
bool vis[50][50];

bool bfs(int n, int m)
{
    queue<pii> Q;
    pii u;
    int K, L;
    if(s[n][m]!='#') Q.push(MP(n, m));

    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        K = u.first;
        L = u.second;
        if(vis[K][L]) continue;
        vis[K][L] = 1;

        if(L>0 && !vis[K][L-1] && (s[K][L-1]=='.' || s[K][L-1]=='G')) Q.push(MP(K, L-1));
        else if(L>0 && !vis[K][L-1] && s[K][L-1]=='B') return 0;

        if(K<n && !vis[K+1][L] && (s[K+1][L]=='.' || s[K+1][L]=='G')) Q.push(MP(K+1, L));
        else if(K<n && !vis[K+1][L] && s[K+1][L]=='B') return 0;

        if(L<m && !vis[K][L+1] && (s[K][L+1]=='.' || s[K][L+1]=='G')) Q.push(MP(K, L+1));
        else if(L<m && !vis[K][L+1] && s[K][L+1]=='B') return 0;

        if(K>0 && !vis[K-1][L] && (s[K-1][L]=='.' || s[K-1][L]=='G')) Q.push(MP(K-1, L));
        else if(K>0 && !vis[K-1][L] && s[K-1][L]=='B') return 0;
    }

    return 1;
}

void task()
{
    //code here...

    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int K=0; K<n; K++){
            for(int L=0; L<m; L++) vis[K][L] = 0;
        }

        for(int K=0; K<n; K++) cin >> s[K];

        if(n==1 && m==1 && (s[0][0]=='.' || s[0][0]=='G' || s[0][0]=='#')){
            cout << "Yes\n";
            continue;
        }
        else if(n==1 && m==1){
            cout << "No\n";
            continue;
        }

        int g = 0;
        bool f = 0;
        for(int K=0; K<n; K++){
            for(int L=0; L<m; L++){
                if(s[K][L]=='B'){
                    if(L>0 && s[K][L-1]=='.') s[K][L-1] = '#';
                    else if(L>0 && s[K][L-1]=='G'){
                        f = 1;
                        break;
                    }

                    if(K<n-1 && s[K+1][L]=='.') s[K+1][L] = '#';
                    else if(K<n-1 && s[K+1][L]=='G') {
                        f =1;
                        break;
                    }

                    if(L<m-1 && s[K][L+1]=='.') s[K][L+1] = '#';
                    else if(L<n-1 && s[K][L+1]=='G'){
                        f = 1;
                        break;
                    }

                    if(K>0 && s[K-1][L]=='.') s[K-1][L] = '#';
                    else if(K>0 && s[K-1][L]=='G') {
                        f = 1;
                        break;
                    }
                }
            }
            if(f) break;
        }
        if(f){
            cout << "No\n";
            continue;
        }

        f = 0;
        bool xx = bfs(n-1, m-1);
        if(!xx){
            cout << "No\n";
            continue;
        }
        else{
            for(int K=0; K<n; K++){
                for(int L=0; L<m; L++){
                    if(s[K][L]=='G' && !vis[K][L]){
                        cout << "No\n";
                        f = 1;
                        break;
                    }
                }
                if(f) break;
            }
        }
        if(!f) cout << "Yes\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

