// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


struct Trie{
	const int A = 26;
	int N;
	
	vector<vector<int> > next;
	vector<int> cnt;
	
	Trie() : N(0) {
		node();
	}
	
	int node(){
		next.emplace_back(A, -1);
		cnt.emplace_back(0);
		
		return N++;
	}
	
	inline int get(char c){
		return c-'0';
	}
	
	inline void insert(string s){
		int cur = 0;
		for(char c : s){
			int to = get(c);
			if(next[cur][to] == -1) next[cur][to] = node();
			cur = next[cur][to];
		}
		cnt[cur]++;
	}
	
	inline int find(string s){
		int cur = 0;
		for(char c : s){
			int to = get(c);
			if(next[cur][to] == -1) return false;
			cur = next[cur][to];
		}
		return cnt[cur];
	}
	
	// Doesn't check for existance
	inline void erase(string s){
		int cur = 0;
		for(char c : s){
			int to =get(c);
			cur = next[cur][to];
		}
		if(cnt[cur]) cnt[cur]--;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	Trie trie;
	
	int t;
	cin >> t;
	while(t--){
		char c;
		string s, str;
		cin >> c;cin.ignore();
		cin >> s;
		//debug(c)debug(s);
		
		if(c == '+'){
			str.assign(18, '0');
			int i = 17, j = (int)s.length()-1;
			
			while(j >= 0){
				str[i] = ((s[j]-'0')%2==0 ? '0' : '1');
				
				i--;
				j--;
			}
			
			trie.insert(str);
		}
		else if(c == '-'){
			str.assign(18, '0');
			int i = 17, j = (int)s.length()-1;
			
			while(j >= 0){
				str[i] = ((s[j]-'0')%2==0 ? '0' : '1');
				
				i--;
				j--;
			}
			
			trie.erase(str);
		}
		else{
			str.assign(18, '0');
			int i = 17, j = (int)s.length()-1;
			
			while(j >= 0){
				str[i] = ((s[j]-'0')%2==0 ? '0' : '1');
				
				i--;
				j--;
			}
			
			cout << trie.find(str) << "\n";
		}
	}
	
	return 0;
}





































