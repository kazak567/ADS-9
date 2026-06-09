#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class Tree {
 public:
    struct Node {
        char value;
        std::vector<Node*> children;

        explicit Node(char v = '\0') : value(v) {}
    };

    Node* root;

    explicit Tree(const std::vector<char>& data) {
        root = new Node();
        constructTree(root, data);
    }

    ~Tree() {
        deallocateTree(root);
    }

    void collect(Node* currNode,
                 std::vector<char>* pathVec,
                 std::vector<std::vector<char>>* permsVec) {
        if (currNode == nullptr) {
            return;
        }

        bool isRoot = (currNode->value == '\0');
        if (!isRoot) {
            pathVec->push_back(currNode->value);
        }

        if (currNode->children.empty()) {
            if (!pathVec->empty()) {
                permsVec->push_back(*pathVec);
            }
        } else {
            for (Node* childNode : currNode->children) {
                collect(childNode, pathVec, permsVec);
            }
        }

        if (!isRoot) {
            pathVec->pop_back();
        }
    }

 private:
    void constructTree(Node* parentNode, const std::vector<char>& availableItems) {
        if (availableItems.empty()) {
            return;
        }

        for (size_t idx = 0; idx < availableItems.size(); ++idx) {
            Node* newNode = new Node(availableItems[idx]);
            parentNode->children.push_back(newNode);

            std::vector<char> remainingItems;
            for (size_t jdx = 0; jdx < availableItems.size(); ++jdx) {
                if (idx != jdx) {
                    remainingItems.push_back(availableItems[jdx]);
                }
            }

            constructTree(newNode, remainingItems);
        }
    }

    void deallocateTree(Node* targetNode) {
        if (targetNode == nullptr) {
            return;
        }

        for (Node* childNode : targetNode->children) {
            deallocateTree(childNode);
        }

        delete targetNode;
    }
};

std::vector<std::vector<char>> getAllPerms(Tree& treeObj);
std::vector<char> getPerm1(Tree& treeObj, int targetIndex);
std::vector<char> getPerm2(Tree& treeObj, int targetIndex);

#endif  // INCLUDE_TREE_H_
