
//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 27 05 2020

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
    string s[4];

    cin >> s[0] >> s[1] >> s[2] >> s[3];

    if(s[0][0]==s[0][1] && s[0][0]==s[1][0] && s[0][0]==s[1][1]) cout << "YES\n";
    else if(s[0][0]==s[0][1] && s[0][0]==s[1][0] && s[0][0]!=s[1][1]) cout << "YES\n";
    else if(s[0][0]==s[0][1] && s[0][0]!=s[1][0] && s[0][0]==s[1][1]) cout << "YES\n";
    else if(s[0][0]!=s[0][1] && s[0][0]==s[1][0] && s[0][0]==s[1][1]) cout << "YES\n";
    else if(s[0][0]!=s[0][1] && s[0][1]==s[1][0] && s[0][1]==s[1][1]) cout << "YES\n";

    else if(s[0][1]==s[0][2] && s[0][1]==s[1][1] && s[0][1]==s[1][2]) cout << "YES\n";
    else if(s[0][1]==s[0][2] && s[0][1]==s[1][1] && s[0][1]!=s[1][2]) cout << "YES\n";
    else if(s[0][1]==s[0][2] && s[0][1]!=s[1][1] && s[0][1]==s[1][2]) cout << "YES\n";
    else if(s[0][1]!=s[0][2] && s[0][1]==s[1][1] && s[0][1]==s[1][2]) cout << "YES\n";
    else if(s[0][1]!=s[0][2] && s[0][2]==s[1][1] && s[0][2]==s[1][2]) cout << "YES\n";

    else if(s[0][2]==s[0][3] && s[0][2]==s[1][2] && s[0][2]==s[1][3]) cout << "YES\n";
    else if(s[0][2]==s[0][3] && s[0][2]==s[1][2] && s[0][2]!=s[1][3]) cout << "YES\n";
    else if(s[0][2]==s[0][3] && s[0][2]!=s[1][2] && s[0][2]==s[1][3]) cout << "YES\n";
    else if(s[0][2]!=s[0][3] && s[0][2]==s[1][2] && s[0][2]==s[1][3]) cout << "YES\n";
    else if(s[0][2]!=s[0][3] && s[0][3]==s[1][2] && s[0][3]==s[1][3]) cout << "YES\n";

    else if(s[1][0]==s[1][1] && s[1][0]==s[2][0] && s[1][0]==s[2][1]) cout << "YES\n";
    else if(s[1][0]==s[1][1] && s[1][0]==s[2][0] && s[1][0]!=s[2][1]) cout << "YES\n";
    else if(s[1][0]==s[1][1] && s[1][0]!=s[2][0] && s[1][0]==s[2][1]) cout << "YES\n";
    else if(s[1][0]!=s[1][1] && s[1][0]==s[2][0] && s[1][0]==s[2][1]) cout << "YES\n";
    else if(s[1][0]!=s[1][1] && s[1][1]==s[2][0] && s[1][1]==s[2][1]) cout << "YES\n";

    else if(s[1][1]==s[1][2] && s[1][1]==s[2][1] && s[1][1]==s[2][2]) cout << "YES\n";
    else if(s[1][1]==s[1][2] && s[1][1]==s[2][1] && s[1][1]!=s[2][2]) cout << "YES\n";
    else if(s[1][1]==s[1][2] && s[1][1]!=s[2][1] && s[1][1]==s[2][2]) cout << "YES\n";
    else if(s[1][1]!=s[1][2] && s[1][1]==s[2][1] && s[1][1]==s[2][2]) cout << "YES\n";
    else if(s[1][1]!=s[1][2] && s[1][2]==s[2][1] && s[1][2]==s[2][2]) cout << "YES\n";

    else if(s[1][2]==s[1][3] && s[1][2]==s[2][2] && s[1][2]==s[2][3]) cout << "YES\n";
    else if(s[1][2]==s[1][3] && s[1][2]==s[2][2] && s[1][2]!=s[2][3]) cout << "YES\n";
    else if(s[1][2]==s[1][3] && s[1][2]!=s[2][2] && s[1][2]==s[2][3]) cout << "YES\n";
    else if(s[1][2]!=s[1][3] && s[1][2]==s[2][2] && s[1][2]==s[2][3]) cout << "YES\n";
    else if(s[1][2]!=s[1][3] && s[1][3]==s[2][2] && s[1][3]==s[2][3]) cout << "YES\n";

    else if(s[2][0]==s[2][1] && s[2][0]==s[3][0] && s[2][0]==s[3][1]) cout << "YES\n";
    else if(s[2][0]==s[2][1] && s[2][0]==s[3][0] && s[2][0]!=s[3][1]) cout << "YES\n";
    else if(s[2][0]==s[2][1] && s[2][0]!=s[3][0] && s[2][0]==s[3][1]) cout << "YES\n";
    else if(s[2][0]!=s[2][1] && s[2][0]==s[3][0] && s[2][0]==s[3][1]) cout << "YES\n";
    else if(s[2][0]!=s[2][1] && s[2][1]==s[3][0] && s[2][1]==s[3][1]) cout << "YES\n";

    else if(s[2][1]==s[2][2] && s[2][1]==s[3][1] && s[2][1]==s[3][2]) cout << "YES\n";
    else if(s[2][1]==s[2][2] && s[2][1]==s[3][1] && s[2][1]!=s[3][2]) cout << "YES\n";
    else if(s[2][1]==s[2][2] && s[2][1]!=s[3][1] && s[2][1]==s[3][2]) cout << "YES\n";
    else if(s[2][1]!=s[2][2] && s[2][1]==s[3][1] && s[2][1]==s[3][2]) cout << "YES\n";
    else if(s[2][1]!=s[2][2] && s[2][2]==s[3][1] && s[2][2]==s[3][2]) cout << "YES\n";

    else if(s[2][2]==s[2][3] && s[2][2]==s[3][2] && s[2][2]==s[3][3]) cout << "YES\n";
    else if(s[2][2]==s[2][3] && s[2][2]==s[3][2] && s[2][2]!=s[3][3]) cout << "YES\n";
    else if(s[2][2]==s[2][3] && s[2][2]!=s[3][2] && s[2][2]==s[3][3]) cout << "YES\n";
    else if(s[2][2]!=s[2][3] && s[2][2]==s[3][2] && s[2][2]==s[3][3]) cout << "YES\n";
    else if(s[2][2]!=s[2][3] && s[2][3]==s[3][2] && s[2][3]==s[3][3]) cout << "YES\n";

    else cout << "NO\n";
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
