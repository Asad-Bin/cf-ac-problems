#include<bits/stdc++.h>

using namespace std;

void task()
{
    int len, count_0=0, count_1=0;
    char str[101];

    scanf(" %[^\n]", str);
    len = strlen(str);

    bool flag_0=0, flag_1=0;
    for(int i=0; i<len; i++){
        if(flag_0==0 && str[i]=='0'){
            flag_0 = 1;
            count_0++;
        }
        else if(flag_0==1 && str[i]=='0'){
            count_0++;
        }
        else if(flag_0==1 && str[i]=='1'){
            count_0=0;
        }

        if(flag_1==0 && str[i]=='1'){
            flag_1 = 1;
            count_1++;
        }
        else if(flag_1==1 && str[i]=='1'){
            count_1++;
        }
        else if(flag_1==1 && str[i]=='0'){
            count_1=0;
        }

        if(count_0>=7){
            cout<<"YES"<<endl;
            return;
        }
        else if(count_1>=7){
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
