#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include <utility>

using namespace std;


pair<int, bool> helper(const unique_ptr<BinaryTreeNode<int>>& node){

  if(!node)
    return make_pair(0, true);

  auto left = helper(node->left);
  auto right = helper(node->right);

  return make_pair(
    max(left.first, right.first)+1,
    abs(left.first-right.first) <=1 && left.second && right.second );

}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.

  pair<int, bool> result = helper(tree);

  return result.second;
}


int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
