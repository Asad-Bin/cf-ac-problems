//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 30 04 2020

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
    int n=7, white=0, black=0;
    char str[8][9];

    for(int K=0; K<=n; K++){
        scanf(" %[^\n]", str[K]);
    }

    for(int K=0; K<=n; K++){
        for(int L=0; L<=n; L++){
            if(str[K][L]=='Q') white += 9;
            else if(str[K][L]=='R') white += 5;
            else if(str[K][L]=='B') white += 3;
            else if(str[K][L]=='N') white += 3;
            else if(str[K][L]=='P') white += 1;
            else if(str[K][L]=='q') black += 9;
            else if(str[K][L]=='r') black += 5;
            else if(str[K][L]=='b') black += 3;
            else if(str[K][L]=='n') black += 3;
            else if(str[K][L]=='p') black += 1;
        }
    }

    if(white==black) cout << "Draw\n";
    else if(white>black) cout << "White\n";
    else cout << "Black\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}

