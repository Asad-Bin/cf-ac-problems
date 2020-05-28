//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 28 05 2020

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
    int a, b, c;
    a = b = c = 0;
    string s;

    cin >> s;
    if(s[0]=='A' && s[2]=='B'){
        if(s[1]=='>') a++;
        else b++;
    }
    else if(s[0]=='B' && s[2]=='A'){
        if(s[1]=='>') b++;
        else a++;
    }
    else if(s[0]=='C' && s[2]=='B'){
        if(s[1]=='>') c++;
        else b++;
    }
    else if(s[0]=='B' && s[2]=='C'){
        if(s[1]=='>') b++;
        else c++;
    }
    else if(s[0]=='C' && s[2]=='A'){
        if(s[1]=='>') c++;
        else a++;
    }
    else if(s[0]=='A' && s[2]=='C'){
        if(s[1]=='>') a++;
        else c++;
    }

    cin >> s;
    if(s[0]=='A' && s[2]=='B'){
        if(s[1]=='>') a++;
        else b++;
    }
    else if(s[0]=='B' && s[2]=='A'){
        if(s[1]=='>') b++;
        else a++;
    }
    else if(s[0]=='C' && s[2]=='B'){
        if(s[1]=='>') c++;
        else b++;
    }
    else if(s[0]=='B' && s[2]=='C'){
        if(s[1]=='>') b++;
        else c++;
    }
    else if(s[0]=='C' && s[2]=='A'){
        if(s[1]=='>') c++;
        else a++;
    }
    else if(s[0]=='A' && s[2]=='C'){
        if(s[1]=='>') a++;
        else c++;
    }

    cin >> s;
    if(s[0]=='A' && s[2]=='B'){
        if(s[1]=='>') a++;
        else b++;
    }
    else if(s[0]=='B' && s[2]=='A'){
        if(s[1]=='>') b++;
        else a++;
    }
    else if(s[0]=='C' && s[2]=='B'){
        if(s[1]=='>') c++;
        else b++;
    }
    else if(s[0]=='B' && s[2]=='C'){
        if(s[1]=='>') b++;
        else c++;
    }
    else if(s[0]=='C' && s[2]=='A'){
        if(s[1]=='>') c++;
        else a++;
    }
    else if(s[0]=='A' && s[2]=='C'){
        if(s[1]=='>') a++;
        else c++;
    }

    if(a==0 && b==1 && c==2) cout << "ABC\n";
    else if(a==0 && c==1 && b==2) cout << "ACB\n";
    else if(b==0 && a==1 && c==2) cout << "BAC\n";
    else if(b==0 && c==1 && a==2) cout << "BCA\n";
    else if(c==0 && a==1 && b==2) cout << "CAB\n";
    else if(c==0 && b==1 && a==2) cout << "CBA\n";
    else cout << "Impossible\n";
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

