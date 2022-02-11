/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const int MX = 500;
string s[MX+5];
int n, m;

bool dfs(pair<int, int> u, pair<int, int> dest)
{
	for(int K = 0; K < 4; K++){
		int x, y;
		x = u.first+dx[K];
		y = u.second+dy[K];
		
		if(0 <= x && x < n && 0 <= y && y < m){
			if(make_pair(x, y) == dest && s[x][y] == 'X') return true;
			
			if(s[x][y] == 'X') continue;
			
			s[x][y] = 'X';
			if(dfs({x, y}, dest)) return true;
		}
	}
	
	return false;
}

int main()
{
	cin >> n >> m;
	
	for(int K = 0; K < n; K++) cin >> s[K];
	
	int x, y, a, b;
	cin >> x >> y;
	cin >> a >> b;
	
	if(dfs({x-1, y-1}, {a-1, b-1})) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}
