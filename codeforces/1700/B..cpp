//. . .Bismillahir Rahmanir Rahim. . .
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';

int main()
{
    int t, n;
    string s, str;

    cin >> t;
    while(t--){
        cin >> n >> s;

        str.assign(n, '0');
        if(s[0] == '9'){
            int num = 11;
            //str[n-1] = num-(s[n-1]-'0') + '0';
            num = 10;
            char c = '1';
            for(int K = n-1; K >= 0; K--){
                if(s[K] <= c){
                    str[K] = c-s[K] + '0';
                    c = '1';
                //cout << K << ' ' << s[K] << ' ' << c << ' ' << str[K] << "\n";
                    continue;
                }
                else str[K] = 10+c-s[K] + '0';

                c = '0';
            }


//            if(s[n-1] == '1'){
//                str[n-1] = '0';
//            }
//            else if(s[n-1] == '0'){
//                str[n-1] = '1';
//            }
//            else{
//                str[n-1] = '9'-s[n-1]+'0'+2;
//            }
//
//            if(s[n-2] == '1'){
//                str[n-2] = '0';
//                str[0] = '9'-s[0]+2+'0';
//            }
//            else if(s[n-2] == '0'){
//                str[n-2] = '1';
//                str[0] = '9'-s[0]+2+'0';
//            }
//            else{
//                str[n-2] = '9'+1-s[n-2]+'0'+(s[n-1] == '1' ? 1 : 0);
//                str[0] = '9'-s[0]+1+'0';
//            }
//
//            for(int K = 1; K < n-2; K++) str[K] = '9'-s[K]+'0';

            cout << str << "\n";
        }
        else{
            for(int K = 0; K < n; K++) cout << '9'-s[K];
            cout << "\n";
        }
    }

    return 0;
}























