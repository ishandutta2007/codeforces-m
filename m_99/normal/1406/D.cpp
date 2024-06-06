#include <stdio.h>
#include <bits/stdc++.h>


#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

// Reference: https://en.wikipedia.org/wiki/Fenwick_tree
template <class T> struct fenwick_tree {
    using U = internal::to_unsigned_t<T>;

  public:
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

}  // namespace atcoder

using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo N
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000



int main(){

	int n;
	cin>>n;
	fenwick_tree<long long> B(n);
	vector<long long> a(n);
	long long ans = 0LL;
	rep(i,n){
		scanf("%lld",&a[i]);
		if(i==0)B.add(i,a[i]);
		else{
			B.add(i,a[i]-a[i-1]);
			ans += max(0LL,a[i]-a[i-1]);
		}
	}
	
	int q;
	cin>>q;
	
	rep(i,q+1){
		if(i!=0){
			int l,r;
			scanf("%d %d",&l,&r);
			long long X;
			scanf("%lld",&X);
			
			if(l>=2){
				long long x = B.sum(0,l-1),y = B.sum(0,l);
				ans -= max(0LL,y-x);
			}
			B.add(l-1,X);
			if(l>=2){
				long long x = B.sum(0,l-1),y = B.sum(0,l);
				ans += max(0LL,y-x);
			}
			
			if(r!=n){
				long long x = B.sum(0,r),y = B.sum(0,r+1);
				ans -= max(0LL,y-x);
			}
			if(r!=n)B.add(r,-X);
			if(r!=n){
				long long x = B.sum(0,r),y = B.sum(0,r+1);
				ans += max(0LL,y-x);
			}
			
		}
		long long temp = B.sum(0,1) - ans;
		if(temp%2==0)temp /= 2;
		else{
			temp = 1 + (temp-1)/2;
		}
		temp += ans;
		
		printf("%lld\n",temp);
	}
		
	
	
    return 0;
}