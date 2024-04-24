#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <queue>

struct TrieNode {
    const std::string *validWord = nullptr;
    std::unordered_map<char, std::unique_ptr<TrieNode>> childNodes;

    void insertWord(const std::string &word) {
        TrieNode *node = this;
        for (auto letter: word) {
            if (node->childNodes.find(letter) == node->childNodes.end()) {
                node->childNodes[letter] = std::make_unique<TrieNode>();
            }
            node = node->childNodes[letter].get();
        }
        node->validWord = &word;
    }

    TrieNode *findPrefixNode(const std::string &prefix) {
        TrieNode *node = this;
        for (auto letter: prefix) {
            if (node->childNodes.find(letter) == node->childNodes.end()) {
                return nullptr;
            }
            node = node->childNodes[letter].get();
        }
        return node;
    }

    std::vector<const std::string *> findWordsWithPrefix(const std::string &prefix) {
        TrieNode *prefixNode = findPrefixNode(prefix);
        std::queue<TrieNode *> trieNodes{};
        std::vector<const std::string *> prefixWords{};

        if (prefixNode == nullptr) {
            return prefixWords;
        }
        trieNodes.push(prefixNode);
        while (!trieNodes.empty()) {
            TrieNode *currentNode = trieNodes.front();
            for (auto const &[key, childNode]: currentNode->childNodes) {
                trieNodes.push(childNode.get());
                if (childNode->validWord != nullptr) {
                    prefixWords.push_back(childNode->validWord);
                }
            }
            trieNodes.pop();
        }
        return prefixWords;
    }

};

int main() {
    TrieNode trie;
    std::vector<std::string> words_to_insert = {
            "apple", "apricot", "application", "apartment", "approve",
            "book", "bookmark", "bookstore",
            "border", "bottle", "boundary",
            "banana", "bank", "banner", "band", "ball", "ballet", "balance",
            "box", "boy", "buy"
    };

    for (auto &word: words_to_insert) {
        trie.insertWord(word);
    }
    auto words = trie.findWordsWithPrefix("ap");
    for (auto word: words) {
        std::cout << *word << std::endl;
    }
}