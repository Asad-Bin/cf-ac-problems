//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 02 05 2020

#include <bits/stdc++.h>

using namespace std;

void task()
{
    int t, n, k;
    string s;

    cin >> t;
    while(t--){
        cin >> n >> k >> s;

        sort(s.begin(), s.end());
        if(s[0]!=s[k-1]){
            cout << s[k-1] << "\n";
            continue;
        }

        cout << s[0];
        if(s[n-1]!=s[k]){
            for(int K=k; K<n; K++) cout << s[K];
            cout << "\n";
        }
        else{
            for(int K=0; K<(int)(n-1)/k; K++) cout << s[K+k];
            cout << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
