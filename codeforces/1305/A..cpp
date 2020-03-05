#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
      if (i > 0) cout << " ";
      cout << a[i];
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
      if (i > 0) cout << " ";
      cout << b[i];
    }
    cout << '\n';
  }
  return 0;
}