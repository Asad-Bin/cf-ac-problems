// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

struct ordered_multiset {  // multiset supporting duplicating values in set
    ll len = 0;
    const ll ADD = 1000010;
    const ll MAXVAL = 1000000010;
    unordered_map<ll, ll> mp;  // hash = 96814
    tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> T;

    ordered_multiset() {
            len = 0;
            T.clear(), mp.clear();
    }

    inline void insert(ll x) {
            len++, x += MAXVAL;
            ll c = mp[x]++;
            T.insert((x * ADD) + c);
    }

    inline void erase(ll x) {
            x += MAXVAL;
           ll c = mp[x];
           if (c) {
            c--, mp[x]--, len--;
            T.erase((x * ADD) + c);
            }
    }

    inline ll kth(ll k) {                 // 1-based index,  returns the
            if (k < 1 || k > len) return -1;  // K'th element in the treap,
            auto it = T.find_by_order(--k);   // -1 if none exists
            return ((*it) / ADD) - MAXVAL;
    }

    inline ll lower_bound(ll x) {  // Count of value <x in treap
            x += MAXVAL;
            ll c = 0;
            return (T.order_of_key((x * ADD) + c));
    }

    inline ll upper_bound(ll x) {  // Count of value <=x in treap
            x += MAXVAL;
            ll c = mp[x];
            return (T.order_of_key((x * ADD) + c));
    }

    inline ll size() { return len; }  // Number of elements in treap
};

int main()
{
	ll t, n, q;
	string s;
	
	cin >> t;
	while(t--){
		cin >> n >> q;
		
		ll ara[n];
		//ordered_multiset ss;
		s.assign(n, '0');
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		ll ans = 0;
		
		for(int K = n-1; K >= 0; K--){
			if(ara[K] <= ans){
				s[K] = '1';
			}
			else{
				if(ans+1 <= q){
					s[K] = '1';
				}
				
				ans = min(ans+1, q);
			}
		}
		
		cout << s << "\n";
	} 
	
	return 0;
}




















































