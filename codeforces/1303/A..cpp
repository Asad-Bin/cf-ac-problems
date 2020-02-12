#include<bits/stdc++.h>
using namespace std;

void task()
{
    int t, k, flag, count;
    char str[101];
    cin>>t;
    while(t--){
        scanf(" %[^\n]", str);

        int length = strlen(str);

        k=0, flag=0, count=0;
        for(int i=0; i<length; i++){
            if(str[i]=='0') k++;
            else if(str[i]=='1'){
                if(flag==0){
                    flag=1;
                    k=0;
                    continue;
                }

                count += k;
                k=0;
            }
        }

        cout<<count<<endl;
    }
}

int main()
{
    task();

    return 0;
}
