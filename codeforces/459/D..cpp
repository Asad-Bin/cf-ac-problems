/**
    ***Bismillahir Rahmanir Rahim***
    
             Asad Bin Saber
**/

#include <bits/stdc++.h>

using namespace std;

const int MX = 1e6;
int ara[MX+5], dp[2][MX+5], tree[4*MX+5];
void update(int at, int l, int r, int idx)
{
    if(l == r){
        tree[at]++;
        
        return;
    }
    
    int mid = (l+r)/2;
    
    if(idx <= mid) update(at*2, l, mid, idx);
    else update(at*2+1, mid+1, r, idx);
    
    tree[at] = tree[at*2] + tree[at*2+1];
}
// int query(int at, int l, int r, int val)
// {
    // if(val < l) return tree[at];
    
    // int mid = (l+r)/2;
    
    // int ans = 0;
    // if(val < mid) ans += query(at*2, l, mid, val);
    // ans += query(at*2+1, mid+1, r, val);
    
    // return ans;
// }
int query(int at, int l, int r, int L, int R)
{
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return tree[at];
    
    int mid = (l+r)/2;
    
    int ans = 0;
    ans += query(at*2, l, mid, L, R);
    ans += query(at*2+1, mid+1, r, L, R);
    
    return ans;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    
    int n;
    map<int, int> cnt1, cnt2;
    
    cin >> n;
    
    for(int K = 0; K < n; K++) scanf("%d", &ara[K]);
    
    for(int K = 0; K < n; K++){
        cnt1[ara[K]]++;
        dp[0][K] = cnt1[ara[K]];
    }
    for(int K = n-1; K >= 0; K--){
        cnt2[ara[K]]++;
        dp[1][K] = cnt2[ara[K]];
    }
    
    long long ans = 0;
    for(int K = 0; K < n; K++){
        ans += query(1, 1, n, dp[1][K]+1, n);
        update(1, 1, n, dp[0][K]);
    }
    
    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}