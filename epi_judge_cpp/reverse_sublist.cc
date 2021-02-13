#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> ReverseListN(shared_ptr<ListNode<int>> head, int n) {

    auto current = head;
    shared_ptr<ListNode<int>> prev = nullptr;

    int k = 0;
    while(current && k++ <= n){
        auto tmp = current->next;
        current->next = prev;
        prev = current;
        current = tmp;
    }

    head->next = current;

    return prev;
}


shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start,
                                         int finish) {
  // TODO - you fill in here.

    if(start == 0)
        return L;

    shared_ptr<ListNode<int>> head = L;

    if(start == 1){
        return ReverseListN(head, finish-start);
    }else{
        int n = 2;
        while(n++ < start){
            head = head->next;
        }
        head->next = ReverseListN(head->next, finish-start);

        return L;
    }

}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "start", "finish"};
  return GenericTestMain(args, "reverse_sublist.cc", "reverse_sublist.tsv",
                         &ReverseSublist, DefaultComparator{}, param_names);
}
