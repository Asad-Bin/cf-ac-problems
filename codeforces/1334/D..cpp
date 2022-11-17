// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg_out cout
#define debug(...) dbg_out << "DBG )> "; __f(#__VA_ARGS__, __VA_ARGS__);
template<typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2> pr) { out << "{ " << pr.first << ", " << pr.second << " }"; return out; }
template<typename T1> ostream& operator<<(ostream& out, vector<T1> vec) { out << "{ "; for (auto &x: vec) out << x << ", "; out << "}"; return out; }
template<typename T1, size_t size> ostream& operator<<(ostream& out, array<T1, size> arr) { out << "{ "; for (auto &x: arr) out << x << ", "; out << "}"; return out; }
template<typename T1, typename T2> ostream& operator<<(ostream& out, map<T1, T2> mp) { out << "{ ";for (auto &x: mp) out << x.first << ": " << x.second <<  ", "; out << "}"; return out; }
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { while (isspace(name[0])) name++; (isalpha(name[0]) || name[0] == '_') ? dbg_out << name << ": " << arg1 << "\n" : dbg_out << arg1 << "\n"; dbg_out.flush();}
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) { const char *comma = strchr(names + 1, ','); while (isspace(names[0])) names++; (isalpha(names[0]) || names[0] == '_') ? dbg_out.write(names, comma - names) << ": " << arg1 << " | " : dbg_out << arg1 << " | "; __f(comma + 1, args...);}
#else
#define debug(...)
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

const int N = 1e5;
//ll ara[N+5];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	//ara[0] = 0;
	//ara[1] = 0;
	//ara[2] = 2;
	//ll i = 4;
	//for(int K = 2; K <= N; K++){
		//ara[K] = i;
		////i *= 2;
	//}
	
	ll t; cin >> t;
	while(t--){
		ll n, l, r; cin >> n >> l >> r;
		
		//ll it = lower_bound(ara, ara+n, l) - ara;
		//debug(it);
		vector<ll> v;
		
		ll i = 2;
		if(1 >= l && 1 <= r) v.push_back(1);
		for(int K = 2; K < n; K++){
			if(i >= l && i <= r) v.push_back(K);
			if(i+1 >= l && i+1 <= r) v.push_back(1);
			i += 2;
		}
		//debug(i);
		//debug(v);
		
		if(i >= l && i <= r){
			v.push_back(n);
		}
		i++;
		for(ll K = 2; K < n; K++){
			ll val = (n-1-K)*2;
			
			if(i >= l && i <= r){
				v.push_back(K);
			}
			i++;
			
			
			if(i+val+1 < l){
			//debug(i) debug(val)
				i += val + 1;
				continue;
			}
			
			//debug(i) debug(v);
			
			for(int L = K+1; L < n; L++){
				if(i > r) break;
				if(i >= l){
					v.push_back(L);
				}
					i++;
				if(i > r) break;
				if(i >= l){
					v.push_back(K);
				}
					i++;
			}
			
			if(i >= l && i <= r){
				v.push_back(n);
			}
			i++;
			if(i > r) break;
		}
		//if(i >= l && i <= r) v.push_back(n);
		//i++;
		if(i >= l && i <= r) v.push_back(1);
		
		//i = ara[it-1] + 1;
		//vector<ll> v;
		//if(i > r) break;
		//if(i >= l && i == 1){
			//v.push_back(1);
			//i++;
		//}
		//while(it < N){
			//if(it == 1){
				//it++;
				//continue;
			//}
			
			////debug(i) debug(it)
			////debug(v);
			//if(i > r) break;
			//if(i >= l && i == ara[it-1]+1) v.push_back(it);
			//i++;
			
			//for(int K = 2; K < it; K++){
				//if(i > r || i > ara[it]) break;
				//if(i >= l) v.push_back(K);
				//i++;
				
				//if(i > r || i > ara[it]) break;
				//if(i >= l) v.push_back(it);
				//i++;
			//}
			//if(i > r) break;
			//if(i >= l) v.push_back(1);
			//i++;
			
			////debug(i) debug(it);
			////debug(v);
			
			//++it;
		//}
		
		for(auto x:v) cout << x << ' ';
		cout << "\n";
	}
	
	return 0;
}





/*
 
5
3 1 7
3 1 6
3 2 6
3 3 6
3 4 6

*/































