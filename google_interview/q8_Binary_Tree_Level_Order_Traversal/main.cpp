#include <iostream>
#include <vector>
#include <queue>

class Node{
    public:
        int m_value = 0;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int value) : m_value(value){};
};

// bfs
std::vector<std::vector<int>> levelValues(Node* root){
    std::vector<std::vector<int>> ret;

    if(!root) return ret;

    std::queue<std::vector<Node*>> level_queue;
    level_queue.push({root});

    while(level_queue.size())
    {

        std::vector<Node*> current_level = level_queue.front();
        level_queue.pop();
        std::vector<Node*> next_level;
        std::vector<int> level_values;
        for(Node* node: current_level)
        {
            level_values.push_back(node->m_value);
            if(node->left){
                next_level.push_back(node->left);
            }
            if(node->right){
                next_level.push_back(node->right);
            }
        }
        if(next_level.size()){
            level_queue.push(next_level);
        }
        ret.push_back(level_values);
    }
    return ret;
}

void show(std::vector<std::vector<int>> &output){
    std::cout << "[" ;
    for(auto o : output){
        std::cout << "[";
        for(auto v : o){
            std::cout << v << ", ";
        }
        std::cout << "]";
    }
    std::cout << "]" << std::endl;
}


int main(){
    Node n(3);
    Node nl1(9);
    Node nr1(20);
    Node l1r2(15);
    Node l1l2(7);

    n.left = &nl1;
    n.right = &nr1;
    nr1.left = &l1r2;
    nr1.right = &l1l2;

    std::vector<std::vector<int>> output = levelValues(&n);
    show(output);

    Node e2_n(3);
    Node e2_n_l1(9);
    e2_n.left = &e2_n_l1;

    Node e2_n_l1_l2(23);
    e2_n_l1.left = &e2_n_l1_l2;

    Node e2_n_l1_l2_l3(3);
    e2_n_l1_l2.left = &e2_n_l1_l2_l3;

    Node e2_n_l1_l2_r3(4);
    e2_n_l1_l2.right = &e2_n_l1_l2_r3;

    Node e2_n_r1(20);
    e2_n.right = &e2_n_r1;

    Node e2_n_r1_r2(15);
    e2_n_r1.right = &e2_n_r1_r2;

    Node e2_n_r1_r2_l3(17);
    e2_n_r1_r2.left = &e2_n_r1_r2_l3;

    Node e2_n_r1_l2(7);
    e2_n_r1.left = &e2_n_r1_l2;

    Node e2_n_r1_l2_l3(9);
    e2_n_r1_l2.left = &e2_n_r1_l2_l3;

    output = levelValues(&e2_n);
    show(output);

    return 0;
}