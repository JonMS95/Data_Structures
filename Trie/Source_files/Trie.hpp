#ifndef TRIE_HPP
#define TRIE_HPP

#include <memory>
#include <vector>
#include <string>
#include "TrieNode.hpp"

class Trie
{
private:
    std::shared_ptr<TrieNode> root;
    bool case_sensitive;

    void insertStringInTrie(const std::string& s                    ,
                            std::shared_ptr<TrieNode> current_node  ,
                            long unsigned current_index = 0         );

public:
    Trie(bool is_case_sensitive = true);
    virtual ~Trie(void);

    void insertString(const std::string s);
};

#endif
