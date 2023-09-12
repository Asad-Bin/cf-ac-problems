#include<bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;
//typedef long long int;

#define endl "\n"
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define pb push_back
//#define mp make_pair
#define int long long

//const int INF = 1e9;
//const int MOD = 1e9 + 7;
//const ld EPS = 1e-18;
//const ld PI = acos(-1.0); 
const int N = 1e5 + 3;
const int MOD = 998244353;
vector<vector<int>> adj(N);
int cnt[N][2];
int niche[N]; 
map<pair<int,int>,int> mp;
bool vis[N];
int tot;
void dfs(int vert){
  vis[vert] = true;
  //cout << vert << ' ' << adj[vert].size() << endl;
  for(auto child : adj[vert]){
   // cout << child << ' ' << vert << ' ' << mp[{vert , child}] << endl;
    cnt[vert][mp[{vert  , child}]]++;
    if(vis[child] == false){
      dfs(child);
    }
    //cout << child << ' ' << vert << ' ' << cnt[child][1] << ' ' << cnt[child][0] << ' ' << niche[child] << ' ' << cnt[vert][1] << ' ' << cnt[vert][0] << endl;
    int ad = (cnt[vert][1] * cnt[child][0]) % MOD;
    if(mp[{vert , child}] == 0) ad = (ad + cnt[vert][1]) % MOD;
    niche[vert] = (niche[vert] + ad) % MOD;
    cnt[vert][0] = (cnt[vert][0] + cnt[child][0]) % MOD;
    cnt[vert][1] = (cnt[vert][1] + cnt[child][1]) % MOD;
    niche[vert] = (niche[vert] + niche[child]) % MOD;
  }
  //tot = (tot + niche[vert]) % MOD;
}

void GG()
{
  int n;
  cin >> n;
  tot = 0;
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    for(int j = 1; j <= x; j++){
      int v , w;
      cin >> v >> w;
      adj[i].pb(v);
      mp[{i , v}] = w;
      //cout << i << ' ' << v << ' ' << mp[{i , v}] << endl;
    }
  }

  tot = 0;
  dfs(1);
  // for(int i = 1; i <= n; i++){
  //   cout << i << ' ' << cnt[i][0] << ' ' << cnt[i][1] << ' ' << niche[i] << endl;
  // }
  cout << (niche[1]) % MOD << endl;

}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(cnt , 0 , sizeof(cnt));
  memset(niche , 0 , sizeof(niche));
  memset(vis, false, sizeof(vis));
  int ttc=1;
  //cin>>ttc;
  //int cnt=0;
  while(ttc--)
  {
    //cout<<"Case "<<++cnt<<": ";
    GG();
  }
}