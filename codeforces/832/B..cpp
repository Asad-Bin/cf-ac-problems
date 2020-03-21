#include <bits/stdc++.h>

using namespace std;

void task()
{
    char good[27], pattern[100001], query[100001];
    int ara[26];

    memset(ara, 0, 26);

    scanf(" %[^\n]", good);
    scanf(" %[^\n]", pattern);

    int n, len, pos, pattern_len;
    len = strlen(good);
    pattern_len = strlen(pattern);

    for(int i=0; i<len; i++){
        pos = good[i] - 'a';
        ara[pos] = 1;
    }

    cin>>n;
    while(n--){
        scanf(" %[^\n]", query);

        bool flag = 0, hi=0;
        len = strlen(query);

        if(pattern_len>(len+1)){
            cout<<"NO"<<endl;
            continue;
        }
        if(pattern_len>len){
            bool kk=0;
            for(int LL=0; LL<pattern_len; LL++){
                if(pattern[LL]=='*') kk=1;
            }
            if(kk==0){
                cout<<"NO"<<endl;
                continue;
            }
        }

        if(len>pattern_len) hi=1;

        if(len<(pattern_len-1)){
            cout<<"NO"<<endl;
            flag=1;
            continue;
        }
        else{
            for(int i=0, j=0; i<pattern_len && j<len; i++, j++){
                pos = query[j] - 'a';

                if(pattern[i]=='*'){
                    if(len==pattern_len){
                        pos = query[j] - 'a';
                        if(ara[pos]==1){
                            cout<<"NO"<<endl;
                            flag=1;
                            break;
                        }
                    }
                    else if(len==(pattern_len-1)) i++;
                    else if(len>pattern_len){
                        hi=0;
                        for(int ll=0; ll<(len-pattern_len+1); ll++)
                        {
                            pos = query[j+ll] - 'a';
                            if(ara[pos]==1) hi=1;
                            //cout<<"for "<<query[j]<<" hi = "<<hi<<endl;
                        }
                        if(hi==1) break;
                        j+=(len-pattern_len);
                        //break;
                    }
                }

                if(pattern[i]=='?' && ara[pos]!=1){
                    cout<<"NO"<<endl;
                    flag=1;
                    break;
                }
                else if(pattern[i]!=query[j] && pattern[i]!='?' && pattern[i]!='*'){
                    cout<<"NO"<<endl;
                    flag=1;
                    break;
                }
            }
        }

        if(flag==0 && hi==0) cout<<"YES"<<endl;
        else if(flag==0 && hi==1) cout<<"NO"<<endl;
    }
}

int main()
{
    task();

    return 0;
}
