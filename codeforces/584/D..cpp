/**
    ***Bismillahir Rahmanir Rahim***
**/

#include <bits/stdc++.h>

using namespace std;

// vector<int> primes;
// bitset<1000005> mark;
// void sieve(int n)
// {
    // mark[1] = 1;
    // for(int K = 4; K <= n; K += 2) mark[K] = 1;
    // //primes.push_back(2);
    
    // for(int K = 3; K <= n; K += 2){
        // if(!mark[K]){
            // primes.push_back(K);
            
            // for(int L = K*K; L <= n; L += K) mark[L] = 1;
        // }
    // }
// }
bool check_prime(int x)
{
    if(x <= 1) return false;
    
    //for(int K = 0; K < (int)primes.size() && primes[K]*primes[K] <= x; K++){
    for(int K = 2; K*K <= x; K++){
        if(x%K == 0) return 0;
    }
    return 1;
}
int main()
{
    int n;
    
    cin >> n;
    
    //sieve(n);
    
    if(check_prime(n)){
        cout << 1 << "\n";
        cout << n << "\n";
    }
    else{
        if(check_prime(n-2)){
            cout << 2 << "\n";
            cout << 2 << ' ' << n-2 << "\n";
        }
        else{
            for(int K = n-1; K >= 0; K--){
                if(check_prime(K)){
                    int mid = n-K;
                    for(int L = 2; L < mid; L++){
                        if(check_prime(L) && check_prime(mid-L)){
                            cout << 3 << "\n";
                            cout << K << ' ' << L << ' ' << mid-L << "\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}