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
ll bigmod(ll a,ll b,ll mod){ if(b==0){ return 1;} ll tm=bigmod(a,b/2,mod); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}



const int MX = 2e5;   // query size . . .
//const int MXI = 1e6;  // maximum value in array . . .
//ll cnt[MXI+5];
ll block_size, range_ans;
struct Query{
    int id, l, r;
    
    Query() {}
    Query(int _id, int _l, int _r){
        id = _id;
        l = _l;
        r = _r;
    }
    
    bool operator<(Query &other) const{
        int curr_size = l/block_size;
        int other_size = other.l/block_size;
        
        if(curr_size == other_size) return r < other.r;
        return curr_size < other_size;
    }
} query[MX+5];

int ans = 0;
int ara[MX+5];
deque<int> q;
void ladd(ll i, int r)
{
	if(i >= r || ara[i] < ara[i+1]) ans++;
	else if(i+2 <= r && ara[i+1] < ara[i+2]) ans++;
	else if(i+1 == r) ans++;
	
    //if(cnt[x]) range_ans -= cnt[x]*cnt[x]*x;
    //cnt[x]++;
    //range_ans += cnt[x]*cnt[x]*x;
}
void radd(ll i, int l)
{
	if(i <= l || ara[i-1] < ara[i]) ans++;
	else if(l <= i-2 && ara[i-2] < ara[i-1]) ans++;
	else if(l == i-1) ans++;
	
    //range_ans -= cnt[x]*cnt[x]*x;
    //cnt[x]--;
    //if(cnt[x]) range_ans += cnt[x]*cnt[x]*x;
}
void lrmv(ll i, int r)
{
	if(i >= r || ara[i] < ara[i+1]) ans--;
	else if(i+2 <= r && ara[i+1] < ara[i+2]) ans--;
	else if(i+1 == r) ans--;
	
    //range_ans -= cnt[x]*cnt[x]*x;
    //cnt[x]--;
    //if(cnt[x]) range_ans += cnt[x]*cnt[x]*x;
}
void rrmv(ll i, int l)
{
	if(i <= l || ara[i-1] < ara[i]) ans--;
	else if(l <= i-2 && ara[i-2] < ara[i-1]) ans--;
	else if(l == i-1) ans--;
	
    //range_ans -= cnt[x]*cnt[x]*x;
    //cnt[x]--;
    //if(cnt[x]) range_ans += cnt[x]*cnt[x]*x;
}
void mos_algo()
{
    int n, t, l, r;
    
    cin >> n >> t;
    
    // setting block size ...
    block_size = sqrt(n);
    
    for(int K = 0; K < n; K++) cin >> ara[K];
    
    for(int K = 0; K < t; K++){
        cin >> l >> r;
        
        query[K] = Query(K, l-1, r-1); // 0-based indexing . . .
    }
    sort(query, query+t);
    
    int L = 0, R = -1;
    ll v[t];
    
    int i = -1;
    for(int K = 0; K < t; K++){
        l = query[K].l;
        r = query[K].r;
        
        while(R < r){
            R++;
            //radd(R, l);
            q.push_back(ara[R]);
            i++;
            if(i == 0 || q[i-1] < q[i]) ans++;
            else if(i >= 2 && q[i-2] < q[i-1]) ans++;
            else if(i == 1) ans++;
        }
        while(L < l){
            //lrmv(L, r);
            
            if(i==0 || q[0] < q[1]) ans--;
            else if(i >= 2 && q[1] < q[2]) ans--;
            else if(i == 1) ans--;
            
            q.pop_front();
            i--;
            
            L++;
        }
        while(L > l){
            L--;
            //ladd(L, r);
            
            
            q.push_front(ara[L]);
            i++;
            if(i == 0 ||  q[0] < q[1]) ans++;
            else if(i >= 2 && q[1] < q[2]) ans++;
            else if(i == 1) ans++;
        }
        while(R > r){
            //rrmv(R, l);
            
            if(i == 0 || q[i-1] < q[i]) ans--;
            else if(i >= 2 && q[i-2] < q[i-1]) ans--;
            else if(i == 1) ans--;
            
            q.pop_back();
            i--;
            
            
            R--;
        }
        
        //cout << l << ' ' << r << ' ' << ans << "\n";
        v[query[K].id] = ans;
    }
    
    for(int K = 0; K < t; K++) cout << v[K] << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	mos_algo();
	
	return 0;
}





































