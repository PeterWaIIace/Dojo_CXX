#include <iostream>
#include <string>

class LinkedNode{

    public:
        LinkedNode* next = nullptr;
        int m_value = 0;

        LinkedNode(int value){
            m_value = value;
        };
};

class LinkedList{

    public:
        void append(int value){
            LinkedNode* next = new LinkedNode(value);
            if(m_head)
            {
                __append(next,m_head);
            }
            else{
                m_head = next;
            }
        };

        void show()
        {
            std::cout << "[";
            __show(m_head);
            std::cout << "]" << std::endl;
        }

        void reverse(){
            if(!m_head) return;
            if(!m_head->next) return;

            __reverse(nullptr,m_head);
        }

    private:
        LinkedNode* m_head = nullptr;

        void __reverse(LinkedNode* prev,LinkedNode* current){
            if(!current) return;
            if(!current->next){
                m_head = current;
            };

            __reverse(current,current->next);
            current->next = prev;
        }

        void __append(LinkedNode* newNode,LinkedNode* current){
            if(current->next){
                __append(newNode,current->next);
            }
            else{
                current->next = newNode;
            }
        }

        void __show(LinkedNode* current){
            if(!current) return;

            std::cout << current->m_value << ", ";
            if(current->next){
                __show(current->next);
            }
        }

};

int main()
{
    LinkedList ll;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    ll.append(5);
    ll.show();
    ll.reverse();
    ll.show();
    return 0;
}