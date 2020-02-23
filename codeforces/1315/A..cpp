#include<bits/stdc++.h>
using namespace std;

void task()
{
    int t, a, b, x, y, x_max, y_max, max_, max_n;

    cin>>t;
    while(t--){
        cin>>a>>b>>x>>y;

        x_max = x;
        y_max = y;
        if(x_max<(a-x-1)) x_max=a-x-1;
        if(y_max<(b-y-1)) y_max=b-y-1;

        if(x_max*b>y_max*a){
            max_=x_max;
            max_n = b;
        }
        else {
            max_ = y_max;
            max_n = a;
        }

        if((x_max*y_max)>(max_*max_n)) cout<<(x_max*y_max)<<endl;
        else cout<<(max_*max_n)<<endl;
    }
}

int main()
{
    task();

    return 0;
}
