#include<bits/stdc++.h>

using namespace std;

void task()
{
    char first[101], last[101];

    scanf(" %[^\n]", first);
    scanf(" %[^\n]", last);

    int len = strlen(first);

    for(int i=0; i<len; i++){
        if(first[i]>=65 && first[i]<=91){
            first[i] = first[i] + 'a' - 'A';
        }
        if(last[i]>=65 && last[i]<=91){
            last[i] = last[i] + 'a' - 'A';
        }
    }

    for(int K=0; K<len; K++){
        if(first[K]>last[K]){
            cout<<'1'<<endl;
            return;
        }
        if(first[K]<last[K]){
            cout<<"-1"<<endl;
            return;
        }
    }

    cout<<'0'<<endl;
}

int main()
{
    task();

    return 0;
}
