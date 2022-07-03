// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';


bool cmp(pair<int, int> A, pair<int, int> B)
{
	return A.second-A.first < B.second-B.first;
}
int main()
{
	int n, a = 0, b = 0;
	
	cin >> n;
	int ara[n];
	
	for(int K = 0; K < n; K++){
		cin >> ara[K];
		if(ara[K]&1) b++;
		else if(ara[K]) a++;
	}
	a = n/2-a;
	b = (n+1)/2-b;
	
	//debug(a);
	//debug(b);
	
	vector<pair<int, int> > even, odd, mis;
	
	int i = 0, j = n-1;
	bool f = 0;
	
	for(int K = 0; K < n; K++){
		i = K;
		if(ara[K] > 0){
			f = 1;
			//if(K){
				//if(ara[K]%2==0) even.push_back({0, K-1});
				//else odd.push_back({0, K-1});
			//}
			
			break;
		}
	}
	
	if(!f){
		if(n > 1) cout << 1 << "\n";
		else cout << 0 << "\n";
		
		return 0;
	}
	
	for(int K = n-1; K >= 0; K--){
		j = K;
		if(ara[K] > 0){
			//if(K < n-1){
				//if(ara[K]%2==0) even.push_back({K+1, n-1});
				//else odd.push_back({K+1, n-1});
			//}
			
			break;
		}
	}
	
	for(int K = i; K <= j; K++){
		if(ara[K] == 0){
			int l = K;
			for(int L = K+1; L < n; L++){
				if(ara[L]) break;
				l = L;
			}
			
			if(ara[K-1]%2 == ara[l+1]%2){
				if(ara[K-1]%2==0) even.push_back({K, l});
				else odd.push_back({K, l});
			}
			else{
				mis.push_back({K, l});
			}
			
			//debug(K);
			//debug(l);
			K = l;
		}
	}
	
	sort(even.begin(), even.end(), cmp);
	sort(odd.begin(), odd.end(), cmp);
	
	//for(auto x:even) cout << x.first << ' ' << x.second << "\n";
	//for(auto x:odd) cout << x.first << ' ' << x.second << "\n";
	
	int ans = 0;
	for(int K = 0; K < (int)even.size(); K++){
		if(even[K].second-even[K].first+1 <= a){
			a -= even[K].second-even[K].first+1;
		}
		else{
			if(even[K].first == 0 || even[K].second == n-1) ans++;
			else ans += 2;
		}
	}
	for(int K = 0; K < (int)odd.size(); K++){
		if(odd[K].second-odd[K].first+1 <= b){
			b -= odd[K].second-odd[K].first+1;
		}
		else{
			if(odd[K].first == 0 || odd[K].second == n-1) ans++;
			else ans += 2;
		}
	}
	//debug(ans);
	
	if(i < n-j-1){
		if(ara[i]%2==0 && i && i <= a){
			a -= i;
		}
		else if(ara[i]%2==1 && i && i <= b){
			b -= i;
		}
		else if(i) ans++;
		
		if(ara[j]%2==0 && n-1-j && n-1-j <= a){
			a -= n-1-j;
		}
		else if(ara[j]%2==1 && n-1-j && n-1-j <= b){
			b -= n-1-j;
		}
		else if(n-1-j) ans++;
	}
	else{
		if(ara[j]%2==0 && n-1-j && n-1-j <= a){
			a -= n-1-j;
		}
		else if(ara[j]%2==1 && n-1-j && n-1-j <= b){
			b -= n-1-j;
		}
		else if(n-1-j) ans++;
		
		if(ara[i]%2==0 && i && i <= a){
			a -= i;
		}
		else if(ara[i]%2==1 && i && i <= b){
			b -= i;
		}
		else if(i) ans++;
	}
	//debug(ans);
	
	ans += (int)mis.size();
	
	for(int K = 0; K < n-1; K++){
		if(ara[K] && ara[K+1] && ara[K]%2 != ara[K+1]%2) ans++;
	}
	
	cout << ans << "\n";
	
	return 0;
}




















































