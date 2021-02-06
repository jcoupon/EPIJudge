#include <string>
#include <unordered_map>

#include "test_framework/generic_test.h"
using std::string;
using std::unordered_map;

unordered_map<char, int> charToDigit;
unordered_map<int, char> digitToChar;

string ConvertBase(const string& num_as_string, int b1, int b2) {

  char c;
  for(int i=0; i<16;++i){
    c = i < 10 ? '0'+i : 'A'+i-10;
    charToDigit[c] = i;
    digitToChar[i] = c;
  }

  if(num_as_string == "0")
    return num_as_string;

  int tmp = 0;
  bool isNegative = false;
  for(int i=0; i<num_as_string.size(); ++i){
    char c = num_as_string[num_as_string.size()-1-i];
    if(c != '-'){
      tmp += pow(b1, i)*charToDigit[c];
    }
    else{
      isNegative = true;
    }
  }

  string result = "";
  while(tmp > 0){
    result += digitToChar[tmp%b2];
    tmp = tmp/b2;
  }
  if(isNegative)
    result += '-';

  reverse(result.begin(), result.end());

  // TODO - you fill in here.
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_as_string", "b1", "b2"};
  return GenericTestMain(args, "convert_base.cc", "convert_base.tsv",
                         &ConvertBase, DefaultComparator{}, param_names);
}
