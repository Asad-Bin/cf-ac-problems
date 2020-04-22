//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 22 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    int a, mid, total=0;

    cin >> a;
    mid = a;

    while(1){
        total += mid%10;
        mid = mid/10;
        if(mid==0) break;
    }

    if(total%4==0) cout << a << "\n";
    else{
        while(1){
            a++;
            mid = a;
            total = 0;
            while(1){
                total += mid%10;
                mid = mid/10;
                if(mid==0) break;
            }
            if(total%4==0){
                cout << a << "\n";
                return;
            }
        }
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
