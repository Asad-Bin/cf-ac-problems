#include <bits/stdc++.h>

using namespace std;

 void task()
 {
     char str[101];

     scanf(" %[^\n]", str);

     int len = strlen(str);

     int x_1=0, x_2=0, x_3=0;

     for( int i=0; i<len; i+=2){
        if(str[i]=='1') x_1++;
        else if(str[i]=='2') x_2++;
        else if(str[i]=='3') x_3++;
     }

     for( int i=0; i<len; i+=2){
        if(x_1>0){
            str[i]='1';
            x_1--;
        }
        else if(x_2>0){
            str[i]='2';
            x_2--;
        }
        else if(x_3>0){
            str[i]='3';
            x_3--;
        }
     }

     cout<<str<<endl;
 }

int main()
{
    task();

    return 0;
}
