#include <bits/stdc++.h>

using namespace std;

void task()
{
    int n, count=0;
    char str[51];

    cin>>n;
    scanf(" %[^\n]", str);

    char c = str[0];
    for(int i=1; i<n; i++){
        if(str[i]==c){
            count++;
        }
        else{
            c = str[i];
        }
    }

    cout<<count<<endl;
}

int main()
{
    task();

    return 0;
}
