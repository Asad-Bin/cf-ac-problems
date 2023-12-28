#include<bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;
//typedef long long int;

#define endl "\n"
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define int long long

//const int INF = 1e9;
//const int MOD = 1e9 + 7;
//const ld EPS = 1e-18;
//const ld PI = acos(-1.0); 
int n;
int dp[2009][2009];
set<int> st;
bool laga_dp(int ind , int sz , vector<int> &ln, int sum){
	if(sum == n){
		return dp[ind][sum] = 1;
	}
	else if(sum > n || sz == ind) return dp[ind][sum] = 0;
	if(dp[ind][sum] != -1) return dp[ind][sum];
	int ret = 0;
	ret |= laga_dp(ind + 1 , sz , ln , sum);
	ret |= laga_dp(ind + 1 , sz , ln , sum + ln[ind]);
	return dp[ind][sum] = ret;
}
void woo(int ind , int sz , vector<int> &ln , vector<vector<int>> &lst , int sum){
	if(ind == sz) return;
	if(dp[ind + 1][sum + ln[ind]] == 1){
		st.insert(ind);
		woo(ind + 1 , sz , ln , lst , sum + ln[ind]);
		return;
	}
	// st.insert(ind);
	woo(ind + 1 , sz , ln , lst, sum);
	return;
}

void GG()
{
	
	cin >> n;
	vector<int> v(2 * n);
	vector<vector<int>> lst;
	vector<int> ln;
	int mxv = -1;
	vector<int> temp;
	for(int i = 0; i < 2 * n; i++){
		cin >> v[i];
		if(v[i] > mxv && mxv != -1){
			ln.pb(temp.size());
			lst.pb(temp);
			mxv = v[i];
			temp.clear();
			temp.pb(v[i]);
		}
		else{
			temp.pb(v[i]);
			mxv = max(mxv , v[i]);
		}
	}

	ln.pb(temp.size());
	lst.pb(temp);

	// cout << ln.size() << endl;
	// for(auto x : ln) cout << x << ' ';
	// 	cout << endl;
	// for(auto x : lst){
	// 	for(auto y : x) cout << y << ' ';
	// 		cout << endl;
	// }

	
	bool ase_naki = laga_dp(0 , ln.size(), ln , 0);
	if(!ase_naki) cout << -1 << endl;
	else{
		vector<int> a , b;
		woo(0 , ln.size(), ln , lst, 0);
		for(int i = 0; i < lst.size(); i++){
			if(st.find(i) == st.end()){
				for(auto x : lst[i]) b.pb(x);
			}
			else for(auto x : lst[i]) a.pb(x);
		}
		for(auto y : b) cout << y << ' ';
			cout << endl;
		for(auto x : a) cout << x << ' ';
			cout << endl;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp , -1 , sizeof dp);
	int ttc=1;
	// cin>>ttc;
	//int cnt=0;
	while(ttc--)
	{
		//cout<<"Case "<<++cnt<<": ";
		GG();
	}
}