#include "../include/tree.h"
#include <iostream>
#include <vector>
#include <chrono>

void printPermutation(const std::vector<char>& perm) {
    for (char ch : perm) {
        std::cout << ch;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<char> inputData = {'1', '2', '3'};
    Tree myTree(inputData);

    std::cout << "=== Experiment 1: Basic Permutations (3 elements) ===" << std::endl;
    std::vector<std::vector<char>> allPerms = getAllPerms(myTree);
    std::cout << "Total permutations: " << allPerms.size() << std::endl;
    
    std::cout << "All permutations:" << std::endl;
    for (const std::vector<char>& singlePerm : allPerms) {
        printPermutation(singlePerm);
    }

    std::cout << "\nPermutation #1 (via getPerm1): ";
    printPermutation(getPerm1(myTree, 1));

    std::cout << "Permutation #2 (via getPerm2): ";
    printPermutation(getPerm2(myTree, 2));

    std::cout << "\n=== Experiment 2: Performance Benchmarking ===" << std::endl;
    
    std::vector<char> benchmarkData = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    Tree benchmarkTree(benchmarkData);
    
    int n = benchmarkData.size();
    int totalPermsCount = 1;
    for(int i = 1; i <= n; ++i) {
        totalPermsCount *= i;
    }

    std::cout << "Benchmarking with " << n << " elements (" 
              << totalPermsCount << " total permutations)..." << std::endl;

    auto startAll = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<char>> benchPerms = getAllPerms(benchmarkTree);
    auto endAll = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationAll = endAll - startAll;
    std::cout << "getAllPerms() took: " << durationAll.count() << " ms" << std::endl;

    auto startP1 = std::chrono::high_resolution_clock::now();
    std::vector<char> perm1Result = getPerm1(benchmarkTree, totalPermsCount);
    auto endP1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationP1 = endP1 - startP1;
    std::cout << "getPerm1() for index " << totalPermsCount << " took: " 
              << durationP1.count() << " ms" << std::endl;

    auto startP2 = std::chrono::high_resolution_clock::now();
    std::vector<char> perm2Result = getPerm2(benchmarkTree, totalPermsCount);
    auto endP2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationP2 = endP2 - startP2;
    std::cout << "getPerm2() for index " << totalPermsCount << " took: " 
              << durationP2.count() << " ms" << std::endl;

    std::cout << "\nVerification of the last permutation:" << std::endl;
    std::cout << "getPerm1 result: ";
    printPermutation(perm1Result);
    std::cout << "getPerm2 result: ";
    printPermutation(perm2Result);

    return 0;
}
