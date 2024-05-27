#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> get_divs(int n) {
  vector<int> divs;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      divs.push_back(i);
      if (n / i != i) {
        divs.push_back(n / i);
      }
    }
  }
  return divs;
}

void solve () {
  int n;  cin >> n;
  vector<int> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    if (a[n - 1] % a[i]) {
      cout << n << "\n";
      return ;
    }
  }
  auto divs = get_divs(a[n - 1]);
  int ans = 0;
  set<int> st(a.begin(), a.end());
  for (auto d: divs) {
    if (st.count(d))  continue;
    int now = 0, L = 1;
    for (auto ai: a) {
      if (d % ai == 0) {
        now++;
        L = lcm(L, ai);
      }
    }
    if (L == d)  ans = max(ans, now);
  }

  cout << ans << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
}