/*
USER: hoangmanhkhiem
TASK: SOCIALNE
ALGO: warshall
*/

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = 1000;

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, n, i, j, k, g[50][50], best, idx, cnt;
	char str[64];
	scanf("%d", &test);
	while(test--) {
		scanf("%s", str);
		for(i = 0; str[i]; i++) g[0][i] = (str[i]=='Y')? 1 : INF;
		for(n = i, j = 1; j < n; j++) {
			scanf("%s", str);
			for(i = 0; str[i]; i++) g[j][i] = (str[i]=='Y')? 1 : INF;
		}
		best = idx = 0;
		for(k = 0; k < n; k++) {
			for(cnt = i = 0; i < n; i++) {
				if(k != i && g[k][i] == INF) {
					for(j = 0; j < n; j++) {
						if(i != j) {
							if(g[k][j]!=INF && g[i][j]!=INF) break;
						}
					}
					if(j < n) cnt++;
				}
			}
			if(cnt > best) {
				best = cnt, idx = k;
			}
		}
		printf("%d %d\n", idx, best);
	}
	return 0;
}
