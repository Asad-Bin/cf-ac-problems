//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 19 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define    pi    acos(-1.0)

void task()
{
    string str;
    bool ans1=0, ans2=0;

    cin >> str;
    int len = str.length();

    for(int K=0; K<len; K++){
        if(ans1==0 && K+1!=len && str[K]=='A' && str[K+1]=='B'){
            ans1=1;
            K++;
        }
        else if(ans2==0 && K+1!=len && str[K]=='B' && str[K+1]=='A'){
            ans2=1;
            K++;
        }

        if(ans1==ans2 && ans1==1){
            cout << "YES" << "\n";
            return;
        }
    }

    ans1 = ans2 = 0;
    for(int K=len-1; K>=0; K--){
        if(ans1==0 && K!=0 && str[K]=='A' && str[K+1]=='B'){
            ans1=1;
            K--;
        }
        else if(ans2==0 && K!=0 && str[K]=='B' && str[K+1]=='A'){
            ans2=1;
            K--;
        }

        if(ans1==ans2 && ans1==1){
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << "\n";
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
