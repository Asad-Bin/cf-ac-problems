#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int MX = 1e5;
int n, k;

ll bit[15][MX+5];

ll sum(int x, int y) {
	ll res = 0;
	for (int j = y; j > 0; j = (j & (j + 1)) - 1)
		res += bit[x][j];
	return res;
}
void add(int x, int y, ll delta) {
	for (int j = y; j <= MX; j = j | (j + 1))
		bit[x][j] += delta;
}

int main()
{
	cin >> n >> k;
	
	int x;
	for(int K=0; K<n; K++){
		cin >> x;
		
		add(1, x, 1);
		for(int L=2; L<=k+1; L++){
			add(L, x, sum(L-1, x-1));
		}
	}
	
	cout << sum(k+1, n) << "\n";
	
	return 0;
}