#include <bits/stdc++.h>

using namespace std;

void task()
{
    int n, x, y, z, count=0;
    cin>>n;
    while(n--){
        cin>>x>>y>>z;

        if(x==1 && y==1 && z==1) count++;
        else if(x==1 && y==1) count++;
        else if(y==1 && z==1) count++;
        else if(x==1 && z==1) count++;
    }

    cout<<count<<endl;
}

int main()
{
    task();

    return 0;
}
