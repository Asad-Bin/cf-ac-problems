//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 20 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

int gcd(int a, int b)
{
    if(a%b==0) return b;
    return gcd(b, a%b);
}

void task()
{
    int a, b, mid;

    cin >> a >> b;
    int mx = max(a, b);
    mx = 6-mx+1;

    mid = gcd(6, mx);

    cout << (int)mx/mid << "/" << (int)(6/mid) << "\n";
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

