//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 18 04 2020

#include <bits/stdc++.h>

using namespace std;

#define    ll   long long
#define    pi   acos(-1.0)

void task()
{
    int n, a, b;

    cin >> n;
    vector<int> ara(n+1);
    //vector<int> position(n+1);

    for(int K=0; K<n; K++){
        cin >> a >> b;

        ara[a] = b;
        //position[b] = a;
    }

    for(int K=2; K<=n; K++){
        if(ara[K-1]>ara[K]){
            cout << "Happy Alex" << "\n";
            return;
        }
    }

    cout << "Poor Alex" << "\n";
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

