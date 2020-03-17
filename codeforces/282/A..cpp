#include <bits/stdc++.h>

using namespace std;

void task()
{
    int n, count=0;
    char str[4];
    cin>>n;
    while(n--){
        scanf(" %[^\n]", str);

        if(str[1]=='-') count--;
        else count++;
    }

    cout<<count<<endl;
}

int main()
{
    task();

    return 0;
}
