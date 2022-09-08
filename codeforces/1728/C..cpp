// Create your own template by modifying this file!
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

int red(int x)
{
	int cnt = 0;
	while(x){
		x /= 10;
		cnt++;
	}
	
	return cnt;
}


int main() 
{
	int t;
	cin >> t;
	while(t--){
		int n;cin >> n;
		
		int a[n], b[n];
		map<int, int> mp_a, mp_b;
		priority_queue<int> pq;
		
		for(int K = 0; K < n; K++){
			cin >> a[K];
			mp_a[a[K]]++;
			pq.push(a[K]);
		}
		for(int K = 0; K < n; K++){
			cin >> b[K];
			mp_b[b[K]]++;
			pq.push(b[K]);
		}
		
		int ans = 0;
		while(!pq.empty()){
			int x = pq.top();
			pq.pop();
			
			if(mp_a[x] > mp_b[x]){
				int y = red(x);
				mp_a[y]++;
				mp_a[x]--;
				
				ans++;
				pq.push(y);
			}
			else if(mp_a[x] < mp_b[x]){
				int y = red(x);
				mp_b[y]++;
				mp_b[x]--;
				
				ans++;
				pq.push(y);
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}

