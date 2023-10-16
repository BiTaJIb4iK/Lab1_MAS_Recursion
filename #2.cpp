
#include <iostream>
#include <string.h>

struct ListNode {
    int val;
    ListNode* next;
    //ListNode() : val(0), next(nullptr) {}
    //ListNode(int x) : val(x), next(nullptr) {}
    //ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* p = head->next;

    head->next = swapPairs(p->next);
    p->next = head;
    return p;
}

int main()
{
    
}
