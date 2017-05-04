#include <cstdio>
#include <string>
#include <vector>

// Format floating point number with fixed precision though no trailing zeros.
std::string format_number(double n, int precision = 5) {
  // Special-case zero (and thus negative zero).
  if (n == 0.0f) return "0";
  static const int SIZE = 64;
  char buffer[SIZE];
  int len = snprintf(buffer, SIZE, "%.*f", precision, n);
  int i = std::min(SIZE - 1, len);
  // Strip off trailing fractional zeros and decimal point.
  while(i > 0) {
    switch(buffer[i]) {
      case '.': buffer[i] = '\0'; break;
      case '0': buffer[i] = '\0'; // Fall through to next case.
      case '\0':
        i--;
        continue;
      default:
        break;
    }
    break;
  }
  return std::string(buffer);
}

void test() {
  std::vector<double> numbers = {
    18014398509481984, // 2^54
    1125899906842624,
    140737488355328,
    17592186044416,
    1099511627776,
    137438953472,
    17179869184,
    1073741824,
    134217728,
    16777216,
    1048576,
    131072,
    16384,
    1024,
    128,
    16,
    1,
    0.0,
    -0.0,
    0.5,
    0.25,
    0.125,
    0.0625,
    0.03125,
    0.015625,
    0.0078125,
    0.00390625,
    0.001953125,
    0.0009765625,
    0.00048828125,
    0.000244140625,
    0.0001220703125,
    0.00006103515625,
    0.000030517578125,
    10000001.10000001,
    1000001.1000001,
    100001.100001,
    10001.10001,
    1001.1001,
    101.101,
    11.11,
    1.1,
    10.01,
    100.001,
    1000.0001,
    10000.00001,
    100000.000001,
    1000000.0000001,
    10000000.00000001,
    .1,
    .01,
    .001,
    .0001,
    .111111,
    .0111111,
    .0011111,
    .0001111,
    .0000111,
    .0000011,
    .0000011,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
    10000000000,
    100000000000,
    1000000000000,
    10000000000000,
    100000000000000,
  };

  for (auto n : numbers) {
    printf("%-26.8f -> %s\n", n, format_number(n, 6).c_str());
  }
}

int main(int argc, const char * argv[]) {
  test();
  return 0;
}
