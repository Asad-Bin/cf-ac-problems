//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 20 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    ll n, start=0, end_=0;

    cin >> n;
    vector<ll> ara(n);
    vector<ll> sorted;

    for(int K=0; K<n; K++) cin >> ara[K];

    sorted = ara;
    sort(sorted.begin(), sorted.end());

    for(int K=0; K<n; K++){
        if(start!=0 && end_==0 && ara[K]>ara[K-1]){
            cout << "no\n";
            return;
        }
        if(start!=0 && end_!=0 && ara[K]<ara[K-1]){
            cout << "no\n";
            return;
        }
        if(start==0 && end_==0 && sorted[K]!=ara[K]){
            start = K+1;
            //cout << start << '.';
            continue;
        }
        if(start!=0 && end_==0 && K<n-1 && ara[K+1]==sorted[K+1]){
            if(ara[K+1]<ara[K]) continue;
            end_ = K+1;
            //cout << end_ << "\n";
        }
    }

    if(start==0 && end_==0) cout << "yes\n1 1\n";
    else if(start!=0 && end_==0) cout << "yes\n" << start << ' ' << n << "\n";
    else cout << "yes\n" << start << ' ' << end_ << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
