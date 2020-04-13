//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 13 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

#define    ll   long long

void task()
{
    int n, i=1, count=0, save2, save3;
    bool flag2, flag3;

    cin >> n;
    vector<int> ara(n+1);
    vector<bool> mark(n+1);
    vector<vector<int> > ans(n+1, vector<int> (3));

    for(int K=1; K<=n; K++) cin >> ara[K];

    while(i<=n){
        if(ara[i]==1){
            //cout << "hi" << endl;
            flag2 = flag3 = 0;
            for(int K=1; K<=n; K++){
                if(!mark[K] && !flag2 && ara[K]==2){
                    flag2 = 1;
                    save2 = K;
                    mark[K] = 1;
                }
                else if(!mark[K] && !flag3 && ara[K]==3){
                    flag3 = 1;
                    save3 = K;
                    mark[K] = 1;
                }
            }
            if(flag2==1 && flag3==1){
                mark[i] = 1;
                count++;
                //cout << "hi" << endl;
                ans[count][0] = i;
                ans[count][1] = save2;
                ans[count][2] = save3;
                //break;
            }
        }
        i++;
    }

    cout << count << endl;

    for(int K=1; K<=count; K++){
        cout << ans[K][0] << ' ' << ans[K][1] << ' ' << ans[K][2] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
