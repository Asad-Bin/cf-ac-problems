//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 05 05 2020

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


vector<int> prime;
vector<bool> mark(102);
vector<int> factorial(11);

void sieve()
{
    int i, j, n=10, limit = sqrt(10*1.0) + 2;

    mark[1] = 1;

    for(i = 4; i<=n; i+=2) mark[i] = 1;

    prime.push_back(2);

    for(i = 3; i <= n; i += 2)
    {
        if(!mark[i])
        {
            prime.push_back(i);

            if(i<=limit)
            {
                for(j =  i*i; j <= n; j += i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}

void fact()
{
    factorial[2] = 2;
    factorial[3] = 6;
    factorial[5] = 120;
    factorial[7] = 5040;
}

void task()
{
    //code here...
    ll a, n, k, extra=1, mid;
    vector<int> ans;
    sieve();
    fact();

    cin >> n >> a;
    k = n;

    while(k-- && a!=0){
        mid = a%10;
        a /= 10;
        if(mid==0){
            continue;
        }

        if(mark[mid]==1){
            if(mid>7){
                for(int K=8; K<=mid; K++) extra*=K;
                ans.PB(7);

                if(extra%factorial[7]==0){
                    ans.PB(7);
                    extra /= factorial[7];
                }
                else if(extra%factorial[5]==0){
                    ans.PB(5);
                    extra /= factorial[5];
                }
                else if(extra%factorial[3]==0){
                    ans.PB(3);
                    extra /= factorial[3];
                }
                else if(extra%factorial[2]==0){
                    ans.PB(2);
                    extra /= factorial[2];
                }
            }
            else if(mid>5){
                for(int K=6; K<=mid; K++) extra*=K;
                ans.PB(5);

                if(extra%factorial[7]==0){
                    ans.PB(7);
                    extra /= factorial[7];
                }
                else if(extra%factorial[5]==0){
                    ans.PB(5);
                    extra /= factorial[5];
                }
                else if(extra%factorial[3]==0){
                    ans.PB(3);
                    extra /= factorial[3];
                }
                else if(extra%factorial[2]==0){
                    ans.PB(2);
                    extra /= factorial[2];
                }
            }
            else if(mid>3){
                for(int K=4; K<=mid; K++) extra*=K;
                ans.PB(3);

                if(extra%factorial[7]==0){
                    ans.PB(7);
                    extra /= factorial[7];
                }
                else if(extra%factorial[5]==0){
                    ans.PB(5);
                    extra /= factorial[5];
                }
                else if(extra%factorial[3]==0){
                    ans.PB(3);
                    extra /= factorial[3];
                }
                else if(extra%factorial[2]==0){
                    ans.PB(2);
                    extra /= factorial[2];
                }
            }
            else if(mid>2){
                for(int K=3; K<=mid; K++) extra*=K;
                ans.PB(2);

                if(extra%factorial[7]==0){
                    ans.PB(7);
                    extra /= factorial[7];
                }
                else if(extra%factorial[5]==0){
                    ans.PB(5);
                    extra /= factorial[5];
                }
                else if(extra%factorial[3]==0){
                    ans.PB(3);
                    extra /= factorial[3];
                }
                else if(extra%factorial[2]==0){
                    ans.PB(2);
                    extra /= factorial[2];
                }
            }
        }
        else{
            ans.PB(mid);
        }
    }

    while(extra!=1){
        if(extra%factorial[7]==0){
            ans.PB(7);
            extra /= factorial[7];
        }
        else if(extra%factorial[5]==0){
            ans.PB(5);
            extra /= factorial[5];
        }
        else if(extra%factorial[3]==0){
            ans.PB(3);
            extra /= factorial[3];
        }
        else if(extra%factorial[2]==0){
            ans.PB(2);
            extra /= factorial[2];
        }
    }

    sort(ans.rbegin(), ans.rend());

    for(int K=0; K<ans.size(); K++){
        cout << ans[K];
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

