/**
    ***Bismillahir Rahmanir Rahim***
    
             Asad Bin Saber
**/

#include <bits/stdc++.h>

using namespace std;

int ara[4005];
bool vis[4005][2005];
vector<int> v;
bool calc(int at, int n, int sum)
{
    if(sum == 0) return true;
    if(sum < 0) return false;
    if(at == n) return false;
    
    if(vis[at][sum]) return false;
    vis[at][sum] = 1;
    
    bool ok = 0;
    ok |= calc(at+1, n, sum-v[at]);
    if(ok) return ok;
    ok |= calc(at+1, n, sum);
    
    return ok;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    
    int t, n;
    
    cin >> t;
    while(t--){
        cin >> n;
        
        for(int K = 0; K < 2*n; K++) cin >> ara[K];
        
        v.clear();
        for(int K = 0; K < 2*n; K++){
            int cnt = 0;
            for(int L = K+1; L < 2*n; L++){
                if(ara[L] >= ara[K]){
                    break;
                }
                
                cnt++;
            }
            
            K += cnt;
            v.push_back(cnt+1);
        }
        // for(int K = 0; K < (int)v.size(); K++) cout << v[K] << ' ';
        // cout << "\n";
        
        memset(vis, 0, sizeof vis);
        if(calc(0, v.size(), n)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}