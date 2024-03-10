#ifndef TRIE_HPP
#define TRIE_HPP

#include <memory>
#include <vector>
#include <string>
#include "TrieNode.hpp"

class Trie
{
private:
public: // move it to private
    std::shared_ptr<TrieNode> root;

private:
    void insertStringInTrie(const std::string& s                    ,
                            std::shared_ptr<TrieNode> current_node  ,
                            long unsigned current_index = 0         );
    void getAllStringsInTrie(   std::shared_ptr<TrieNode> current_node      ,
                                std::string& current_string                 ,
                                std::vector<std::string>& strings_in_trie   );
public: // move it to private
    std::shared_ptr<TrieNode> getlastNodeFromStartingString(  std::shared_ptr<TrieNode> current_node  ,
                                                                    const std::string& starting_string      ,
                                                                    unsigned int current_index = 0          );
    // std::vector<std::string> Trie::getAllStringsFromStartingNode(std::shared_ptr<TrieNode> current_node, std::string& starting_string, unsigned int current_index = 0);

public:
    Trie(const bool is_case_sensitive = true);
    Trie(const Trie& t);
    virtual ~Trie(void);

    void insertString(const std::string s);
    // std::vector<std::string> getAllStringsFromStartingString(const std::string& starting_string);
    std::vector<std::string> getAllStrings(void);
};

#endif
