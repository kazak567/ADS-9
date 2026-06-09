// Copyright 2026 NNTU-CS
#include <vector>

#include "../include/tree.h"

static int computeFactorial(int n) {
    int res = 1;
    int multiplier = 2;

    while (multiplier <= n) {
        res *= multiplier;
        ++multiplier;
    }

    return res;
}

std::vector<std::vector<char>> getAllPerms(PMTree& treeObj) {
    std::vector<std::vector<char>> permsVec;
    std::vector<char> pathVec;

    treeObj.collect(treeObj.root, &pathVec, &permsVec);

    return permsVec;
}

std::vector<char> getPerm1(PMTree& treeObj, int targetIndex) {
    std::vector<std::vector<char>> allPermutations =
        getAllPerms(treeObj);

    if (targetIndex < 1 ||
        targetIndex > static_cast<int>(allPermutations.size())) {
        return std::vector<char>();
    }

    return allPermutations[targetIndex - 1];
}

std::vector<char> getPerm2(PMTree& treeObj, int targetIndex) {
    std::vector<char> permResult;

    if (targetIndex <= 0) {
        return permResult;
    }

    int totalPermutations = computeFactorial(
        static_cast<int>(treeObj.root->children.size()));

    if (targetIndex > totalPermutations) {
        return std::vector<char>();
    }

    PMTree::Node* currNode = treeObj.root;
    int currentIndex = targetIndex - 1;

    while (!currNode->children.empty()) {
        int childrenCount =
            static_cast<int>(currNode->children.size());
        int branchFactorial =
            computeFactorial(childrenCount - 1);

        int selectedBranch = currentIndex / branchFactorial;

        currNode = currNode->children[selectedBranch];
        permResult.push_back(currNode->value);

        currentIndex %= branchFactorial;
    }

    return permResult;
}
