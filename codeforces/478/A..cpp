//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 19 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define    pi    acos(-1.0)

void task()
{
    int a, b, c, d, e;

    cin >> a >> b >> c >> d >> e;

    double ans = 1.0*(a+b+c+d+e)/5;

    if((a+b+c+d+e)!=0 && (ceil(ans)-floor(ans))<0.000001) cout << (int)(a+b+c+d+e)/5 << "\n";
    else cout << "-1" << "\n";
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
