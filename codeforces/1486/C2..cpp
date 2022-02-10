/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


int check(int l, int r)
{
	if(l >= r) return -1;
	
	int x;
	cout << '?' << ' ' << l << ' ' << r << endl;
	cin >> x;
	
	return x;
}
int main()
{
	int n, num;
	
	cin >> n;
	
	cout << '?' << ' ' << 1 << ' ' << n << endl;
	cin >> num;
	
	
	if(num == 1 || check(1, num) != num){
		; //right
		
		int l = num, r = n;
		
		while(l+1 < r){
			int mid = (l+r)/2;
			
			if(check(num, mid) == num){
				r = mid;
			}
			else{
				l = mid;
			}
		}
		cout << '!' << ' ' << r << "\n";
	}
	else{
		; //left
		
		int l = 1, r = num;
		
		while(l+1 < r){
			int mid = (l+r)/2;
			
			if(check(mid, num) == num){
				l = mid;
			}
			else{
				r = mid;
			}
		}
		cout << '!' << ' ' << l << "\n";
	}
	
	
	return 0;
}
