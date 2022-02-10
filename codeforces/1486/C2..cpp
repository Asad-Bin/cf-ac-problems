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
	
	
	
	//int l = 1, r = n;
	//while(l < r){
		//if(r-l+1 == 2){
			//x = num;
			
			//cout << '!' << ' ' << (x==l ? r : l) << endl;
			//break;
		//}
		
		//else if(r-l+1 == 3){
			//int a, b, c;
			//a = b = c = 0;
			
			//x = num;
			
			//if(x == l) a = -1;
			//else if(x == r) c = -1;
			//else b = -1;
			
			//cout << '?' << ' ' << l << ' ' << l+1 << endl;
			//cin >> x;
			
			//if(x == l) a = -1;
			//else b = -1;
			
			////if(a==-1 && b==-1){
				////cout << '!' << ' ' << r << "\n";
				////break;
			////}
			////else if(a==-1 && c==-1){
				////cout << '!' << ' ' << l+1 << "\n";
				////break;
			////}
			////else if(b==-1 && c==-1){
				////cout << '!' << ' ' << l << "\n";
				////break;
			////}
			
			//cout << '?' << ' ' << l+1 << ' ' << r << endl;
			//cin >> x;
			
			//if(x == r) c = -1;
			//else b = -1;
			
			//if(a == 0) cout << '!' << ' ' << l << "\n";
			//else if(b == 0) cout << '!' << ' ' << l+1 << "\n";
			//else cout << '!' << ' ' << r << "\n";
			
			//break;
		//}
		
		//int mid = (l+r)/2;
		
		
		//if(num <= mid){
			//cout << '?' << ' ' << l << ' ' << mid << endl;
			//cin >> x;
			
			//if(num == x){
				//r = mid;
				//continue;
			//}
			//else{
				//cout << '?' << ' ' << mid+1 << ' ' << r << endl;
				//cin >> y;
				
				//l = mid+1;
				//num = y;
			//}
		//}
		//else{
			//cout << '?' << ' ' << mid+1 << ' ' << r << endl;
			//cin >> y;
			
			//if(num == y){
				//l = mid+1;
			//}
			//else{
				//cout << '?' << ' ' << l << ' ' << mid << endl;
				//cin >> x;
				
				//r = mid;
				//num = x;
			//}
		//}
		
			////cout << '?' << ' ' << l << ' ' << mid << endl;
			////cin >> x;
		
		////if(num == x){
			////r = mid;
			////continue;
		////}
		
			////cout << '?' << ' ' << mid+1 << ' ' << r << endl;
			////cin >> y;
		
		////if(num == y){
			////l = mid+1;
		////}
		////else{
			////if(num <= mid){
				////l = mid+1;
				////num = y;
			////}
			////else{
				////r = mid;
				////num = x;
			////}
		////}
	//}
	
	return 0;
}
