#include "tree.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<char> inputData = {'1', '2', '3'};

    PMTree myTree(inputData);

    std::cout << "All permutations:" << std::endl;

    std::vector<std::vector<char>> allPerms = getAllPerms(myTree);

    for (const std::vector<char>& singlePerm : allPerms) {
        for (char ch : singlePerm) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::vector<char> firstPerm = getPerm1(myTree, 1);
    std::cout << "Permutation #1: ";
    for (char ch : firstPerm) {
        std::cout << ch;
    }
    std::cout << std::endl;

    std::vector<char> secondPerm = getPerm2(myTree, 2);
    std::cout << "Permutation #2: ";
    for (char ch : secondPerm) {
        std::cout << ch;
    }
    std::cout << std::endl;

    return 0;
}
