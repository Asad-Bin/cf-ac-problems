//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 20 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    int a1, a2, a3, b1, b2, b3, n;

    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;

    a1 += (a2+a3);
    b1 += (b2+b3);
    int shelves = (int)(a1)/5;
    shelves += (int)(b1)/10;
    if(a1%5!=0) shelves++;
    if(b1%10!=0) shelves++;

    if(shelves>n) cout << "NO" << "\n";
    else cout << "YES" << "\n";
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

