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
#define mp make_pair
#define int long long

//const int INF = 1e9;
//const int MOD = 1e9 + 7;
//const ld EPS = 1e-18;
//const ld PI = acos(-1.0); 

const int MOD = 998244353;

void GG()
{
  int n;
  cin >> n;
  map<int,int> x;
  map<int,int> y;
  vector<int> v(n);
  int mx = -1;
  set<int> kk;
  for(int i = 0; i < n; i++){
    cin >> v[i];
    mx = max(mx , v[i]);
    kk.insert(v[i]);
  }
  for(int i = 0; i < n; i++){
    int u;
    cin >> u;
    x[v[i]] = u;
  }
  int m;
  cin >> m;
  vector<int> v1(m);
  for(int i = 0; i < m; i++) {
    cin >> v1[i];
    kk.insert(v1[i]);
    mx = max(mx , v1[i]);
  }

  for(int i = 0; i < m; i++){
    int u ;
    cin >> u;
    y[v1[i]] = u; 
  }

  int ans = 1;
  for(auto i : kk){
    if(x[i] < y[i]) {
      cout << 0 << endl;
      return;
    }
    else if(x[i] > y[i]){
      ans = (ans * 2) % MOD;
    }
  }
  cout << ans << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int ttc=1;
  //cin>>ttc;
  //int cnt=0;
  while(ttc--)
  {
    //cout<<"Case "<<++cnt<<": ";
    GG();
  }
}