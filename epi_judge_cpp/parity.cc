#include "test_framework/generic_test.h"
#include <iostream>

using namespace std;


bool getBit(unsigned long long num, int i){

    unsigned long long one = 1, res;

    res = num & (one << i);

    return res != 0;
}

short Parity(unsigned long long x) {
  // TODO - you fill in here.

  int n = 0;
  for (int i=0; i<64; i++){
    n += getBit(x, i);
    // cout << i << " " << n << endl;
  }

  cout << n << endl;

  if(n%2 == 0) return 0;
  
  return 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
