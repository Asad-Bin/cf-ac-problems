//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 20 06 2020

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

int gcd(int a, int b) {
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


void bruce()
{
    cout << "\nExpected answer:\n";
    cout << "\nAnswer recieved:\n";
}

const int MX = 1e6;
int arr[MX];
int GCD(int n)
{
    int high = 0;
    for (int i = 0; i < n; i++)
        high = max(high, arr[i]);

    int count[high + 1] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int counter = 0;
    for (int i = high; i >= 1; i--)
    {
        int j = i;
       counter = 0;
        while (j <= high)
        {
            if(count[j] >=2)
               return j;

           else if (count[j] == 1)
                counter++;
            j += i;
            if (counter == 2)
                return i;
        }
    }
}

void task()
{
    //code here...

    int t, n;

    cin >> t;
    while(t--){
        cin>> n;
        for(int i = 0; i < n; i++){
            arr[i] = i+1;
        }
        cout<< GCD(n) << "\n";

        /*
        if(mark[n]){
            for(int K=n-1; K>=1; K--){
                if(n%K==0){
                    cout << K << "\n";
                    break;
                }
            }
        }
        else{
            n--;
            for(int K=n-1; K>=1; K--){
                if(n%K==0){
                    cout << K << "\n";
                    break;
                }
            }
        }*/
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

