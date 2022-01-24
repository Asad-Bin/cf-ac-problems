/**
    ***Bismillahir Rahmanir Rahim***
    
    Asad Bin Saber
**/

#include <bits/stdc++.h>

using namespace std;

const int MX = 1e6;
struct Node{
    int left, right, ans;
    
    Node(){}
    Node(int _ans, int _left, int _right){
        left = _left;
        right = _right;
        ans = _ans;
    }
} tree[4*MX+5];
string s;
int n;
void build(int at, int l, int r)
{
    if(l == r){
        tree[at].left = tree[at].right = 0;
        
        if(s[l-1] == '(') tree[at].left = 1;
        else tree[at].right = 1;
        
        tree[at].ans = 0;
        
        //cout << at << ' ' << l << ' ' << r << ' ' << tree[at].ans << ' ' << tree[at].left << ' ' << tree[at].right << ' ' << "\n";
        return;
    }
    
    int mid = (l+r)/2;
    
    // if(l == 6 && r == 8){
        // l = l;
    // }
    
    build(at*2, l, mid);
    build(at*2+1, mid+1, r);
    
    int t = min(tree[at*2].left, tree[at*2+1].right);
    
    tree[at].ans = tree[2*at].ans + tree[at*2+1].ans + t; //(tree[at*2].left&&tree[at*2+1].right ? 2*t : 0);
    tree[at].left = tree[2*at].left + tree[at*2+1].left - t;
    tree[at].right = tree[2*at].right + tree[at*2+1].right - t;
    
    //cout << at << ' ' << l << ' ' << mid << ' ' << r << ' ' << t << ' ' << tree[at].ans << ' ' << tree[at].left << ' ' << tree[at].right << ' ' << "\n";
    // tree[at].left = tree[at*2].left;
    // tree[at].right = tree[at*2+1].right;
    
    // tree[at].ans = 0;
    // int cnt = 0, num = 0;
    // for(int K = tree[at].left; K <= tree[at].right; K++){
        // if(s[K-1] == '(') cnt++;
        // else cnt--;
        
        // if(cnt == -1){
            // cnt = 0;
            
            // continue;
        // }
        
        // num++;
        // tree[at].ans = max(tree[at].ans, num-cnt);
    // }
}
Node query(int at, int l, int r, int L, int R)
{
    if(L <= l && r <= R) return tree[at]; //tree[at].ans;
    if(r < L || R < l) return Node(0, 0, 0);
    
    int mid = (l+r)/2;
    
    Node x = query(at*2, l, mid, L, R);
    Node y = query(at*2+1, mid+1, r, L, R);
    
    //cout << at << ' ' << l << ' ' << mid << ' ' << r << ' ' << x << ' ' << y << ' ' << "\n";
    // if(x < 0) x = 0;
    // if(y > 0) y = 0;
    //cout << at << ' ' << l << ' ' << mid << ' ' << r << ' ' << x << ' ' << y << ' ' << "\n";
    
    Node sol;
    int t = min(x.left, y.right);
    
    sol.ans = x.ans + y.ans + t; //(x.left && y.right ? 2*t : 0);
    sol.left = x.left + y.left - t;
    sol.right = x.right + y.right - t;
    
    return sol;
}
int main()
{
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #endif
    
    cin >> s;
    
    int q, l, r;
    
    memset(tree, 0, sizeof tree);
    n = (int)s.length();
    build(1, 1, n);
    
    cin >> q;
    while(q--){
        cin >> l >> r;
        
        cout << 2*query(1, 1, n, l, r).ans << "\n";
    }
    
    return 0;
}