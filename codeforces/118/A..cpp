#include <bits/stdc++.h>

using namespace std;

void task()
{
    int ll=0;
    char str[101], copy_[201];

    scanf(" %[^\n]", str);
    //printf("%s\n", str);

    int k = strlen(str);

    for(int i=0; i<k; i++){
        if(str[i]=='a' || str[i]=='e' || str[i]=='y' || str[i]=='Y' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
            continue;
        }

        if(str[i]>='A' && str[i]<='Z'){
            copy_[ll] = '.';
            ll++;
            copy_[ll] = str[i]-'A'+'a';
            ll++;
        }
        else{
            copy_[ll] = '.';
            ll++;
            copy_[ll] = str[i];
            ll++;
        }
    }

    for(int i=0; i<ll; i++){
        cout<<copy_[i];
    }
    cout<<endl;
}

int main()
{
    task();

    return 0;
}
