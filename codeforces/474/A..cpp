//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 15 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

#define    ll   long long
#define    pi   acos(-1.0)

void task()
{
    char c, d;
    string one = "qwertyuiop0asdfghjkl;0zxcvbnm,./", str, ans;

    cin >> c >> str;

    int len = str.length();

    if(c=='R'){
        for(int K=0; K<len; K++){
            d = str[K];

            for(int L=1; L<32; L++){
                if(d==one[L] && one[L-1]!='0'){
                    ans+=one[L-1];
                    break;
                }
                else if(d==one[L] && one[L-1]=='0'){
                    ans+=one[L];
                    break;
                }
            }
        }
    }
    else if(c=='L'){
        for(int K=0; K<len; K++){
            d = str[K];

            for(int L=0; L<31; L++){
                if(d==one[L] && one[L+1]!='0'){
                    ans+=one[L+1];
                    break;
                }
                else if(d==one[L] && one[L+1]=='0'){
                    ans+=one[L];
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}

