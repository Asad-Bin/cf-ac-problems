//...Bismillahir Rahmanir Rahim...
 
#include <bits/stdc++.h>
using namespace std;
 
// typedefs...
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
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
    size_t operator()(const pair<T1, T2>& p) const{ auto hash1 = hash<T1>{}(p.first); auto hash2 = hash<T2>{}(p.second); return hash1 ^ hash2;} 
};

// functions...
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll comb(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}


int t, a, b;
string s1, s2, s;
bool check2()
{
	string str = s;
	bool ok = 0;
	while((int)str.length()<=b){
		if(str==s2){
			ok = 1;
			break;
		}
		str += s;
	}
	
	return ok;
}
bool check1()
{
	string str = s;
	bool ok = 0;
	while((int)str.length()<=a){
		if(str==s1){
			ok = 1;
			break;
		}
		str += s;
	}
	
	return ok;
}
void task()
{
	// Code here.. ..
	
	cin >> t;
	while(t--){
		cin >> s1 >> s2;
		
		if((int)s1.length()<(int)s2.length()) swap(s1, s2);
		
		a = (int)s1.length();
		b = (int)s2.length();
		
		for(int K=1; K<=b; K++){
			s = s2.substr(0, K);
			
			if(check2()){
				break;
			}
		}
		
		if(check1()==false) cout << "-1\n";
		else{
			string str = "";
			int x = lcm(a/(int)s.length(), b/(int)s.length());
			while(x--) str += s;
			
			cout << str << "\n";
		}
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
