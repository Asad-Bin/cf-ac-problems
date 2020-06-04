    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        long long t, n;
        cin >> t;
        while(t--){
            cin >> n;
     
            long long ans = (long long)(n+1)/2;
            for(long long K=2, k=2; k<=n; K++, k*=2){
                ans+=K;
                ans += (long long)K*((n-k)/(k*2));
            }
     
            cout << ans << "\n";
        }
    }