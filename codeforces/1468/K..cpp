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
const int MOD = 1e9+7; // 998244353;
const int MXS = 2e5+5;
const int MXI = 1e9+5;
const ll MXL = 1e18+5;
 
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
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
 
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
ll gcd(ll a, ll b) {
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
        ans = ans * K;
        ans /= L;
    }
 
    return ans;
}


int t, n;
string s;
bool check(int x, int y)
{
	//cout << n << ' ' << x << ' ' << y << "\n";
	int i = 0, j = 0;
	for(int K=0; K<n; K++){
		if(s[K]=='R'){
			if(i+1==x && j==y) continue;
			
			i++;
		}
		else if(s[K]=='U'){
			if(i==x && j+1==y) continue;
			
			j++;
		}
		else if(s[K]=='L'){
			if(i-1==x && j==y) continue;
			
			i--;
		}
		else if(s[K]=='D'){
			if(i==x && j-1==y) continue;
			
			j--;
		}
	}
	//cout << n << ' ' << i << ' ' << j << "\n";
	if(i==0 && j==0) return true;
	return false;
}
void task()
{
	// Code here.. ..
	
	
	cin >> t;
	while(t--){
		cin >> s;
		
		n = (int)s.length();
		int ans_x = MXI, ans_y = MXI, x = 0, y = 0;
		
		for(int K=0; K<n; K++){
			if(s[K]=='R'){
				if(check(x+1, y)){
					ans_x = x+1;
					ans_y = y;
					break;
				}
				else x++;
			}
			else if(s[K]=='U'){
				if(check(x, y+1)){
					ans_x = x;
					ans_y = y+1;
					break;
				}
				else y++;
			}
			else if(s[K]=='L'){
				if(check(x-1, y)){
					ans_x = x-1;
					ans_y = y;
					break;
				}
				else x--;
			}
			else if(s[K]=='D'){
				if(check(x, y-1)){
					ans_x = x;
					ans_y = y-1;
					break;
				}
				else y--;
			}
		}
		
		if(ans_x==MXI && ans_y==MXI && check(1e9, 1e9)) cout << 1e9 << ' ' << 1e9 << "\n";
		else if(ans_x==MXI && ans_y==MXI) cout << 0 <<  ' ' << 0 << "\n";
		else cout << ans_x << ' ' << ans_y << "\n";
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
