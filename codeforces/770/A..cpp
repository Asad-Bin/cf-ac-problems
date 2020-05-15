//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 15 05 2020

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
    int n, k;

    cin >> n >> k;
    char s[n+1];

    int mid = n - k + 1;
    for(int K=0; K<n; K++) s[K] = '1';
    for(int K=0; K<n; K+=2){
        if(mid==0 && s[K]=='1') break;
        s[K] = 'a';
        mid--;
    }
    mid++;
    for(int K=1; K<n; K+=2){
        if(mid==0 && s[K]=='1') break;
        s[K] = 'b';
        mid--;
    }

    int i = 2;
    for(int K=0; K<n; K++){
        if(s[K]=='1'){
            s[K] = 'a' + i;
            i++;
        }
    }
    s[n] = '\0';

    printf("%s\n", s);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
