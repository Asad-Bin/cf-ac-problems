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
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       ll c1,c2,c3,a1,a2,a3,a4,a5;
       cin>>c1>>c2>>c3>>a1>>a2>>a3>>a4>>a5;
       if(a1>c1||a2>c2||a3>c3)
       {
           cout<<"No\n";
       }
       else
       {
           c1-=a1,c2-=a2,c3-=a3;
           a1=a2=a3=0;
           a4=max(0ll,a4-c1),a5=max(0ll,a5-c2);
           if(a4+a5<=c3)
            cout<<"Yes\n";
           else
            cout<<"No\n";
       }
   }
}
