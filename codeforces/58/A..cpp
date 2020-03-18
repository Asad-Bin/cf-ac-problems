#include <bits/stdc++.h>

using namespace std;

void task()
{
    char str[101], hello[] = "hello";

    scanf(" %[^\n]", str);

    int len = strlen(str), count=0;

    char c = hello[0];
    for(int i=0; i<len; i++){
        if(str[i]==c){
            count++;
            c = hello[count];
        }
    }

    if(count==5) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    task();

    return 0;
}
