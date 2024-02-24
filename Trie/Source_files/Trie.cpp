#include "Trie.hpp"

Trie::Trie(void): root(std::make_shared<TrieNode>('\0'))
{
    std::cout << "Created new trie." << std::endl;
}

Trie::~Trie(void)
{
    std::cout << "Destroyed trie." << std::endl;
}

void Trie::insertStringInTrie(  std::string& s                          ,
                                std::shared_ptr<TrieNode> current_node  ,
                                int current_index                       )
{
    std::shared_ptr<TrieNode> tn = current_node->pendingNodeExists(s[current_index]);
    if(tn != nullptr)
        this->insertStringInTrie(s, tn, ++current_index);
    else
    {
        current_node->addPendingNode(s[current_index]);
        this->insertStringInTrie(s, current_node->pendingNodeExists(s[current_index]), ++current_index);
    }
}

void Trie::insertString(std::string s)
{
    this->insertStringInTrie(s, this->root, 0);
}
