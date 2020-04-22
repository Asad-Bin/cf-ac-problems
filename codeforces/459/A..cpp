//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 22 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    int x1, y1, x2, y2, x, y;

    cin >> x1 >> y1 >> x2 >> y2;

    x = abs(y2-y1);
    y = abs(x2-x1);

    if(x1==x2) cout << x+x1 << ' ' << y1 << ' ' << x+x2 << ' ' << y2 << "\n";
    else if(y1==y2) cout << x1 << ' ' << y+y1 << ' ' << x2 << ' ' << y+y1 << "\n";
    else{
        if(x==y) cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1 << "\n";
        else cout << "-1\n";
    }
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

