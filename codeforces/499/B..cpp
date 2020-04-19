//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 19 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define    pi    acos(-1.0)

void task()
{
    int n, m, len_a, len_b;
    string a, b;
    map<string, string> mp;

    cin >> n >> m;
    vector<string> v(n);

    for(int K=1; K<=m; K++){
        cin >> a >> b;
        mp.insert(make_pair(a, b));
    }

    for(int K=0; K<n; K++) cin >> v[K];

    for(int K=0; K<n; K++){
        a = v[K];
        b = mp[a];

        len_a = a.length();
        len_b = b.length();

        if(len_b<len_a){
            v[K] = b;
        }
    }

    for(int K=0; K<n; K++) cout << v[K] << ' ';
    cout << "\n";
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
