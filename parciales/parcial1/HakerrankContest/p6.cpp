#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
using Long = long long;

const Long infty = 10000;
const int N = 100001;

// Point data type
struct point {
  Long x, y;
}p[N];

// Sort criteria by X
bool sortX(const int &i, const int &j) {
  return p[i].x < p[j].x;
}

// Sort criteria by Y
bool sortY(const int &i, const int &j) {
  return p[i].y < p[j].y;
}

// f(x) = x**2
Long sqr(Long a) {
  return a * a;
}

// Euclidean distance
Long dist(int a, int b) {
  return sqr(p[a].x - p[b].x) + sqr(p[a].y - p[b].y);
}

int tmp[N], X, Y;
Long minDist;

Long brute(int ord[], int n) {
  sort(ord, ord + n, sortY);
  Long ret = infty;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ret = min(ret, dist(ord[i], ord[j]));
      if (minDist>ret) {
        minDist = ret;
        X = ord[i], Y = ord[j];
      }
    }
  }
  return ret;
}

Long solve(int ord[], int n) {
  if (n == 1) return infty;
  if (n <= 10) return brute(ord, n);
  int left = (n + 1) / 2;
  Long midx = p[ord[left]].x, delta = min(solve(ord, left), solve(ord + left, n - left));
  int i = 0, j = left, k = 0;
  while (i < left || j < n) {
    if (i != left && (j == n || p[ord[i]].y < p[ord[j]].y)) tmp[k++] = ord[i++];
    else tmp[k++] = ord[j++];
  }
  memcpy(ord, tmp, sizeof(int)*n);
  k = 0;
  for (int i = 0; i < n; i++) {
    int u = ord[i];
    if (sqr(p[u].x - midx) < delta) tmp[k++] = u;
  }
  Long ret = delta;
  for (int i = 0; i < k; i++) {
    int u = tmp[i];
    for (int j = i + 1; j < k; j++) {
      int v = tmp[j];
      if (sqr(p[u].y - p[v].y) >= ret) break;
      ret = min(ret, dist(u, v));
      if (minDist>ret) {
        minDist = ret;
        X = u, Y = v;
      }
    }
  }
  return ret;
}

int ord[N], n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld", &p[i].x, &p[i].y);
    ord[i] = i;
  }
  sort(ord, ord + n, sortX);
  minDist = infty;
  minDist = solve(ord, n);
  if (X>Y) swap(X, Y);
  printf("%d %d %.6lf\n", X,Y,(double)(sqrt(minDist+0.)));
  return 0;
}