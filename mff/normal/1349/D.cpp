#include <algorithm>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <experimental/optional>

namespace asl
{
    namespace modint
    {
        
        const int m1000000007 = 1000000007;
        
        const int m998244353 = 998244353;

        int MOD = m1000000007;

        void set_mod(int mod)
        {
            MOD = mod;
        }

        class Mint
        {
        public:
            int val;

            Mint(long long v = 0)
            {
                if (v >= 0)
                {
                    if (v < MOD)
                        val = v;
                    else
                        val = v % MOD;
                }
                else
                {
                    if (v >= -MOD)
                    {
                        val = v + MOD;
                    }
                    else
                    {
                        v %= MOD;
                        if (v < 0)
                            v += MOD;
                        val = v;
                    }
                }
            }

            static int mod_inv(int a, int m = MOD)
            {
                
                int g = m, r = a, x = 0, y = 1;

                while (r != 0)
                {
                    int q = g / r;
                    g %= r;
                    std::swap(g, r);
                    x -= q * y;
                    std::swap(x, y);
                }

                return x < 0 ? x + m : x;
            }

            Mint &operator+=(const Mint &other)
            {
                val += other.val;
                if (val >= MOD)
                    val -= MOD;
                return *this;
            }

            Mint &operator-=(const Mint &other)
            {
                val -= other.val;
                if (val < 0)
                    val += MOD;
                return *this;
            }

            static unsigned fast_mod(uint64_t x, unsigned m = MOD)
            {
#if !defined(_WIN32) || defined(_WIN64)
                return x % m;
#endif
                
                unsigned x_high = x >> 32, x_low = (unsigned)x;
                unsigned quot, rem;
                asm("divl %4\n"
                    : "=a"(quot), "=d"(rem)
                    : "d"(x_high), "a"(x_low), "r"(m));
                return rem;
            }

            Mint &operator*=(const Mint &other)
            {
                val = fast_mod((uint64_t)val * other.val);
                return *this;
            }

            Mint &operator/=(const Mint &other)
            {
                return *this *= other.inv();
            }

            friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
            friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
            friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
            friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }

            Mint operator-() const
            {
                return val == 0 ? 0 : MOD - val;
            }

            Mint inv() const
            {
                return mod_inv(val);
            }

            friend std::ostream &operator<<(std::ostream &stream, const Mint &m)
            {
                return stream << m.val;
            }
        };
    } 
} 

#define endl '\n'

using namespace std;
using namespace asl::modint;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set_mod(m998244353);

    int n;
    cin >> n;

    vector<int> a(n);
    int s = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s += a[i];
    }

    vector<Mint> pot(s + 1, 0);

    Mint m(s);

    for (int t = 0; t < s; ++t)
    {
        auto x = t ? pot[t - 1] : 0;
        auto y = pot[t];

        auto num = -y * n * m + m * n - m + x * n * n * t - y * n * n * t - x * n * t + y * 2 * n * t;
        auto den = (t - m) * n;
        pot[t + 1] = num / den;
    }

    Mint curpot;

    for (int i = 0; i < n; ++i)
    {
        curpot += pot[a[i]];
    }

    curpot -= pot[s];

    cout << curpot << endl;

    return 0;
}