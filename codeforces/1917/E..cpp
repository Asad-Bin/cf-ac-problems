// . . . Bismillahir Rahmanir Rahim . . .


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg_out cout
#define debug(...) dbg_out << "DBG )> "; __f(#__VA_ARGS__, __VA_ARGS__);
template<typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2> pr) { out << "{ " << pr.first << ", " << pr.second << " }"; return out; }
template<typename T1> ostream& operator<<(ostream& out, vector<T1> vec) { out << "{ "; for (auto &x: vec) out << x << ", "; out << "}"; return out; }
template<typename T1, size_t size> ostream& operator<<(ostream& out, array<T1, size> arr) { out << "{ "; for (auto &x: arr) out << x << ", "; out << "}"; return out; }
template<typename T1, typename T2> ostream& operator<<(ostream& out, map<T1, T2> mp) { out << "{ ";for (auto &x: mp) out << x.first << ": " << x.second <<  ", "; out << "}"; return out; }
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { while (isspace(name[0])) name++; (isalpha(name[0]) || name[0] == '_') ? dbg_out << name << ": " << arg1 << "\n" : dbg_out << arg1 << "\n"; dbg_out.flush();}
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) { const char *comma = strchr(names + 1, ','); while (isspace(names[0])) names++; (isalpha(names[0]) || names[0] == '_') ? dbg_out.write(names, comma - names) << ": " << arg1 << " | " : dbg_out << arg1 << " | "; __f(comma + 1, args...);}
#else
#define debug(...)
#endif

ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b,ll mod){ 
    b %= (mod-1);
    a %= mod;

    if(b==0){
     return 1;
    } 
    ll tm=bigmod(a,b/2,mod); 
    tm=(tm*tm)%mod; 
    if(b%2==1) tm=(tm*a)%mod; 
    return tm;
}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1; 
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        // cout << "Case " << cs << "\n";

        ll n, k; cin >> n >> k;

        int ara[n][n];
        memset(ara, 0, sizeof ara);

        if(k&1ll){
            cout << "No\n";
            continue;
        }
        else if(k % 4 == 0){
            for(int K = 0; K < n; K+=2){
                for(int L = 0; L < n-1; L += 2){
                    if(k){
                        ara[K][L] = ara[K][L+1] = ara[K+1][L] = ara[K+1][L+1] = 1;
                        k -= 4;
                    }
                }
            }
        }
        else if(k == 2 || k == n*n-2){
            if(n == 2){
                cout << "Yes\n";
                cout << "1 0\n"  << "0 1\n" << "\n";
            }
            else{
                cout << "No\n";
            }
            continue;
        }
        else if(k <= n*n-10){
            // cout << "lol\n";
            ara[0][0] = 1, ara[0][1] = 1, ara[0][2] = 0, ara[0][3] = 0;
            ara[1][0] = 1, ara[1][1] = 0, ara[1][2] = 1, ara[1][3] = 0;
            ara[2][0] = 0, ara[2][1] = 1, ara[2][2] = 1, ara[2][3] = 0;
            ara[3][0] = 0, ara[3][1] = 0, ara[3][2] = 0, ara[3][3] = 0;
            k -= 6;
            for(int K = 0; K < n; K+=2){
                for(int L = 0; L < n; L+=2){
                    if(K <= 3 && L <= 3) continue;

                    if(k){
                        ara[K][L] = 1, ara[K][L+1] = 1;
                        ara[K+1][L] = 1, ara[K+1][L+1] = 1;
                        k -= 4;
                    }
                }
            }
        }
        else if(k == n*n - 6){
            ara[0][0] = 1, ara[0][1] = 1, ara[0][2] = 0, ara[0][3] = 0;
            ara[1][0] = 1, ara[1][1] = 0, ara[1][2] = 1, ara[1][3] = 0;
            ara[2][0] = 1, ara[2][1] = 1, ara[2][2] = 1, ara[2][3] = 1;
            ara[3][0] = 1, ara[3][1] = 0, ara[3][2] = 0, ara[3][3] = 1;
            k -= 10;
            for(int K = 0; K < n; K+=2){
                for(int L = 0; L < n; L+=2){
                    if(K <= 3 && L <= 3) continue;

                    if(k){
                        ara[K][L] = 1, ara[K][L+1] = 1;
                        ara[K+1][L] = 1, ara[K+1][L+1] = 1;
                        k -= 4;
                    }
                }
            }
        }
        else{
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";
        for(int K = 0; K < n; K++){
            for(int L = 0; L < n; L++) cout << ara[K][L] << ' ' ;
            cout << "\n";
        }
    }

    return 0;
}





























