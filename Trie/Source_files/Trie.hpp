#ifndef TRIE_HPP
#define TRIE_HPP

#include <memory>
#include <vector>
#include "TrieNode.hpp"

class Trie
{
private:
    std::shared_ptr<TrieNode> root;
    std::vector<std::shared_ptr<TrieNode>> pending_nodes;

    void insertStringInTrie(std::string& s                          ,
                            std::shared_ptr<TrieNode> current_node  ,
                            int current_index = 0                   );

public:
    Trie(void);
    virtual ~Trie(void);

    void insertString(std::string s);
};

#endif
