#include <bits/stdc++.h>

using namespace std;

void task()
{
    char str[101];

    scanf(" %[^\n]", str);
    int len = strlen(str);

    for(int i=0; i<len; i++){
        if(str[i]=='H' || str[i]=='Q' || str[i]=='9'){
            cout<<"YES"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
}

int main()
{
    task();

    return 0;
}
