/**
    ***Bismillahir Rahmanir Rahim***
    
             Asad Bin Saber
**/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q, m;
    string s, t;
    vector<int> v;
    
    cin >> q;
    while(q--){
        cin >> s >> m;
        
        t.resize(m, 'a');
        
        int b[m];
        for(int K = 0; K < m; K++){
            cin >> b[K];
        }
        
        int cnt = 50;
        char c = 'z';
        while(cnt--){
            int num = 0;
            for(int K = 0; K < s.length(); K++){
                if(c == s[K]) num++;
            }
            
            for(int K = 0; K < m; K++){
                if(b[K] == 0){
                    v.push_back(K);
                    b[K] = -1;
                }
            }
            
            if(v.size() > num){
                c--;
                continue;
            }
            
            for(auto x:v){
                for(int K = 0; K < m; K++){
                    if(b[K] > 0) b[K] -= abs(x-K);
                }
            }
            for(auto x:v){
                t[x] = c;
            }
            for(int K = 0; K < s.length(); K++){
                s[K] = (s[K] == c ? 'a'-1 : s[K]);
            }
            
            v.clear();
            c--;
        }
        
        cout << t << "\n";
    }
    
    return 0;
}