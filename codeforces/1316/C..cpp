// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


//using cd = complex<double>;
//const double PI = acos(-1);

//void fft(vector<cd> & a, bool invert) {
    //ll n = a.size();
    //if (n == 1)
        //return;

    //vector<cd> a0(n / 2), a1(n / 2);
    //for (ll i = 0; 2 * i < n; i++) {
        //a0[i] = a[2*i];
        //a1[i] = a[2*i+1];
    //}
    //fft(a0, invert);
    //fft(a1, invert);

    //double ang = 2 * PI / n * (invert ? -1 : 1);
    //cd w(1), wn(cos(ang), sin(ang));
    //for (ll i = 0; 2 * i < n; i++) {
        //a[i] = a0[i] + w * a1[i];
        //a[i + n/2] = a0[i] - w * a1[i];
        //if (invert) {
            //a[i] /= 2;
            //a[i + n/2] /= 2;
        //}
        //w *= wn;
    //}
//}


//vector<ll> v;
//void multiply(vector<ll> const& a, vector<ll> const& b) {
    //vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    //ll n = 1;
    //while (n < (ll)a.size() + (ll)b.size()) 
        //n <<= 1LL;
    //fa.resize(n);
    //fb.resize(n);

    //fft(fa, false);
    //fft(fb, false);
    //for (ll i = 0; i < n; i++)
        //fa[i] *= fb[i];
    //fft(fa, true);

    ////vector<ll> v(n);
	//v.resize(n);
    //for (ll i = 0; i < n; i++)
        //v[i] = round(fa[i].real());
//}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n, m, p; cin>> n >> m >> p;
	vector<ll> a(n), b(m);
	for(ll K = 0; K < n; K++) cin >> a[K];
	for(ll K = 0; K< m; K++) cin >> b[K];
	
	int ans = 0;
	for(int K = 0; K < n; K++){
		if(a[K] % p != 0) {
			ans = K;
			break;
		}
	}
	for(int K = 0; K < m; K++){
		if(b[K] % p != 0){
			ans += K;
			break;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}





































