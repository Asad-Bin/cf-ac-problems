// code from anachor    
#include <bits/stdc++.h>
    using namespace std;
     
    int binsearch(int lo, int hi)
    {
        if (lo>hi)      return -1;
        if (lo==hi)     return lo;
     
        int a=(lo+hi)/2;
        cout<<1<<" "<<a<<" "<<a+1<<endl;
        fflush(stdout);
     
        string s;
        cin>>s;
     
        if (s[0]=='T')  return  binsearch(lo, a);
        else            return  binsearch(a+1, hi);
    }
     
    int main ()
    {
        ios::sync_with_stdio(false);
        int n,k;
        cin>>n>>k;
     
        int x=binsearch(1, n);
        int y1=binsearch(1,x-1);
        int y2=binsearch(x+1,n);
     
        if (y1==-1)
        {
            cout<<2<<" "<<x<<" "<<y2<<endl;
            return 0;
        }
     
        if (y2==-1)
        {
            cout<<2<<" "<<x<<" "<<y1<<endl;
            return 0;
        }
     
        string s;
     
        cout<<1<<" "<<y1<<" "<<y2<<endl;
        fflush(stdout);
        cin>>s;
     
     
        if (s[0]=='T')     cout<<2<<" "<<x<<" "<<y1<<endl;
        else               cout<<2<<" "<<x<<" "<<y2<<endl;
    }