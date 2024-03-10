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

    void insertStringInTrie(const std::string& s                    ,
                            std::shared_ptr<TrieNode> current_node  ,
                            long unsigned current_index = 0         );

    std::shared_ptr<TrieNode> getlastNodeFromStartingString(std::shared_ptr<TrieNode> current_node  ,
                                                            const std::string& starting_string      ,
                                                            unsigned int current_index = 0          );

    void getAllStringsFromStartingNode( std::shared_ptr<TrieNode> current_node      ,
                                        std::string& current_string                 ,
                                        std::vector<std::string>& strings_in_trie   );

public:
    Trie(const bool is_case_sensitive = true);
    Trie(const Trie& t);
    virtual ~Trie(void);

    void insertString(const std::string s);
    std::vector<std::string> getAllStringsInTrie(void);
    std::vector<std::string> getAllStringsFromStartingString(std::string starting_string = "");
};

#endif
