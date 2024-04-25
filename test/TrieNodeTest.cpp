//
// Created by alex on 25.04.2024.
//
#include "gtest/gtest.h"
#include "TrieNode.h"

class TrieNodeTest : public ::testing::Test {
protected:
    void SetUp() override {
        for (auto &word: words_to_insert) {
            trie.insertWord(word);
        }
    }

    void TearDown() override {
    }

    TrieNode trie;
    std::vector<std::string> words_to_insert = {
            "apple", "apricot", "application", "apartment", "approve",
            "book", "bookmark", "bookstore",
            "border", "bottle", "boundary",
            "banana", "bank", "banner", "band", "ball", "ballet", "balance",
            "box", "boy", "buy"
    };

};

TEST_F(TrieNodeTest, prefixTest) {

    std::vector<std::string> words = {"apple", "application"};
    ASSERT_EQ(trie.findWordsWithPrefix("appl"),words);
}