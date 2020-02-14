#include<bits/stdc++.h>
using namespace std;

void task()
{
    int t, flag, length;
    string s1, s2, s3;

    cin>>t;
    while(t--){
        cin>>s1;
        cin>>s2;
        cin>>s3;

        length = s1.length();
        flag = 0;

        for(int i=0; i<length; i++){
            if(s1[i]!=s3[i]){
                if(s2[i]!=s3[i]){
                    flag=1;
                    break;
                }
            }
        }

        if(flag==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}

int main()
{
    task();

    return 0;
}
