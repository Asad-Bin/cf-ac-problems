//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
typedef long long ll;
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}
ll lcm(ll a,ll b){ return (a*b)/gcd(a,b);}
ll ncr(ll n,ll r){ ll ans=1;for(ll i=1;i<=r;i++) ans=(ans*(n-i+1))/i;return ans;}
#define PI 3.14159265
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       ll n;
       cin>>n;
       map<pair<ll,ll>,ll> ar;
       for(int i=0;i<n;i++)
       {
           ll x,y,a,b,temp;
           cin>>x>>y>>a>>b;
           x=x-a,y=y-b;
           temp=abs(gcd(x,y));
           ar[make_pair(x/temp,y/temp)]++;
        }
        ll ans=0;
        for(auto it : ar)
        {
           ll x,y,temp;
           x=it.first.first,y=it.first.second;
           if(x>=0&&y>=0)
           {

               if(x==0&&y==0)
                temp=0;
               else if(x==0)
                temp=ar[make_pair(x,-y)];
               else if(y==0)
                temp=ar[make_pair(-x,y)];
               else
                temp=ar[make_pair(-x,-y)];
           }
           else if(x>=0)
            temp=ar[make_pair(-x,-y)];
           else if(y>=0)
            temp=ar[make_pair(-x,-y)];
           else
           temp=ar[make_pair(-x,-y)];
           ans=ans+temp*it.second;
           ar[make_pair(x,y)]=0;
        }
        cout<<ans<<endl;
   }
}
