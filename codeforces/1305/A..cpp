#include<bits/stdc++.h>
using namespace std;

void task()
{
    int t, n, pos_a, pos_b, i, j;
    int a[1000], b[1000];

    cin>>t;
    while(t--){
        cin>>n;

        for(i=0; i<n; i++){
            cin>>a[i];
        }
        for(i=0; i<n; i++){
            cin>>b[i];
        }

        for(i=1; i<n; i++){
            pos_a = i;
            pos_b = i;
            for(j=i-1; j>=0; j--){
                if(a[pos_a]>a[pos_a-1]) break;

                if(a[pos_a]<a[pos_a-1]){
                    swap(a[pos_a], a[pos_a-1]);
                }
                pos_a--;
            }

            for(j=i-1; j>=0; j--){
                if(b[pos_b]>b[pos_b-1]) break;

                if(b[pos_b]<b[pos_b-1]){
                    swap(b[pos_b], b[pos_b-1]);
                }
                pos_b--;
            }
        }

        for(i=0; i<n; i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
        for(i=0; i<n; i++){
            cout<<b[i]<<' ';
        }
        cout<<endl;
    }
}

int main()
{
    task();

    return 0;
}
