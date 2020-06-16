//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 16 06 2020

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


void bruce(int n)
{
    cout << "\nExpected answer:\n";
    cout << "\nAnswer recieved:\n";
}


void task()
{
    //code here...

    string s;
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k >> s;

        int ans=0, lol;

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                for(int j=max(0,i-k);j<=min(n-1,i+k);j++) s[j]='*';
            }
        }

        for(int i=0;i<n;i++){
            lol=0;
            while(i<n && s[i]=='0'){
                i++;
                lol++;
            }
            ans+=lol/(k+1);
            if(lol%(k+1)!=0) ans++;
        }

        cout<<ans<<endl;

        /*int ans = 0, p=0, q=n+1;

         cfor(int K=0; K<n; K++){
            if(s[K]=='1'){
                if(p==0){
                    ans += (int)(K/(k+1));
                }
                else ans += (int)(K+1-p)/(2*k+1);
                //cout << p << ' ' << K << ' ' << ans << "\n";
                p = K+1;
            }
            if(K==n-1){
                ans += (int)(n-p)/(k+1);
                if((n-p)%(k+1)==k && s[p-1]!='1') ans++;
            }
        }

        cout << ans << "\n";
       ontinue;

        if(k==0){
            for(int K=0; K<n; K++){
                if(s[K]=='0') ans++;
            }
            cout << ans << "\n";
            continue;
        }

        for(int K=0; K<n; K++){
            if(s[K]=='1'){
                p = K+1;
                ans += (int)((K+1)/(k+1));
                break;
            }
        }

        for(int K=n-1; K>=0; K--){
            if(s[K]=='1'){
                q = K+1;
                ans += (int)((n-K-1)/(k+1));
                break;
            }
        }
        //k = k*2+1;

        for(int K=p; K<min(q,n); K++){
            if(s[K]=='1'){
                ans += (int)(K+1-p)/(2*k+1);
                //cout << p << ' ' << K << ' ' << ans << "\n";
                p = K+1;
            }
        }

        ans += (int)(n-p)/(k+1);
        //cout << p << ' ' << ans << "\n";
        if((n-p)%(k+1)>0 && p==0) ans++;
        //ans += mid;

        cout << ans << "\n";*/
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

