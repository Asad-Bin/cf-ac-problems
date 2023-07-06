// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg_out cout
#define debug(...) dbg_out << "DBG )> "; __f(#__VA_ARGS__, __VA_ARGS__);
template<typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2> pr) { out << "{ " << pr.first << ", " << pr.second << " }"; return out; }
template<typename T1> ostream& operator<<(ostream& out, vector<T1> vec) { out << "{ "; for (auto &x: vec) out << x << ", "; out << "}"; return out; }
template<typename T1, size_t size> ostream& operator<<(ostream& out, array<T1, size> arr) { out << "{ "; for (auto &x: arr) out << x << ", "; out << "}"; return out; }
template<typename T1, typename T2> ostream& operator<<(ostream& out, map<T1, T2> mp) { out << "{ ";for (auto &x: mp) out << x.first << ": " << x.second <<  ", "; out << "}"; return out; }
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { while (isspace(name[0])) name++; (isalpha(name[0]) || name[0] == '_') ? dbg_out << name << ": " << arg1 << "\n" : dbg_out << arg1 << "\n"; dbg_out.flush();}
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) { const char *comma = strchr(names + 1, ','); while (isspace(names[0])) names++; (isalpha(names[0]) || names[0] == '_') ? dbg_out.write(names, comma - names) << ": " << arg1 << " | " : dbg_out << arg1 << " | "; __f(comma + 1, args...);}
#else
#define debug(...)
#endif

ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b,ll mod){ if(b==0){ return 1;} ll tm=bigmod(a,b/2,mod); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}


struct TrieNode{
    int value;
    TrieNode *child[2];
    TrieNode(){
        this->value = 0;
        this->child[0] = this->child[1] = NULL;
    }
};

//class Solution{   
//public:
    void insert(TrieNode *root,int pre_xor){
        TrieNode *temp = root;
        for(int i=9;i>=0;i--){
            bool curr  = pre_xor & (1<<i);
            if(temp->child[curr]==NULL){
                temp->child[curr] = new TrieNode();
            }
            temp = temp->child[curr];
        }
        temp->value=pre_xor;
    }
    int query(TrieNode *root,int pre_xor){
        TrieNode *temp = root;
        for(int i=9;i>=0;i--){
            bool curr = pre_xor & (1<<i);
            if(temp->child[1-curr] != NULL){
                temp = temp->child[1-curr];
            }else if(temp->child[curr] != NULL){
                temp = temp->child[curr];
                
            }
        }
        
        pre_xor = pre_xor^(temp->value);
        //delete temp;
        return pre_xor;
    }
    int maxSubarrayXOR(int N, int arr[]){    
        TrieNode *root = new TrieNode();
        insert(root,0);
        int result = 0,pre_xor=0;
        for(int i=0;i<N;i++){
            pre_xor= pre_xor^arr[i];
            insert(root,pre_xor);
            result = max(result,query(root,pre_xor));
        }
        delete root;
        return result;
    }
//};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		int n; cin >>n;
		
		int ara[n];
		for(int K = 0;K < n; K++) cin >> ara[K];
		
		
		//v.clear();
		//for(int K = 0;  K < n; K++) v.push_back(ara[K]);
		//int ans = gaussian_elimination();
		
		//for(int K = n-2; K >= 0; K--) ara[K] ^= ara[K+1];
		////<< 
		
		//for(int K = 0; K < n; K++) cout << ara[K] << ' ';
		//cout << "\n";
		
		//v.clear();
		//for(int K = 0;  K < n; K++) v.push_back(ara[K]);
		//cout << max(ans, gaussian_elimination()) << "\n";
		
		//int ans = ara[0];
		//for(int K = 1; K < n; K++) ara[K] ^= ara[K-1], ans = max(ans, ara[K]);
		
		//int sum = 0, max_;
		//sum = max_ = ara[0];
		////ul = dl = u = v = 0;
		//for(int M=1; M<n; M++){
			////sum = max(sum+help[M], help[M]);
			//if((sum^ara[M])>=ara[M]){
				//sum ^= ara[M];
				////v++;
			//}
			//else{
				//sum = ara[M];
				////u = M;
				////v = M;
			//}
			
			//max_ = max(max_, sum);
			////if(sum>max_){
				////max_ = sum;
				//////ul = u;
				//////dl = v;
			////}
		//}
		
		
		cout << maxSubarrayXOR(n, ara) << "\n";
	}
	
	return 0;
}





































