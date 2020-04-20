//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 20 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    int t, n;
    string str;

    cin >> t;
    while(t--){
        cin >> n >> str;
        //cout << "   " << str << "\n";
        string a = "1", b = "1";
        //cout << K << "    " << a << "      " << b << "\n";


        for(int K=1; K<n; K++){
            if(a==b){
                if(str[K]=='0'){
                    a += "0";
                    b += "0";
                }
                else if(str[K]=='2'){
                    a += "1";
                    b += "1";
                }
                else if(str[K]=='1'){
                    a += "1";
                    b += "0";
                }
                else{
                    a += "2";
                    b += "1";
                }
            }
            else{
                if(str[K]=='0'){
                    a += "0";
                    b += "0";
                }
                else if(str[K]=='1'){
                    a += "0";
                    b += "1";
                }
                else if(str[K]=='2'){
                    a += "0";
                    b += "2";
                }
                else if(str[K]=='3'){
                    a += "0";
                    b += "3";
                }
            }
        }

        cout << a << "\n" << b << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}

