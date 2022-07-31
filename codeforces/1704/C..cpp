//. . .Bismillahir Rahmanir Rahim. . .
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';


int main()
{
	int t, n, m;
	vector<int> v;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		int ara[m];
		for(int K = 0; K < m; K++) cin >> ara[K];
		sort(ara, ara+m);
		
		v.clear();
		for(int K = 1; K < m; K++){
			v.push_back(ara[K]-ara[K-1]-1);
		}
		if(ara[0] == 1 && ara[m-1] == n){}
		else v.push_back(ara[0]-1+n-ara[m-1]);
		sort(v.begin(), v.end());
		
		//cout<< "v = ";
		//for(auto it:v) cout << it << ' ' ;
		//cout << "\n";
		
		int time = 0, cnt = 0;
		for(int K = v.size()-1; K >= 0; K--){
			v[K] -= time;
			if(v[K] <= 0) continue;
			
			if(v[K] == 1){
				cnt++;
				time += 2;
				continue;
			}
			v[K]--;
			cnt += v[K];
			time += 4;
		}
		
		//cout << "ans" << " = ";
		cout << n-cnt << "\n";
	}
	
    return 0;
}























