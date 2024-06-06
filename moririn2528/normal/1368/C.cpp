#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
#include<set>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

vector<P> v2;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	v2.push_back(make_pair(0,0));
	v2.push_back(make_pair(0,1));
	v2.push_back(make_pair(1,0));
	v2.push_back(make_pair(1,1));
	for(i=0;i<n;i++){
		v2.push_back(make_pair(i+1,i+2));
		v2.push_back(make_pair(i+2,i+1));
		v2.push_back(make_pair(i+2,i+2));
	}
	cout<<v2.size()<<endl;
	for(auto pos:v2){
		cout<<pos.first<<" "<<pos.second<<endl;
	}
}