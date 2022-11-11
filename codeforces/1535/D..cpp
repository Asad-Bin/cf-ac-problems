// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


const int N = (1<<20);
int tree[4*N+5];
string s;
void build(int at, int l, int r)
{
	if(l == r){
		if(s[at-1] == '?') tree[at] = 2;
		else tree[at] = 1;
		return;
	}
	
	int mid = (l+r)/2;
	
	build(at*2, l, mid);
	build(at*2+1, mid+1, r);
	
	if(s[at-1] == '1') tree[at] = tree[at*2];
	else if(s[at-1] == '0') tree[at] = tree[at*2+1];
	else if(s[at-1] == '?') tree[at] = tree[at*2] + tree[at*2+1];
}
void update(int at, int l, int r, int sft, int i, char c)
{
	bool ok = 0;
	for(int K = 0; K < 20; K++){
		if((at<<K) > i) break;
		if((at&(i>>K)) == (i>>(K)) && ((at<<K)&i) == (at<<K)) {
			ok = 1;
			break;
		}
	}
	//if((at&(i>>(sft-1))) != (i>>(sft-1))) return;
	if(!ok) return ;
	
	if(l == r){
		//if(i != at) return ;
		
		s[at-1] = c;
		
		if(s[at-1] == '?') tree[at] = 2;
		else tree[at] = 1;
		
		//cout << "ok :" << i << ' ' << at << "\n";
		
		//cout << at << ' ' << s[at-1] << ' ' << tree[at] << "\n";
		//cout << s << "\n";
		return;
	}
	if(i == at){
		s[at-1] = c;
		
		if(s[at-1] == '1') tree[at] = tree[at*2];
		else if(s[at-1] == '0') tree[at] = tree[at*2+1];
		else if(s[at-1] == '?') tree[at] = tree[at*2] + tree[at*2+1];
		//cout << "ok " << i << ' ' << at << "\n";;
		
		//cout << at << ' ' << s[at-1] << ' ' << tree[at] << "\n";
		//cout << s << "\n";
		
		return;
	}
	
	int mid = (l+r)/2;
	
	//int x = at&i;
	////if((i&(at<<(sft)))^x) 
	//if((i>>(sft-1))&1) 
	update(at*2+1, mid+1, r, sft-1, i, c);
	//else 
	update(at*2, l, mid, sft-1, i, c);
	
	if(s[at-1] == '1') tree[at] = tree[at*2];
	else if(s[at-1] == '0') tree[at] = tree[at*2+1];
	else if(s[at-1] == '?') tree[at] = tree[at*2] + tree[at*2+1];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int k, n = 1; cin >> k;
	n = (1<<k) - 1;

	cin >> s;
	reverse(s.begin(), s.end());
	
	memset(tree, 0, sizeof(tree));
	build(1, 1, (1<<(k-1)));
	
	//for(int K = 1; K <= n; K++) cout << tree[K] << ' ';
	//cout << "\n";
	
	int q, i; char c;
	cin >> q;
	while(q--){
		cin >> i >> c;
		
		update(1, 1, (1<<(k-1)), k, n-i+1, c);
		cout << tree[1] << "\n";
	}
	
	return 0;
}





































