//
// Created by alex on 25.04.2024.
//

#ifndef TESTING_TEST_TRIENODE_H
#define TESTING_TEST_TRIENODE_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <queue>

class TrieNode {
private:
    const std::string *validWord = nullptr;
    std::unordered_map<char, std::unique_ptr<TrieNode>> childNodes;
public:
    void insertWord(const std::string &word);

    TrieNode *findPrefixNode(const std::string &prefix);

    std::vector<std::string> findWordsWithPrefix(const std::string &prefix);
};


#endif //TESTING_TEST_TRIENODE_H
