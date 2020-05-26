//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 26 05 2020

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

    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        string s[n], all[1000];
        bool flag=0;

        for(int K=0; K<n; K++) cin >> s[K];

        int i = 1;
        all[0] = s[0];
        for(int K=0; K<m; K++){
            //all[K] = s[0];
            for(int L=0; L<26; L++){
                if('a'+L!=s[0][K]){
                    all[i] = s[0];
                    all[i][K] = L+'a';
                    i++;
                }
            }
        }

        //cout << "\n-------\n";
        //for(int K=0; K<i; K++) cout << all[K] << "\n";
        //cout << "\n-------\n\n";

        //vector<bool> mark(i);
        for(int K=1; K<n; K++){
            for(int L=0; L<i; L++){
                if(all[L].empty()) continue;

                //if(mark[L]) continue;
                flag = 0;
                for(int M=0; M<m; M++){
                    if(all[L][M]!=s[K][M]){
                        if(flag==0){
                            flag=1;
                            continue;
                        }

                        //cout << all[L] << "\n";
                        //mark[L] = 1;
                        all[L].clear();
                        //cout << "-" << all[L] << "\n";
                        //i--;
                        //L--;
                        break;
                    }
                }
            }
        }//cout << "\n-------\n\n";

        flag=0;
        for(int K=0; K<i; K++){
            if(!all[K].empty()){
                flag=1;
                cout << all[K] << "\n";
                break;
            }
        }

        if(flag==0){
            cout << "-1\n";
        }
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

