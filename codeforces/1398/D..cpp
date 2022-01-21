/**
    ***Bismillahir Rahmanir Rahim***
    
    Asad Bin Saber
**/

#include <bits/stdc++.h>

using namespace std;

const int MX = 205;
int red[MX], green[MX], blue[MX];
int dp[MX][MX][MX];
int calc(int i, int j, int k)
{
    if(i >= 0 && j >= 0 && k >= 0 && dp[i][j][k] != -1) return dp[i][j][k];
    
    int ans = 0;
    if(i >= 0 && j >= 0) ans = max(ans, calc(i-1, j-1, k)+red[i]*green[j]);
    if(i >= 0 && k >= 0) ans = max(ans, calc(i-1, j, k-1)+red[i]*blue[k]);
    if(j >= 0 && k >= 0) ans = max(ans, calc(i, j-1, k-1)+green[j]*blue[k]);
    
    if(i < 0 || j < 0 || k < 0) return ans;
    return dp[i][j][k] = ans;
}
int main()
{
    int r, g, b;
    
    cin >> r >> g >> b;
    
    for(int K = 0; K < r; K++) cin >> red[K];
    for(int K = 0; K < g; K++) cin >> green[K];
    for(int K = 0; K < b; K++) cin >> blue[K];
    
    sort(red, red+r);
    sort(green, green+g);
    sort(blue, blue+b);
    
    memset(dp, -1, sizeof dp);
    
    cout << calc(r-1, g-1, b-1) << "\n";
    
    return 0;
}