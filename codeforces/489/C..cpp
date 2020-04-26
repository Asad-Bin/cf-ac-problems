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


void max_(int m, int s)
{
    char num[101];

    if(m==1){
        if(s<=9) cout << s << "\n";
        else cout << "-1\n";
    }
    else{
        if(s==0){
            printf("-1\n");
            return;
        }
        for(int K=0; K<m; K++){
            if(s>0){
                if(s>=9){
                    num[K] = 48 + 9;
                    s -= 9;
                }
                else{
                    num[K] = 48 + s;
                    s = 0;
                }
            }
            else{
                num[K] = '0';
            }
        }
        num[m] = '\0';

        if(s!=0) printf("-1\n");
        else printf("%s\n", num);
    }
}

void min_(int m, int s)
{
    char num[101];

    if(m==1){
        if(s<=9) cout << s << " ";
        else cout << "-1\n";
    }
    else{
        num[0] = '1';
        s--;
        for(int K=1; K<m-1; K++) num[K] = '0';
        if(s>9){
            num[m-1] = '9';
            num[m] = '\0';
            s-=9;

            for(int K=m-2; K>=1; K--){
                if(s>9){
                    num[K] = 48+9;
                    s-=9;
                }
                else{
                    num[K] = 48+s;
                    s=0;
                }

                if(s==0) break;
            }

            if(s<9){
                num[0] += s;
                s = 0;
            }
        }
        else if(s==-1){
            printf("-1 ");
            return;
        }
        else{
            num[m-1] = 48+s;
            num[m] = '\0';
            s = 0;
        }

        if(s!=0) printf("-1 ");
        else printf("%s ", num);
    }
}

void task()
{
    int m, s;
    cin >> m >> s;

    min_(m, s);
    max_(m, s);
}

int main()
{
    task();

    return 0;
}

