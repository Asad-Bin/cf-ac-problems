/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;



int main()
{
	long long n, d;
	
	cin >> n >> d;
	
	vector<pair<long long, long long> > ara(n);
	vector<long long> sum(n, 0), ans_sum(n, 0);
	for(long long K = 0; K < n; K++) cin >> ara[K].first >> ara[K].second;
	
	sort(ara.begin(), ara.end());
	//for(auto x:ara) cout << x.first << ' ' << x.second << "\n";
	
	for(long long K = 0; K < n; K++) {
		sum[K] = ara[K].first;// + (K > 0 ? sum[K-1] : 0);
		ans_sum[K] = ara[K].second + (K > 0 ? ans_sum[K-1] : 0);
	}
	
	long long ans = 0;
	
	for(long long K = 0; K < n; K++){
		long long it = upper_bound(sum.begin(), sum.end(), sum[K]+d-1)-sum.begin();
		--it;
		//cout << K << ' ' << sum[K] << ' ' << it << " ";
		
		it = min(it, n-1);
		ans = max(ans, ans_sum[it] - ans_sum[K] + ara[K].second);
		//cout << ans << "\n";
	}
	
	cout << ans << "\n";
	
	return 0;
}
