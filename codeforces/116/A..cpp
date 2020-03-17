#include <bits/stdc++.h>

using namespace std;

void task()
{
    int n, now=0, enter, exit, capacity=0;

    cin>>n;
    while(n--){
        cin>>exit>>enter;

        now = now - exit + enter;
        if(now>capacity) capacity = now;
    }

    cout<<capacity<<endl;
}

int main()
{
    task();

    return 0;
}
