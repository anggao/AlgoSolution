#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(i, n) for (__typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
typedef long long llint;
typedef pair<int, int> PII;
/// BEGIN CUT HERE
inline void errf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
}

template<typename T>
inline void errf(const char *fmt, const vector<T>& v) {
  errf("{");
  FOR(i, v.size()) {
    errf(fmt, v[i]);
  }
  errf("}\n");
}
// TODO
/// END CUT HERE
#ifndef __WATASHI__
#define errf(fmt, ...) do { } while (false)
#endif

struct TheSwapsDivOne {
  double find(vector <string> sequence, int k);
};

double TheSwapsDivOne::find(vector <string> sequence, int k) {
  string seq = "";
  FOREACH (i, sequence) {
    seq += *i;
  }
  int n = seq.size();
  double x = 1.0, y = 0.0;
  int num = (n - 1) * (n - 2) / 2, den = n * (n - 1) / 2;
  FOR (i, k) {
    double xx = (num * x + (n - 1) * y) / den;
    double yy = (x + (den - 1) * y) / den;
    x = xx;
    y = yy;
  }
  printf("%lf %lf %lf\n", x, y, x + (n - 1) * y);

  llint s = 0;
  vector<llint> c(n, 0);
  FOR (i, n) {
    c[i] = (i + 1LL) * (n - i);
    s += c[i];
  }

  double ans = 0;
  FOR (i, n) {
    // printf("%d %lld\n", seq[i] - '0', c[i]);
    ans += (c[i] * x + (s - c[i]) * y) * (seq[i] - '0');
  }
  return ans / (n * (n + 1) / 2);
}

/// BEGIN CUT HERE
// TODO
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << "{";
  FOR(i, v.size()) {
    os << "\"" << v[i] << "\",";
  }
  os << "}";

  return os;
}

vector<bool> __eq__;

template<typename S, typename T>
void eq(int id, S v1, T v2) {
  ostringstream s1, s2;

  s1 << v1;
  s2 << v2;

  errf("Case #%d: ", id);
  if (s1.str() == s2.str()) {
    __eq__.push_back(true);
    errf("\033[1;32mPassed\033[0m\n");
  } else {
    __eq__.push_back(false);
    errf("\033[1;31mFailed\033[0m\n");
    errf("\tReceived \"%s\"\n", s1.str().c_str());
    errf("\tExpected \"%s\"\n", s2.str().c_str());
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

      {
        string sequenceARRAY[] = {"4", "77"};
        vector <string> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        TheSwapsDivOne theObject;
        eq(0, theObject.find(sequence, 1),10.0);
    }
    {
        string sequenceARRAY[] = {"4", "77"};
        vector <string> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        TheSwapsDivOne theObject;
        eq(1, theObject.find(sequence, 47),10.0);
    }
    {
        string sequenceARRAY[] = {"1", "1", "1", "1", "1", "1", "1"};
        vector <string> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        TheSwapsDivOne theObject;
        eq(2, theObject.find(sequence, 1000000),3.0);
    }
    {
        string sequenceARRAY[] = {"572685085149095989026478064633266980348504469", "19720257361", "9", "69"};
        vector <string> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        TheSwapsDivOne theObject;
        eq(3, theObject.find(sequence, 7),98.3238536775161);
    }

  int __pass__ = count(ALL(__eq__), true);
  int __fail__ = count(ALL(__eq__), false);
  if (__fail__ == 0) {
    errf("\033[1;32mAll %d Passed\033[0m\n", __pass__);
  } else if (__pass__ == 0) {
    errf("\033[1;31mAll %d Failed\033[0m\n", __fail__);
  } else {
    errf("\033[1;31m%d Passed; %d Failed\033[0m\n", __pass__, __fail__);
    if (__eq__[0]) {
      errf("\033[1;31mDid you reset global variables?\033[0m\n");
    }
  }
  errf("\033[1;33mPress any key to continue...\033[0m\n");
  getchar();

  return 0;
}

/*
 * __builtin_popcount __builtin_ctz make_pair
 * priority_queue
 * push_back
 * first second iterator const_iterator
 */
/*
 * vim: ft=cpp.doxygen
 */
/// END CUT HERE
