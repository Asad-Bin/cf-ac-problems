#include<bits/stdc++.h>
using namespace std;

void task()
{
    long long int t,n,g,b,k,result;
    cin>>t;
    while(t--){
        cin>>n>>g>>b;

        k = n / 2;
        if((k*2) != n) k++;

        if(k<=g){
            cout<<n<<endl;
            continue;
        }

        result = k / g;
        unsigned long long int ans;
        if(k%g!=0){
            ans = result*g + result*b + k%g;
        }
        else {
            ans = result*g + (result-1)*b;
        }

        if(ans<n){
            cout<<n<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
}

int main()
{
    task();

    return 0;
}

