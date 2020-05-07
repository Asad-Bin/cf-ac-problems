

    //...Bismillahir Rahmanir Rahim...
    // Code by    Asad Bin Saber
    // 06 05 2020
     
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
     
        int t, n;
        vector<int> ara;
        ara.PB(0); ara.PB(2); ara.PB(7);
        for(int K=3; ara[K-1]<1e9; K++){
            ara.PB(2*ara[K-1] + 3 - ara[K-2]);
        }
     
        cin >> t;
        while(t--){
            cin >> n;
     
            int ans = 0;
            while(1){
                auto it = upper_bound(ara.begin(), ara.end(), n);
                --it;
                if(*it==1 || *it==0) break;
                n -= *it;
                ans++;
                //cout << *it << "\n";
            }
     
            cout << ans << "\n";
        }
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