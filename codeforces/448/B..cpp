//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber

#include <bits/stdc++.h>

using namespace std;

// typedefs...
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

// constants...
const double PI = acos(-1);

// defines...
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return ((ll)a*b/(ll)gcd(a, b));
}
ll comb(ll a, ll b)
{
    ll x = max(a-b, b), ans=1;

    for(ll K=a, L=1; K>=x+1; K--, L++){
        ans *= K;
        ans /= L;
    }

    return ans;
}
 
 
void task()
{
    //code here...
    
    int len_a, len_b;
    string a, b;
    
    cin >> a >> b;
    
    len_a = a.length();
    len_b = b.length();
    
    /*if(len_a<len_b){
		string x = a;
		a = b;
		b = x;
		swap(len_a, len_b);
	}*/
	
	if(len_a==len_b){
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		if(a==b) cout << "array\n";
		else cout << "need tree\n";
	}
	else{
		/*bool f = 0;
		for(int K=0; K<len_a-len_b; K++){
			cout << a.substr(K, len_b) << "#" << "\n";
			if(b==a.substr(K, len_b)){
				f = 1;
				break;
			}
		}
		
		//*/
		
		string s = a, t = b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		int p = len_a;
		for(int K=0, L=0; L<p; K++, L++){
			if(b[K]!=a[L]){
				a.erase(L, 1);
				L--;
				p--;
				K--;
			}
		}
		
		//cout << a << ' ' << b << "\n";
		
		if(a==b){
			int K=0, L=0;
			//cout << len_a << ' ' << len_b << "\n";
			for(; K<len_a && L<len_b; K++){
				if(s[K]==t[L]) L++;
				//cout << s[K] << ' ' << t[L] << "\n";
			}
			
			//cout << len_b << ' ' << L << "\n";
			if(len_b==L) cout << "automaton\n";
			else cout << "both\n";
		}
		else cout << "need tree\n";
	}
}
 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

