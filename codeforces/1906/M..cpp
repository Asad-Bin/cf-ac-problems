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

void GG()
{
	int n;
	cin >> n;
	int arr[n];
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + n);
	int msum = sum - arr[n - 1];
	cout << min(sum / 3 , msum) << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ttc=1;
	// cin>>ttc;
	//int cnt=0;
	while(ttc--)
	{
		//cout<<"Case "<<++cnt<<": ";
		GG();
	}
}