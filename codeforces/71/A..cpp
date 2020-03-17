#include <bits/stdc++.h>

using namespace std;

void task()
{
    int n, t;
    char str[100];

    cin>>t;
    while(t--){
        scanf(" %[^\n]", str);

        n = strlen(str);

        if(n<=10) cout<<str<<endl;
        else cout<<str[0]<<n-2<<str[n-1]<<endl;
    }
}

int main()
{
    task();

    return 0;
}
