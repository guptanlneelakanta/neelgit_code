#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<long long>a(n);
    for(auto&x:a)cin>>x;
    long long ans=0;
    for(int i=0;i<n;i++){
        long long sum=0,mn=LLONG_MAX;
        for(int j=i;j<n;j++){
            sum+=a[j];
            mn=min(mn,a[j]);
            if(sum==(j-i+1)*mn) ans++;
        }
    }
    cout<<ans;
}
