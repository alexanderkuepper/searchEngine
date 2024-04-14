#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>

struct TrieNode {
    const std::string *validWord = nullptr;
    std::unordered_map<char, std::unique_ptr<TrieNode>> childNodes;

    void insertWord(const std::string &word) {
        TrieNode *node = this;
        for (auto letter : word) {
            if (node->childNodes.find(letter) == node->childNodes.end()) {
                node->childNodes[letter] = std::make_unique<TrieNode>();
            }
            node = node->childNodes[letter].get();
        }
        node->validWord = &word;
    }

    const std::string *findWord(const std::string &word) {
        TrieNode *node = this;
        for (auto letter : word) {
            if (node->childNodes.find(letter) == node->childNodes.end()) {
                return nullptr;
            }
            node = node->childNodes[letter].get();
        }
        return node->validWord;
    }

};

int main() {
    TrieNode trie;
    std::vector<std::string> words_to_insert = {
            "car",
            "bike",
            "cart",
            "plane"
    };
    for (auto &word: words_to_insert) {
        trie.insertWord(word);
    }

    auto word = trie.findWord("plane");
    if (word) {
        std::cout << "Word: " << *word << std::endl;
    } else {
        std::cout << "Word does not exist" << std::endl;
    }
}