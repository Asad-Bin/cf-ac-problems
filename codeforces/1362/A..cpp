//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 04 06 2020

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

    ll t, a, b;

    cin >> t;
    while(t--){
        cin >> a >> b;

        vector<int> ara(9);
        ll ans = 0;

        if(a==b){
            ans = 0;
        }
        else if(a<b){
            while(1){
                a *= 2;
                ara[2]++;
                if(a>b){
                    ans = -1;
                    break;
                }
                else if(a==b){
                    ll mid = ara[2]%3;
                    ara[8] = (int)ara[2]/3;
                    ara[2] = mid%2;
                    ara[4] = mid/2;
                    ans = ara[2] + ara[4] + ara[8];
                    break;
                }
            }
        }
        else{
            while(1){
                if(a%2!=0){
                    ans = -1;
                    break;
                }
                a /= 2;
                ara[2]++;
                //cout << a << ' ' << b << ' ' << ara[2] << "\n";
                if(a<b){
                    ans = -1;
                    break;
                }
                else if(a==b){
                    ll mid = ara[2]%3;
                    ara[8] = (int)ara[2]/3;
                    ara[2] = mid%2;
                    ara[4] = mid/2;
                    ans = ara[2] + ara[4] + ara[8];
                    break;
                }
            }
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

