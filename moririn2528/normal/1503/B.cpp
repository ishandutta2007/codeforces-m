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
#include<complex>
#include<numeric>
#include<functional>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,LL> LP;
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

namespace sol{

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        vector<P> v1,v2;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if((i+j)%2)v1.push_back({i,j});
                else v2.push_back({i,j});
            }
        }
        for(i=0;i<n*n;i++){
            cin>>a;
            a--;
            P pos;
            if(v1.empty()){
                if(a==0)b=2;
                else b=0;
                pos=v2.back();
                v2.pop_back();
            }else if(v2.empty()){
                if(a==1)b=2;
                else b=1;
                pos=v1.back();
                v1.pop_back();
            }else if(a==0){
                b=1;
                pos=v1.back();
                v1.pop_back();
            }else{
                b=0;
                pos=v2.back();
                v2.pop_back();
            }
            cout<<b+1<<" "<<pos.first+1<<" "<<pos.second+1<<endl;
        }
    }
}

int main(){
    sol::solve();
}