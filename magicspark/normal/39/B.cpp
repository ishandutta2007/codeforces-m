#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int now=0;
vector<int>ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		if(x==now+1){
			ans.push_back(2001+i);
			now++;
		}
	}
	cout<<ans.size()<<endl;
	for(auto x:ans)cout<<x<<" ";
	return 0;
}