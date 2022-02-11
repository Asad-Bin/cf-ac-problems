/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


int calc(vector<int> &a, int bit)
{
	if(bit < 0) return 0;
	
	vector<int> l, r;
	for(auto x:a){
		if(((x>>bit)&1) == 0) l.push_back(x);
		else r.push_back(x);
	}
	
	if(l.empty()) return calc(r, bit-1);
	if(r.empty()) return calc(l, bit-1);
	
	return min(calc(l, bit-1), calc(r, bit-1))|(1<<bit);
}
int main()
{
	int n;
	
	cin >> n;
	vector<int> ara(n);
	
	for(int K = 0; K < n; K++) cin >> ara[K];
	
	cout << calc(ara, 30) << "\n";
	
	return 0;
}
