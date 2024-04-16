#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>

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

    TrieNode *findPrefixNode(const std::string &word) {
        TrieNode *node = this;
        for (auto letter: word) {
            if (node->childNodes.find(letter) == node->childNodes.end()) {
                return nullptr;
            }
            node = node->childNodes[letter].get();
        }
        return node;
    }

    std::vector<const std::string *> findWordsWIthPrefix(const std::string &prefix) {
        TrieNode *prefixNode = findPrefixNode(prefix);
        std::vector<TrieNode *> trieNodes{};
        std::vector<const std::string *> prefixWords{};
        if (prefixNode == nullptr) {
            return prefixWords;
        }
        trieNodes.push_back(prefixNode);
        for (auto index = 0; index < trieNodes.size(); index++) {
            for (auto const &[key, childNode]: trieNodes[index]->childNodes) {
                trieNodes.push_back(childNode.get());
                if (childNode->validWord != nullptr) {
                    prefixWords.push_back(childNode->validWord);
                }
            }
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
    auto x = trie.findWordsWIthPrefix("appli");
    for (auto y: x) {
        std::cout << *y << std::endl;
    }
}