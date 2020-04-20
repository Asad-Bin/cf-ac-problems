//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 20 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    int n, ans=0, count, mid;

    cin >> n;
    vector<int> needs(n);
    vector<int> price(n);

    for(int K=0; K<n; K++) cin >> needs[K] >> price[K];

    for(int K=0; K<n; K++){
        mid = K;
        ans+=(needs[K]*price[K]);
        count=0;
        for(int L=K+1; L<n; L++){
            if(price[L]<price[mid]){

                K = L-1;
                break;
            }
            //cout << "hi";
            if(L==n-1) K=L;
            count+=needs[L];
        }
        //cout << count << "\n";

        ans+=(price[mid]*count);
    }

    cout << ans << "\n";
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

