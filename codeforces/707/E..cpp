#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pii pair<int, int>
#define vl vector<long long>
#define PB push_back
#define sz(x) (int)x.size()
#define fi first
#define se second


const int MX = 2e3;
int n, m, k;
bool lit[MX+5];
vector<vector<pair<pii, int> > > v(MX+5);
ll bit[MX+5][MX+5];
ll res[MX+5][MX+5];
vector<pair<pii, pii> > ara;
vector<pair<pii, pii> > query;

void add(int x, int y, ll delta) {
	for (int i = x; i < MX; i = i | (i + 1))
		for (int j = y; j < MX; j = j | (j + 1))
			bit[i][j] += delta;
}

ll sum(int x, int y) {
	if(x < 0 || y < 0) return 0;
	
	ll res = 0;
	for (int i = x; i >=0; i = (i & (i + 1)) - 1)
		for (int j = y; j >=0; j = (j & (j + 1)) - 1)
			res += bit[i][j];
	return res;
}
ll sum(int x1, int y1, int x2, int y2) {
	return sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1);
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	memset(bit, 0LL, sizeof bit);
	
	int len;
	for(int K=0; K<k; K++){ // 1-based
		scanf("%d", &len);
		
		int x, y, w;
		for(int L=0; L<len; L++){
			scanf("%d%d%d", &x, &y, &w);
			v[K].PB({{x-1, y-1}, w});
		}
	}
	
	int q, x1, x2, y1, y2;
	char s[15];
	
	scanf("%d", &q);
	while(q--){
		scanf("%s", s);
		
		if(s[0] == 'A'){
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			ara.PB({{x1-1, y1-1}, {x2-1, y2-1}});
			query.PB({{x1-1, y1-1}, {x2-1, y2-1}});
		}
		else{
			scanf("%d", &x1);
			ara.PB({{-1, x1-1}, {-1, -1}});
		}
	}
	
	for(int K=0; K<k; K++){ // 1-based
		for(int L=0; L<sz(query); L++){ // 0-based // increase eff.
			res[L][K] = -sum(query[L].fi.fi, query[L].fi.se, query[L].se.fi, query[L].se.se);

		}
		for(int L=0; L<sz(v[K]); L++){
			add(v[K][L].fi.fi, v[K][L].fi.se, v[K][L].se);
		}
		for(int L=0; L<sz(query); L++){
			res[L][K] += sum(query[L].fi.fi, query[L].fi.se, query[L].se.fi, query[L].se.se);
		}
	}
	
	ll ans = 0;
	int cnt = 0;
	for(int L=0; L<sz(ara); L++){ // 0-based
		if(ara[L].fi.fi == -1){
			lit[ara[L].fi.se] ^= 1;
		}
		else{
			ans = 0;
			for(int K=0; K<k; K++){ // 1-based
				if(!lit[K]){
					ans += res[cnt][K];
				}
			}
			cnt++;
			
			printf("%lld\n", ans);
		}
	}
	
	return 0;
}














































