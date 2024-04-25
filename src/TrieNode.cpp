//
// Created by alex on 25.04.2024.
//

#include "TrieNode.h"

void TrieNode::insertWord(const std::string &word) {
    TrieNode *node = this;
    for (auto letter: word) {
        if (node->childNodes.find(letter) == node->childNodes.end()) {
            node->childNodes[letter] = std::make_unique<TrieNode>();
        }
        node = node->childNodes[letter].get();
    }
    node->validWord = &word;
}

TrieNode *TrieNode::findPrefixNode(const std::string &prefix) {
    TrieNode *node = this;
    for (auto letter: prefix) {
        if (node->childNodes.find(letter) == node->childNodes.end()) {
            return nullptr;
        }
        node = node->childNodes[letter].get();
    }
    return node;
}

std::vector<std::string> TrieNode::findWordsWithPrefix(const std::string &prefix) {
    TrieNode *prefixNode = findPrefixNode(prefix);
    std::queue<TrieNode *> trieNodes{};
    std::vector<std::string> prefixWords{};

    if (prefixNode == nullptr) {
        return prefixWords;
    }
    trieNodes.push(prefixNode);
    while (!trieNodes.empty()) {
        TrieNode *currentNode = trieNodes.front();
        for (auto const &[key, childNode]: currentNode->childNodes) {
            trieNodes.push(childNode.get());
            if (childNode->validWord != nullptr) {
                prefixWords.push_back(*childNode->validWord);
            }
        }
        trieNodes.pop();
    }
    return prefixWords;
}
