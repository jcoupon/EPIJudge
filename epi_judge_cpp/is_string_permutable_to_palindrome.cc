#include <string>
#include <unordered_map>

#include "test_framework/generic_test.h"
using std::string;
using namespace std;

bool CanFormPalindrome(const string& s) {
  // TODO - you fill in here.

  unordered_map<char, int> letterMap;

  for(auto c:s){
    letterMap[c]++;
  }

  int nOdd = 0;
  for(auto c:letterMap){
    nOdd += c.second%2 != 0;
  }
  return nOdd <= 1; // odd string

  if(s.size()%2 == 0){
    return nOdd == 0; // even string
  }
  else{
  }

}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_string_permutable_to_palindrome.cc",
                         "is_string_permutable_to_palindrome.tsv",
                         &CanFormPalindrome, DefaultComparator{}, param_names);
}
