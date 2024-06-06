#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
// Please write the recurances once :(
void pre(){}
void solve(){
    int n;cin>>n;
    pair<int,pii>arr[n];
    vector<int>dp(n+1);
    for(int i=0;i<n;i++){
        cin>>arr[i].S.F>>arr[i].S.S;
        arr[i].F = arr[i].S.S - arr[i].S.F+1;
    }
    sort(arr,arr+n);
    for(int i=0;i<=n;i++){
        dp[i]=i-1;
    }
    for(int i=0;i<n;i++){
        if(arr[i].F==1){
            cout<<arr[i].S.F<<" "<<arr[i].S.S<<" "<<arr[i].S.S<<"\n";
            dp[arr[i].S.F] = arr[i].S.F;
        }else{
            cout<<arr[i].S.F<<" "<<arr[i].S.S<<" "<<dp[arr[i].S.F]+1<<"\n";
            dp[arr[i].S.F] = arr[i].S.S;
            dp[arr[i].S.S] = arr[i].S.F;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}