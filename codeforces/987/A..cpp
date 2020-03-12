#include <bits/stdc++.h>

using namespace std;

void task()
{
    int n;
    map<string, int> thanos;
    thanos["purple"]=0;
    thanos["green"]=0;
    thanos["blue"]=0;
    thanos["orange"]=0;
    thanos["red"]=0;
    thanos["yellow"]=0;
    char str[7];
    cin>>n;
    while(n--){
        scanf(" %[^\n]", str);
        thanos[str]++;
    }

    int count=0;
    if(thanos["purple"]==0) count++;
    if(thanos["green"]==0) count++;
    if(thanos["blue"]==0) count++;
    if(thanos["orange"]==0) count++;
    if(thanos["red"]==0) count++;
    if(thanos["yellow"]==0) count++;

    cout<<count<<endl;
    if(thanos["purple"]==0) cout<<"Power"<<endl;
    if(thanos["green"]==0) cout<<"Time"<<endl;
    if(thanos["blue"]==0) cout<<"Space"<<endl;
    if(thanos["orange"]==0) cout<<"Soul"<<endl;
    if(thanos["red"]==0) cout<<"Reality"<<endl;
    if(thanos["yellow"]==0) cout<<"Mind"<<endl;
}

int main()
{
    task();

    return 0;
}
