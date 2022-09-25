// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif

int kmp_search(int n, const vector<int> &s, int m, const vector<int> &p, const vector<int> &v)
{
	vector<int> res;
	
	int j = 0;
	for(int K = 0; K < n; K++){
		while(j > 0 && (j == m || s[K] != p[j])){
			j = v[j-1];
		}
		if(s[K] == p[j]) j++;
		
		if(j == m) res.push_back(K-m+1);
	}
	
	return (int)res.size();
}

vector<int> prefix_function(int n, const vector<int> &s)
{
	vector<int> p(n, 0);
	
	int j = 0;
	for(int K = 1; K < n; K++){
		while(j > 0 && s[K] != s[j]){
			j = p[j-1];
		}
		if(s[K] == s[j]) j++;
		
		p[K] = j;
	}
	
	return p;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	
	cin >> n >> m;
	
	vector<int> s(n), t(m);
	for(int K = 0; K < n; K++) cin >> s[K];
	for(int K = 0; K < n-1; K++) s[K] = s[K]-s[K+1];
	for(int K = 0; K < m; K++) cin >> t[K];
	for(int K = 0; K < m-1; K++) t[K] = t[K] - t[K+1];
	
	if(m ==1){
		cout << n << endl;
		return 0;
	}
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	
	s.pop_back();
	t.pop_back();
	
	cout << kmp_search(n-1, s, m-1, t, prefix_function(m-1, t)) << "\n";
	
	return 0;
}





































