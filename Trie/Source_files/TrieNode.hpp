#ifndef TRIE_NODE_HPP
#define TRIE_NODE_HPP

#include <vector>
#include <memory>
#include <iostream>
#include <string>

class TrieNode
{
private:
    const char letter;
    std::vector<std::shared_ptr<TrieNode>> pending_nodes;
    
    std::string getPendingNodesAsString(void);

public:
    TrieNode(char c);
    TrieNode(char c, std::vector<std::shared_ptr<TrieNode>> nodes);
    TrieNode(char c, std::vector<char> nodes);
    virtual ~TrieNode(void);

    char getTrieNodeLetter(void);
    void addPendingNode(char c);
    std::shared_ptr<TrieNode> pendingNodeExists(char c);
};

#endif
