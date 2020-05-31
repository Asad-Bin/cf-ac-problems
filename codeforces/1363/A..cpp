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

void bruce()
{
    cout << "\nExpected answer:\n";
    cout << "\nAnswer recieved:\n";
}

void task()
{
    //code here...

    int t, n, x, l;

    cin >> t;
    while(t--){
        cin >> n >> x;

        int even=0, odd=0;

        for(int K=0; K<n; K++){
            cin >> l;
            if(l%2==0) even++;
            else odd++;
        }

        if(odd>0){
            odd--;
            x--;
            if(even>=x) cout << "Yes\n";
            else{
                if(odd>=x && x%2==0){
                    cout << "Yes\n";
                    continue;
                }
                x -= even;
                if(odd>=x && x%2==0){
                    cout << "Yes\n";
                }else if(even>0 && odd>x){
                    cout << "Yes\n";
                }
                else cout << "No\n";
            }
        }
        else{
            cout << "No\n";
        }
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

