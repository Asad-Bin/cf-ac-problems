#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

void task()
{
    int t, n, x, p;


    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<int> ara(205, 0);

        for(int i=0; i<n; i++){
            cin>>p;
            ara[p]=1;
        }

        int count=0;
        for(int i=1; i<=201; i++){
            if(x>0 && ara[i]==0){
                ara[i]=1;
                x--;
            }
            if(x==0) break;
        }
        for(int i=1; i<=201; i++){
            if(ara[i]==0){
                cout<<i-1<<endl;
                break;
            }
        }
    }
}

int main()
{
    task();

    return 0;
}
