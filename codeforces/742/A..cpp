//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 20 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    ll n, m;

    cin >> n;
    m = n%4;

    if(n==0) cout << '1' << "\n";
    else if(m==0) cout << '6' << "\n";
    else if(m==3) cout << '2' << "\n";
    else if(m==2) cout << '4' << "\n";
    else cout << '8' << "\n";
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

