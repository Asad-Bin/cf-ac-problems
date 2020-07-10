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
    return (a*b/gcd(a, b));
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
    
    string a, b;
    
    cin >> a >> b;
    int len_a = a.length(), len_b = b.length(), num_a[26], num_A[26], num_b[26], num_B[26];
    memset(num_a, 0, sizeof num_a);
    memset(num_A, 0, sizeof num_A);
    memset(num_b, 0, sizeof num_b);
    memset(num_B, 0, sizeof num_B);
    
    for(int K=0; K<len_a; K++){
		if(a[K]>='a' && a[K]<='z') num_a[a[K]-'a']++;
		else num_A[a[K]-'A']++;
	}
	for(int K=0; K<len_b; K++){
		if(b[K]>='a' && b[K]<='z') num_b[b[K]-'a']++;
		else num_B[b[K]-'A']++;
	}
	
	int mid, ans1=0, ans2=0;
	for(int K=0; K<26; K++){
		mid = min(num_a[K], num_b[K]);
		num_a[K] -= mid;
		num_b[K] -= mid;
		ans1 += mid;
		
		mid = min(num_A[K], num_B[K]);
		num_A[K] -= mid;
		num_B[K] -= mid;
		ans1 += mid;
	}
	
	for(int K=0; K<26; K++){
		mid = min(num_a[K], num_B[K]);
		num_a[K] -= mid;
		num_B[K] -= mid;
		ans2 += mid;
		
		mid = min(num_A[K], num_b[K]);
		num_A[K] -= mid;
		num_b[K] -= mid;
		ans2 += mid;
	}
	
	cout << ans1 << ' ' << ans2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}


