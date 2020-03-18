#include <bits/stdc++.h>

using namespace std;

void task()
{
    int n, save, number, previous=0, situation=-1;
    bool flag=0;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>number;
        if(number>previous){
            if(situation!=-1){
                flag=1;
                break;
            }
            previous = number;
            situation = -1;
        }
        else if(number==previous){
            if(situation!=-1 && situation!=0){
                flag=1;
                break;
            }
            situation = 0;
        }
        else if(number<previous){
            previous = number;
            situation = 1;
        }
    }

    if(flag==1) cout<<"no"<<endl;
    else cout<<"yes"<<endl;
}

int main()
{
    task();

    return 0;
}
