//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 31 05 2020

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

string s;
void bruce(int n)
{
    int one,zero,c_one,c_zero,c_ans,ans;
    c_zero=c_one=one=zero=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')one++;
            else if(s[i]=='0') zero++;
        }
        for(int i=0;i<=n;i++){
            if(i==0) ans=min(one,zero);
            else{
                if(s[i-1]=='0') c_zero++;
                else if(s[i-1]=='1') c_one++;
                c_ans=min(c_zero,c_one)+min(one-c_one,zero-c_zero);
                ans=min(ans,c_ans);
            }
        }
        cout<<ans<< "\n";
}

int ones(int n)
{
    int ans=0,p=0, l=0,f=0;
    for(int K=n-1; K>=0; K--){
        if(s[K]=='1') break;
        l++;
    }
    for(int K=0; K<n; K++){
        if(s[K]=='1') break;
        p++;
    }
    for(int K=0; K<n; K++){
        if(s[K]=='0') ans++;
    }

    return min(ans,(ans-max(p,l)));
}
int zeros(int n)
{
    int ans=0,p=0, l=0,f=0;
    for(int K=n-1; K>=0; K--){
        if(s[K]=='0') break;
        l++;
    }
    for(int K=0; K<n; K++){
        if(s[K]=='0') break;
        p++;
    }
    for(int K=0; K<n; K++){
        if(s[K]=='1') ans++;
    }

    return min(ans,(ans-max(p,l)));
}

void task()
{
    //code here...

    int t;

    cin >> t;
    while(t--){
        cin >> s;
        int n = s.length();
        bruce(n);
    }
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

