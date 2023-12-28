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
//#define int long long

//const int INF = 1e9;
//const int MOD = 1e9 + 7;
//const ld EPS = 1e-18;
//const ld PI = acos(-1.0); 
string s[3];
vector<pair<int,int>> pos[3];
char pagla(int x , int y , int ix , int iy){
	pair<int,int> pp;
	char t = 'C';
	for(int i = -1; i <= 1; i++){
			for(int j = -1; j <= 1; j++){
				if((x + i < 3) && (x + i >= 0) && (y + j < 3) && (y + j >= 0)){
					// cout << x + i << ' ' << y + j << ' ' << x << ' ' << y << endl;
					if(i == 0 && j == 0) continue;
					if(x + i == ix && y + j == iy) continue;
					if(s[x + i][y + j] < t){
						pp.first = x + i;
						pp.second = y + i;
						t = s[x + i][y + j];
					}
				}
			}
		}
	return t;
}
string ken(int k){
	string ans = "CCC";
	for(auto [x , y] : pos[k]){
		string temp;
		if(k == 0) temp = "A";
		else temp = "B";
		char t = 'C';
		pair<int,int> pp;
		vector<pair<int,int>> lst;
		for(int i = -1; i <= 1; i++){
			for(int j = -1; j <= 1; j++){
				if((x + i < 3) && (x + i >= 0) && (y + j >= 0) && (y + j < 3)){
					if(i == 0 && j == 0) continue;
					if(s[x + i][y + j] < t){
						lst.clear();
						lst.pb({x + i , y + j});						
						t = s[x + i][y + j];
					}
					else if(s[x + i][y + j] <= t){
						lst.pb({x + i , y + j});						
						t = s[x + i][y + j];
					}
				}
			}
		}
		temp.pb(t);
		// cout << temp << ' ';
		t = 'C';
		int ix = x;
		int iy = y;
		for(auto [m , n] : lst){
			t = min(t , pagla(m , n , ix , iy));
		}
		temp.pb(t);
		// cout << temp << endl;
		ans = min(ans , temp);
	}
	return ans;
}

void GG()
{
	
	for(int i = 0; i < 3; i++) cin >> s[i];
	
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(s[i][j] == 'A') pos[0].pb({i , j});
			else if(s[i][j] == 'B') pos[1].pb({i , j});
			else pos[2].pb({i , j});
		}
	}
	
	string ans = "CCC";
	if(pos[0].size() != 0) ans = ken(0);
	else if(pos[1].size() != 0) ans = ken(1);
	cout << ans << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ttc=1;
	// cin>>ttc;
	//int cnt=0;
	while(ttc--)
	{
		//cout<<"Case "<<++cnt<<": ";
		GG();
	}
}