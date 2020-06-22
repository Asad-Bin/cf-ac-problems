//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 22 06 2020

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


vector<int> primes;
vector<int> mark(100002);
void sieve()
{
    int n = 1e5+1;
    int i, j, limit = sqrt(n*1.) + 2;

    mark[1] = 1;

    for(i = 4; i<=n; i+=2) mark[i] = 1;

    primes.push_back(2);

    for(i = 3; i <= n; i += 2)
    {
        if(!mark[i])
        {
            primes.push_back(i);

            if(i<=limit)
            {
                for(j = i*i; j <= n; j += i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}

void task()
{
    //code here...

    int t, n;

    sieve();

    cin >> t;
    while(t--){
        cin >> n;

        if(n==1) cout << "FastestFinger\n";
        else if(n==2) cout << "Ashishgup\n";
        else if(n%2==1) cout << "Ashishgup\n";
        else{
            int i = 0, cnto=0, cnt2=0;
            while(1){
                if(i>=primes.size()){
                    cnto++;
                    break;
                }
                if(n%primes[i]==0){
                    if(i==0) cnt2++;
                    else cnto++;

                    n /= primes[i];
                }
                else{
                    i++;
                }

                if(n==1) break;
            }

            bool f = 0;
            if(cnto==1 && cnt2==1){
                f = f ^ 1;
                if(f) cout << "FastestFinger\n";
                else cout << "Ashishgup\n";
                continue;
            }
            else if(cnto>1 && cnt2==1){
                if(f) cout << "FastestFinger\n";
                else cout << "Ashishgup\n";
                continue;
            }
            if(cnto>0){
                f = f^1;
            }
            if(cnt2>1){
                f = f^1;
            }

            if(f) cout << "FastestFinger\n";
            else cout << "Ashishgup\n";
        }
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

