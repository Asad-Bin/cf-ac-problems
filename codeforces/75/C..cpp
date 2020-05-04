//...Bismillahir Rahmanir Rahim...
//code by Asad Bin Saber
// 04 05 2020

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> ara;

ll gcd(ll a, ll b)
{
    if(a%b==0) return b;
    return gcd(b, a%b);
}

void dp(ll x)
{
    for(ll K=1; K*K<=x; K++){
        if(x%K==0){
            ara.push_back(K);
            ara.push_back(x/K);
        }
    }

    sort(ara.begin(), ara.end());
}

void task()
{
    // Code here...

    ll a, b, q, lo, hi;

    cin >> a >> b >> q;
    ll save_me = gcd(a, b);
    dp(save_me);

    while(q--){
        cin >> lo >> hi;

        //ll mid = bin_search(0, ara.size()-1, hi);

        vector<ll>::iterator it = upper_bound(ara.begin(), ara.end(), hi);

        --it;
        if(*it<lo) cout << "-1\n";
        else cout << *it << "\n";
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

