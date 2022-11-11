// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


const int N = 1e5;
vector<int> ara[N+5];
int ans = 0;

bool find_min(int u, int p , int h, bool f)
{
	if((int)ara[u].size() == 1 && u != 1){
		if(h%2==1 && h > 1 && f) ans = 3;
		
		return 1;
	}
	
	int odd = 0, eve = 0;
	for(int K = 0; K < (int)ara[u].size(); K++){
		if(ara[u][K] != p){
			bool ok = find_min(ara[u][K], u, h+1, f);
			if(ok) odd++;
			else eve++;	
		}
	}
	
	if(odd == 0 || eve == 0) {}
	else ans = 3;
	
	return (odd ? 0 : 1);
}

vector<int> par[N+5];
void find_max(int u, int p, int h, bool f)
{
	if((int)ara[u].size() == 1 && u != 1){
		if(h == 2 && f) ans--;
		else par[p].push_back(h);
		
		return;
	}
	
	for(int K = 0; K < (int)ara[u].size(); K++){
		if(ara[u][K] != p){
			find_max(ara[u][K], u, h+1, f);
		}
	}
	
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	int a, b;
	for(int K = 1; K < n; K++){
		cin >> a >> b;
		ara[a].push_back(b);
		ara[b].push_back(a);
	}
	
	ans = 1;
	find_min(1, 1, 0, ((int)ara[1].size()==1));
	cout << ans << ' ';
	
	ans = n-1;
	find_max(1, 1, 0, ((int)ara[1].size() == 1));
	for(int K = 1; K <= n; K++){
		sort(par[K].begin(), par[K].end());
		for(int L = 1; L < (int)par[K].size(); L++){
			if(par[K][L] == par[K][L-1]){
				ans--;
			}
		}
	}
	cout << ans << "\n";
	
	return 0;
}





































