#include <bits/stdc++.h>
using namespace std;

size_t karatsuba(size_t x, size_t y) {
  if (x < 10 && y < 10) {
    return x * y;
  }

  size_t n = max(to_string(x).length(), to_string(y).length());
  size_t m = ceil(n / 2.0);

  size_t pm = pow(10, m);
  size_t xH = floor(x / pm);
  size_t xL = x % pm;

  size_t yH = floor(y / pm);
  size_t yL = y % pm;

  size_t a = karatsuba(xH, yH);
  size_t d = karatsuba(xL, yL);
  size_t e = karatsuba(xH + xL, yH + yL) - a - d;

  size_t xy = (a * pm * pm) + (e * pm) + d;
  return xy;
}

int main() {
  size_t x = 123;
  size_t y = 321;
  cout << karatsuba(x, y) << "\n";
  return 0;
}