#ifndef TRIE_NODE_HPP
#define TRIE_NODE_HPP

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <cctype>
#include <map>

class TrieNode
{
private:
    const char letter;
    const bool case_sensitive;
    std::map<char, std::shared_ptr<TrieNode>> pending_letters;
    
    std::string getPendingNodesAsString(void);

public:
    TrieNode(void) = delete;
    TrieNode(char c, bool case_sensitive = false);
    TrieNode(char c, std::vector<char> pending_letters, bool case_sensitive = false);
    virtual ~TrieNode(void);
    TrieNode(const TrieNode& tn);

    char getTrieNodeLetter(void);
    void addPendingNode(char c);
    std::shared_ptr<TrieNode> getPendingLetter(char c);
};

#endif
