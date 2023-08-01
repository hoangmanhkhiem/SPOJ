/*
USER: zobayer
TASK: AGGRCOW
ALGO: binary search
*/

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
using namespace std;

#define DEBUG if(0)
#define PAUSE system("pause")
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define UB(s, e, x) upper_bound(s, e, x)
#define LB(s, e, x) lower_bound(s, e, x)
#define REV(s, e) reverse(s, e);
#define SZ(c) c.size()
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define i64 long long
#define ff first
#define ss second

template< class T > T sq(T &x) { return x * x; }
template< class T > T abs(T &n) { return (n < 0 ? -n : n); }
template< class T > T max(T &a, T &b) { return (!(a < b) ? a : b); }
template< class T > T min(T &a, T &b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T &a, T &b) { return (a < b ? a : a % b); }
template< class T > bool inside(T &a, T &b, T &c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

const int INF = 1000000001;
const double EPS = 1e-10;
const int MAX = 100001;

int a[MAX];

bool possible(int n, int c, int dist) {
	int i, put = 1, last = a[0];
	for(i = 1; i < n && put < c; i++) {
		if(a[i]-last >= dist) {
			put++;
			last = a[i];
		}
	}
	return (put == c);
}

int main() {
	int t, n, i, c, maxdiff, mindiff, middiff, best;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &c);
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a, a+n);
		maxdiff = INF;
		mindiff = best = 0;
		while(mindiff <= maxdiff) {
			middiff = (maxdiff + mindiff) >> 1;
			if(possible(n, c, middiff)) {
				setmax(best, middiff);
				mindiff = middiff + 1;
			}
			else maxdiff = middiff - 1;
		}
		printf("%d\n", best);
	}
	return 0;
}
