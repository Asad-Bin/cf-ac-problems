/**
    ***Bismillahir Rahmanir Rahim***
    
             Asad Bin Saber
**/

#include <bits/stdc++.h>

using namespace std;

int n;
int a[5005], b[5005], dp[5005][5005];
const int MX = 1e9+7;

int p, q;
int calc(int i, int j)
{
    if(i == p) return 0;
    if(j == q) return MX;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    dp[i][j] = min(calc(i, j+1), calc(i+1, j+1)+abs(b[j]-a[i]));
    
    return dp[i][j];
}
int main()
{
    //freopen("in.txt", "r", stdin);
    
    
    int x;
    cin >> n;
    
    int i = 0, j = 0;
    for(int K = 0; K< n; K++){
        cin >> x;
        if(x) a[i++] = K;
        else b[j++] = K;
    }
    
    p = i;
    q = j;
    
    memset(dp, -1, sizeof dp);
    cout << calc(0, 0) << "\n";
    
    return 0;
}