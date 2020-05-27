//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 27 05 2020

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
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b))
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)


void task()
{
    //code here...
    string str;
    int n, s=-1, t=-1;

    cin >> n >> str;

    for(int K=0; K<n; K++){
        if(str[K]=='R' && s==-1){
            s = K + 1;
        }
        if(str[K]=='R' && (K==n-1 || str[K+1]=='.') && t==-1){
            t = K + 2;
        }
        if(str[K]=='L' && (K==n-1 || str[K+1]=='.') && s==-1){
            s = K+1;
        }
        if(str[K]=='L' && t==-1){
            t = K;
        }
    }

    cout << s << ' ' << t << "\n";
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

