// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif

const int MX = 1e5;   // query size . . .
const int MXI = 2e6;  // maximum value in array . . .
ll cnt[MXI+5];
int ara[MX+5];
ll v[MX+5];

int block_size;
ll range_ans = 0;

struct Query{
    int id, l, r;
    
    bool operator<(Query &other) const{
        int curr_size = l/block_size;
        int other_size = other.l/block_size;
        
        if(curr_size == other_size) return r < other.r;
        return curr_size < other_size;
    }
};

Query query[MX+5];


int k;
//void add(int val)
//{
	//cnt[val]++;
	//range_ans += cnt[val^k];
//}
//void rmv(int val)
//{
	//range_ans -= cnt[val^k];
	//cnt[val]--;
//}
//int get_solution()
//{
	//return range_ans;
//}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m >> k ;
	
	block_size = 340;
	
	for (int K = 0; K < n; K++) {cin >> ara[K]; ara[K] =  (K ? ara[K-1] : 0) ^ ara[K];}
	
	for(int i = 0; i < m; i++){
		cin >> query[i].l >> query[i].r;
		
		query[i].l--;
		query[i].r--;
		
		query[i].id = i;
	}
	
	sort(query, query+m);
	
	
	int L = 0, R = -1;
	
	for(int K = 0; K < m; K++){
        int l = query[K].l;
        int r = query[K].r;
        
        while(L+1 < l){
			if(L >= 0){
				cnt[ara[L]]--;
				range_ans -= cnt[ara[L]^k];
			}
			else{
				cnt[0]--;
				range_ans -= cnt[k];
			}
			
            //rmv(ara[L]);
            L++;
            //cout << L << ' ' << R << ' ' << range_ans << "\n";
        }
        while(L+1 > l){
            L--;
            //add(ara[L]);
            
            if(L < 0){
				range_ans += cnt[k];
				cnt[0]++;
			}
			else{
				range_ans += cnt[ara[L]^k];
				cnt[ara[L]]++;
			}
           // cout << L << ' ' << R << ' ' << range_ans << "\n";
        }
        while(R < r){
            R++;
            //add(ara[R]);
            
			range_ans += cnt[ara[R]^k];
			cnt[ara[R]]++;
            //cout << L << ' ' << R << ' ' << range_ans << "\n";
        }
        while(R > r){
            //rmv(ara[R]);
            
			cnt[ara[R]]--;
			range_ans -= cnt[ara[R]^k];
            R--;
            //cout << L << ' ' << R << ' ' << range_ans << "\n";
        }
        
        v[query[K].id] = range_ans;//get_solution();
    }
    
    for(int K = 0; K < m; K++) cout << v[K] << "\n";
	
	
	return 0;
}
