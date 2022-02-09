/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


long long gcd(long long a, long long b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
	return a/gcd(a, b)*b;
}
int main()
{
	long long n, p, w, d;
	
	
	cin >> n >> p >> w >> d;
	
	for(long long K = 0; K < w; K++){
		long long mid = p - K*d;
		
		if(mid >= 0 && mid%w == 0 && mid/w+K <= n){
			cout << mid/w << ' ' << K << ' ' << n-mid/w-K << "\n";
			return 0;
		}
	}
	
	//long long x = w*d; //lcm(w, d);
	
	//long long ans = p / x;
	//ans *= (x/w);
	//p %= x;
	
	////cout << x << ' ' << ans << ' ' << p << "\n";
	
	//while(ans >= 0){
		//long long i = 0;
		////cout << i+ans+(p - i*w)/d << "\n";
		//while(i*w <= p && i+ans <= n){
			//long long mid = p - i*w;
			
			////if(i+ans+mid/d > n) continue;
			
			////cout << "hi\n";
			////cout << i*w << ' ' << mid << "\n";
			//if(mid%d == 0 && i+ans+mid/d <= n){
				//cout << i+ans << ' ' << mid/d << ' ' << n-i-ans-(mid/d);
				//return 0;
			//}
			
			//i++;
		//}
		
		//ans -= x/w;
		//p += x;
	//}
	
	cout << "-1\n";
	
	return 0;
}
