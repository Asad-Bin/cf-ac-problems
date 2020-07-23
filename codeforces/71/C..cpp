//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber

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
#define fi first
#define se second
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

// chess moves...
// int dx[] = {+0, +0, -1, +1}; ///Up-down, Left-Right
// int dy[] = {+1, -1, +0, +0};
// int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's Move
// int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
// int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2}; ///Knight's Move
// int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};

// structs...
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

// functions...
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return (a/gcd(a, b)*b);
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


void task()
{
    //code here...
    
    int n;
    
    cin >> n;
    bool ara[2*n];
    
    for(int K=0; K<n; K++) cin >> ara[K];
    
    vi save;
    for(int K=1; K*K<=n; K++){
		if(n%K==0){
			save.PB(K);
			if(K*K!=n) save.PB(n/K);
		}
	}
	
	if(!(int)save.size()){
		cout << "NO\n";
		return;
	}
	
	for(int K=n; K<2*n; K++) ara[K] = ara[K-n];
	sort(save.begin(), save.end());
	
	bool ok=0;
	int s, cnt=0;
	for(int K=0; K<(int)save.size(); K++){
		if(3*save[K]>n) break;
		
		for(int M=0; M<n; M++){
			if(ara[M]){
				s = M;
				
				
				cnt = 0;
				ok = 1;
				for(int L=s; L<n+s; L+=save[K]){
					cnt++;
					if(!ara[L]){
						ok = 0;
				//cout << "test = " << save[K] << "\n";
						break;
					}
				}
		
				if(cnt>2 && ok){
					cout << "YES\n";
					return;
				}
			}
		}
	}
	
	cout << "NO\n";
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


