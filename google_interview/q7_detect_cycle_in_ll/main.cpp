#include <iostream>
#include <set>

class ListNode{
    public:
        ListNode* next = nullptr;
        int m_value = 0;
        ListNode(int value){
            m_value = value;
        }
};

bool detectCycle(ListNode *ln, std::set<ListNode*> &nodeTracker){
    if(nodeTracker.find(ln) != nodeTracker.end()){
        return true;
    }
    else{
        nodeTracker.insert(ln);
        if(ln->next)
        {
            return detectCycle(ln->next,nodeTracker);
        }
        return false;
    }
}

int main(){

    ListNode ln0(3);
    ListNode ln1(2); // <- cycle is here from 4th to 1st
    ListNode ln2(0);
    ListNode ln3(-4);

    ln0.next = &ln1;
    ln1.next = &ln2;
    ln2.next = &ln3;
    ln3.next = &ln1; // cycle
    std::set<ListNode*> nodeTracker1;
    std::cout << detectCycle(&ln0,nodeTracker1) << std::endl;


    ln0.next = &ln1;
    ln1.next = &ln2;
    ln2.next = &ln3;
    ln3.next = nullptr; // no cycle
    std::set<ListNode*> nodeTracker2;
    std::cout << detectCycle(&ln0,nodeTracker2) << std::endl;
    return 0;
}