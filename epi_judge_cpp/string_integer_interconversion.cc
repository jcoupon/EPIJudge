#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;


using namespace std;

string IntToString(int x) {
  
  if(x == 0) return "0";

  // will cause an overflow when converting to positive number
  if(x == INT32_MIN) return "-2147483648";

  long r;
  long m=10;
  string result = "";
  char sign = '+';


  if(x<0){
    sign = '-';
    x *= -1;
  }

  while(x>0){

    r = x%m;
    x -= r;
    result += r/(m/10)+'0';
    m *= 10;
  }
  if(sign=='-'){
    result += sign;
  }
  reverse(result.begin(), result.end());

  return result;
}

int StringToInt(const string& s) {
 
  int sign = +1;
  if(s[0] == '-') sign = -1;

  int multiple = 1;
  int result = 0;

  for (int i=s.size()-1;i>=0;i--){
    if('0' <= s[i] && s[i] <= '9'){
      result += (s[i]-'0')*multiple;
      multiple *= 10;
    }
  }

  return sign*result;
}

void Wrapper(int x, const string& s) {
  if (stoi(IntToString(x)) != x) {
    throw TestFailure("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailure("String to int conversion failed");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "s"};

  return GenericTestMain(args, "string_integer_interconversion.cc",
                         "string_integer_interconversion.tsv", &Wrapper,
                         DefaultComparator{}, param_names);
}
