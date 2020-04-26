//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 26 04 2020

#include <bits/stdc++.h>

using namespace std;

// typedefs...
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> pll;

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
    int s, n, x, y, mid;

    cin >> s >> n;
    vector<vector<int> > bonus(10001);
    vector<int> q;

    for(int K=0; K<n; K++){
        cin >> x >> y;

        bonus[x].push_back(y);
        q.push_back(x);
    }

    sort(q.begin(), q.end());

    for(int K=0; K<q.size(); K++){
        if(mid==q[K]) continue;
        mid = q[K];

        if(mid>=s){
            cout << "NO\n";
            return;
        }

        for(int L=0; L<bonus[mid].size(); L++){
            s += bonus[mid][L];
        }
    }

    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    task();

    return 0;
}

