/**
    ***Bismillahir Rahmanir Rahim***
    
             Asad Bin Saber
**/

#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5;
int ara[MX+5], cnt[100];
int main()
{
    int n;
    
    cin >> n;
    
    for(int K = 0; K < n; K++){
        cin >> ara[K];
        cnt[ara[K]+30]++;
    }
    
    int ans = -100;
    for(int K = 30; K >= -30; K--){
        if(cnt[K+30]){
            int sum = 0, mx = -100;
            for(int L = 0; L < n; L++){
                if(ara[L] <= K && sum+ara[L] >= ara[L]){
                    sum += ara[L];
                }
                else if(ara[L] > K){
                    sum = -MX+5;
                }
                else{
                    sum = ara[L];
                }
                
                mx = max(mx, sum);
            }
            
            ans = max(ans, mx-K);
        }
    }
    
    // int sum, mx, ans = 0;
    // sum = mx = ara[0];
    // for(int K = 1; K < n; K++){
        // cout << K << ' ' << ara[K] << ' ' << sum << ' ' << mx << ' ' << ans << "\n";
        // if(sum+ara[K]-max(mx, ara[K]) >= 0){
            // sum += ara[K];
            // mx = max(mx, ara[K]);
        // }
        // else{
            // sum = ara[K];
            // mx = ara[K];
        // }
        
        
        
        
        
        // // if(sum+ara[K] > ara[K]){
        // // }
        // // else if(sum+ara[K] == ara[K]){
            // // if(sum+ara[K]-mx >= 0){
                // // sum += ara[K];
                // // mx = max(mx, ara[K]);
            // // }
            // // else{
                // // sum = ara[K];
                // // mx = ara[K];
            // // }
        // // }
        // ans = max(ans, sum-mx);
    // }
    
    cout << ans << "\n";
    
    return 0;
}