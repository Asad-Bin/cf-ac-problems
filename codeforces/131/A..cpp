#include <bits/stdc++.h>

using namespace std;

void task()
{
    char str[101];

    scanf(" %[^\n]", str);
    int len = strlen(str);

    bool flag = 0;
    for(int i=1; i<len; i++){
        if(str[i]>=97 && str[i]<=122){
            flag=1;
            break;
        }
    }

    if(flag==1) cout<<str<<endl;
    else{
        if(str[0]>=97 && str[0]<=122) str[0] = str[0] - 'a' + 'A';
        else str[0] = str[0] - 'A' + 'a';

        for(int i=1; i<len; i++){
            str[i] = str[i] - 'A' + 'a';
        }

        cout<<str<<endl;
    }
}

int main()
{
    task();

    return 0;
}
