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
    ll arr[n];
    ll mi = 1e11,mii = -1, ma = -1e11, mai = -1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>ma){
            ma = arr[i];
            mai = i;
        }
        if(arr[i]<mi){
            mi = arr[i];
            mii = i;
        }
    }
    cout<<mii+1<<" "<<mai+1<<"\n";
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