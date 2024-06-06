/**
 * @author Macesuted (macesuted@qq.com)
 * @copyright Copyright (c) 2021
 */

#include <bits/stdc++.h>
using namespace std;

namespace io {
#define SIZE (1 << 20)
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55];
int f, qr;
inline void flush(void) { return fwrite(obuf, 1, oS - obuf, stdout), oS = obuf, void(); }
inline char getch(void) { return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++); }
inline void putch(char x) {
    *oS++ = x;
    if (oS == oT) flush();
    return;
}
void putstr(string str, int begin = 0, int end = -1) {
    if (end == -1) end = str.size();
    for (register int i = begin; i < end; i++) putch(str[i]);
    return;
}
template <typename T>
inline T read() {
    register T x = 0;
    for (f = 1, c = getch(); c < '0' || c > '9'; c = getch())
        if (c == '-') f = -1;
    for (x = 0; c <= '9' && c >= '0'; c = getch()) x = x * 10 + (c & 15);
    return x * f;
}
template <typename T>
inline void write(const T& t) {
    register T x = t;
    if (!x) putch('0');
    if (x < 0) putch('-'), x = -x;
    while (x) qu[++qr] = x % 10 + '0', x /= 10;
    while (qr) putch(qu[qr--]);
    return;
}
struct Flusher_ {
    ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io::getch;
using io::putch;
using io::putstr;
using io::read;
using io::write;

#define maxn 105
#define maxVal 200005

typedef pair<int, int> pii;

vector<int> answer;

bool f[maxVal];

int dfs(vector<pii> vec) {
    if (vec.size() == 1) return answer.push_back(vec[0].second), 1;
    memset(f, 0, sizeof(f));
    int sum = 0, pos = -1;
    bool check = true;
    for (vector<pii>::iterator i = vec.begin(); i != vec.end(); i++) {
        sum += i->first;
        if (i->first & 1) check = false, pos = i->second;
    }
    if (sum & 1) return 0;
    f[0] = true;
    for (vector<pii>::iterator i = vec.begin(); i != vec.end(); i++)
        for (register int j = maxVal - 1; j >= i->first; j--)
            f[j] |= f[j - i->first];
    if (!f[sum >> 1]) return 0;
    if (!check) return answer.push_back(pos), 1;
    for (vector<pii>::iterator i = vec.begin(); i != vec.end(); i++) i->first /= 2;
    return dfs(vec);
}

int main() {
    int n = read<int>();
    vector<pii> vec;
    vec.clear();
    for (register int i = 1; i <= n; i++) vec.push_back((pii){read<int>(), i});
    write(dfs(vec)), putch('\n');
    for (vector<int>::iterator i = answer.begin(); i != answer.end(); i++) write(*i), putch('\n');
    putch('\n');
    return 0;
}//awa