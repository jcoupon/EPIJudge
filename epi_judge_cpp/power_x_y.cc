#include "test_framework/generic_test.h"

double PowerHelper(const double &x, const int &y){

  if(y==1)
    return x;

  double ans = PowerHelper(x, y/2);
  ans *= ans;
  if(y%2 != 0)
    ans *= x;

  return ans;
}

double Power(double x, int y) {
  // TODO - you fill in here.

  if(y==0){
    return 1.0;
  }else if(y < 0){
    return PowerHelper(1/x, -y);
  }else{
    return PowerHelper(x, y);
  }

  return 0.0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "power_x_y.cc", "power_x_y.tsv", &Power,
                         DefaultComparator{}, param_names);
}
