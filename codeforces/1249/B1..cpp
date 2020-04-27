//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 27 04 2020

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

vector<int> ara(201);
int ans[201];
int ini, moves;

void u_find(int K)
{
    if(K==ini){
        ans[K] = moves;
        return;
    }

    moves++;
    int mid = ara[K];
    u_find(mid);
    ans[K] = moves;
}

void task()
{
    int q, n;

    cin >> q;
    while(q--){
        cin >> n;
        for(int K=0; K<=n; K++) ans[K] = 0;

        for(int K=1; K<=n; K++) cin >> ara[K];

        for(int K=1; K<=n; K++){
            if(ans[K]!=0) continue;
            moves = 1;
            ini = K;
            u_find(ara[K]);
        }

        for(int K=1; K<=n; K++) cout << ans[K] << " ";
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
