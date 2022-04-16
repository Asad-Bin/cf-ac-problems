/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


const int MX = 1e5;
long long ara[MX+5];
map<long long, int> mp, smp;

int main()
{
	long long n, pre = 0, suf = 0, mid;
	
	cin >> n;
	for(int K = 0; K < n; K++){
		cin >> ara[K];
		suf += ara[K];
		smp[ara[K]]++;
	}
	
	for(int K = 0; K < n-1; K++){
		pre += ara[K];
		suf -= ara[K];
		mp[ara[K]]++;
		smp[ara[K]]--;
		//cout << K << ' ' << pre << ' ' << suf << ' ' << suf-pre << ' ' << smp[(suf-pre)/2] << "\n";
		
		if(pre == suf){
			cout << "YES\n";
			return 0;
		}
		else if(pre > suf){
			mid = pre - suf;
			
			if(!(mid&1LL) && mp[mid/2]){
				cout << "YES\n";
				return 0;
			}
			
			if(!(mid&1LL) && mp[ara[K+1]+mid/2]){
				cout << "YES\n";
				return 0;
			}
			else if(!(mid&1LL) && smp[ara[K]-mid/2]){
				cout << "YES\n";
				return 0;
			}
		}
		else{
			mid = suf - pre;
			
			if(!(mid&1LL) && smp[mid/2]){
				cout << "YES\n";
				return 0;
			}
			
			if(!(mid&1LL) && mp[ara[K+1]-mid/2]){
				cout << "YES\n";
				return 0;
			}
			else if(!(mid&1LL) && smp[ara[K]+mid/2]){
				cout << "YES\n";
				return 0;
			}
		}
	}
	
	cout << "NO\n";
	
	return 0;
}












