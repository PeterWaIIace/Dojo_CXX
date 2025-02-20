

#include <iostream>
#include <string>
#include <vector> 

#define BLUE "\033[34m"
#define RED "\033[31m"
#define WHITE "\033[0m"

class TreeNode{
    public:

        TreeNode(int value){
            m_value = value;
        };

        void addLeft(TreeNode *node){
            left = node;
        };

        void addRight(TreeNode *node){
            right = node;
        };

        TreeNode* left = nullptr;
        TreeNode* right= nullptr;
    
        int getVal(){
            return m_value;
        }
    private:
        int m_value = 0;
};


void printTree(TreeNode* rootNode, std::string prefix = ""){ 
    std::cout << "value: " << rootNode->getVal() << WHITE << std::endl;
    if(rootNode->left){
        std::cout << prefix << BLUE"└-Left ";
        printTree(rootNode->left, prefix + " ");
    }
    if(rootNode->right){
        std::cout << prefix << RED"└-Right ";
        printTree(rootNode->right, prefix + " ");
    }
};

void findMaxPathLeaves(TreeNode* rootNode, int currentMaxVal, std::vector<int>* listOfMaxLeaves){
    if(rootNode->left){
        int val = rootNode->getVal();
        currentMaxVal = val > currentMaxVal ? val : currentMaxVal;
        findMaxPathLeaves(rootNode->left,currentMaxVal,listOfMaxLeaves);
    }
    if(rootNode->right){
        int val = rootNode->getVal();
        currentMaxVal = val > currentMaxVal ? val : currentMaxVal;
        findMaxPathLeaves(rootNode->right,currentMaxVal,listOfMaxLeaves);
    }
    if(not rootNode->left && not rootNode->right){
        // in case both splits do not exist, that node is a leaf
        int val = rootNode->getVal();
        if(val > currentMaxVal){
            listOfMaxLeaves->push_back(val);
        }
    }
}

int main(){
    TreeNode n1(4);
    TreeNode n1l1(5);
    TreeNode l1l2(9);
    TreeNode n1r1(2);
    TreeNode r1l2(6);
    TreeNode r1r2(8);
    n1.addLeft(&n1l1);
    n1l1.addLeft(&l1l2);
    n1.addRight(&n1r1);
    n1r1.addLeft(&r1l2);
    n1r1.addRight(&r1r2);

    printTree(&n1);
    std::cout << "=====TASK======" << std::endl;
    std::vector<int> list;
    findMaxPathLeaves(&n1,n1.getVal(),&list);
    std::cout << "[";
    for(auto n : list)
    {
        std::cout << n << ", ";
    }
    std::cout << "]"<<std::endl;
    return 0;
};