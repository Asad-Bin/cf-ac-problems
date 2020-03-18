#include <bits/stdc++.h>

using namespace std;

void task()
{
    char str[1001];

    scanf(" %[^\n]", str);

    if(str[0]>=97 && str[0]<=122) str[0] = str[0] - 'a' + 'A';

    cout<<str<<endl;
}

int main()
{
    task();

    return 0;
}
