//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 20 06 2020

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
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

int gcd (int a, int b) {
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


void bruce()
{
    cout << "\nExpected answer:\n";
    cout << "\nAnswer recieved:\n";
}

void task()
{
    //code here...

    int t, n;

    cin >> t;
    while(t--){
        cin >> n;

        //vi ara(2*n);
        int ara[2*n];
        vector<bool> mark(2*n+1);

        int even=0, odd=0;
        bool f=0, g=0;
        for(int K=0; K<2*n; K++){
            cin >> ara[K];
            if(ara[K]%2==1) odd++;
            else even++;
        }

        if(odd!=0 && odd%2==1){
            for(int K=0; K<2*n; K++){
                if(!g && ara[K]%2==1){
                    //ara.erase(ara.begin()+K);
                    mark[K+1] = 1;
                    g = 1;
                    //K--;
                }
                if(!f && ara[K]%2==0){
                    //ara.erase(ara.begin()+K);
                    mark[K+1] = 1;
                    //K--;
                    f = 1;
                }
                if(f && g) break;
            }
        }
        else{
            f = 0;
            for(int K=1; K<2*n; K++){
                if(ara[K]%2==ara[0]%2){
                    //ara.erase(ara.begin()+K);
                    mark[K+1] = 1;
                    f = 1;
                    break;
                }
            }

            if(!f){
                for(int K=2; K<2*n; K++){
                    if(ara[K]%2==ara[1]%2){
                    //ara.erase(ara.begin()+K);
                        mark[K+1] = 1;
                        f = 1;
                        break;
                    }
                }
                mark[2] = 1;
            }
            else mark[1] = 1;
            //ara.erase(ara.begin());
        }

        //for(int K=0; K<ara.size(); K++) cout << ara[K] << ' ';
        //cout << "\n";
        for(int K=0; K<2*n; K++){
            if(mark[K+1]) continue;
            cout << K+1 << ' ';
            for(int L=K+1; L<2*n; L++){
                if(!mark[L+1] && ara[L]%2==ara[K]%2){
                    cout << L+1 << "\n";
                    //ara.erase(ara.begin()+L);
                    mark[L+1] = 1;
                    //cout << t << ' ' << "hi\n";
                    break;
                }
            }
            //ara.erase(ara.begin()+K);
            //K--;
            mark[K+1] = 1;
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

