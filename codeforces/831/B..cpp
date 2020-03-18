#include <bits/stdc++.h>

using namespace std;

void task()
{
    char first[27], second[27], standard[27], input[1001], output[1001];
    int k, len;

    scanf(" %[^\n]", first);
    scanf(" %[^\n]", second);
    scanf(" %[^\n]", input);

    for(int i=0; i<26; i++){
        k = first[i] - 'a';
        //cout<<k<<"->";
        standard[k] = second[i];
        //cout<<standard[k]<<"  ";
    }
    //cout<<standard<<endl;

    len = strlen(input);
    for(int i=0; i<len; i++){
        if(input[i]<'A' || (input[i]>'Z' && input[i]<'a') || input[i]>'z'){
            output[i]=input[i];
            continue;
        }

        if(input[i]>='A' && input[i]<='Z'){
            k = input[i] - 'A';
            output[i] = standard[k] - 'a' + 'A';
            continue;
        }
        k = input[i] - 'a';
        //cout<<k<<"-";
        output[i] = standard[k];
        //cout<<standard[k]<<"-";
        //cout<<output[i]<<"  ";
    }
    output[len] = '\0';

    cout<<output<<endl;
}

int main()
{
    task();

    return 0;
}
