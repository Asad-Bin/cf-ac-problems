//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 06 06 2020

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

void bruce()
{
    cout << "\nExpected answer:\n";
    cout << "\nAnswer recieved:\n";
}

void task()
{
    //code here...

    int t, a, b, c;

    cin >> t;
    while(t--){
        cin >> a >> b >> c;

        int ans=0;

        if(a>=1){
            ans++;
            a--;
        }
        if(b>=1){
            ans++;
            b--;
        }
        if(c>=1){
            ans++;
            c--;
        }
        if((a==1 && b==1) || (a==1 && c==1) || (b==1 && c==1)){
            if(a>1){
                ans+=2;
                a-=2;
                b--;
                c--;
            }
            if(b>1){
                ans+=2;
                a--;
                c--;
            }
            if(c>1){
                ans+=2;
                a--;
                b--;
            }
        }
        if(a>=1 && b>=1){
            ans++;
            a--;
            b--;
        }
        if(a>=1 && c>=1){
            ans++;
            a--;
            c--;
        }
        if(b>=1 && c>=1){
            ans++;
            b--;
            c--;
        }
        if(a>=1 && b>=1 && c>=1){
            ans++;
        }

        cout << ans << "\n";
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

