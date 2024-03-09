#include "Trie.hpp"

Trie::Trie(const bool is_case_sensitive): root(std::make_shared<TrieNode>('\0', is_case_sensitive))
{
    std::cout << "Created new trie with root at: " << this->root << ". Case sensitivity: " << (is_case_sensitive ? "en" : "dis") << "abled." << std::endl;
}

Trie::Trie(const Trie& t): root(std::make_shared<TrieNode>(*(t.root)))
{
    std::cout << "Created Trie with root at: " << this->root << "by copying it from root at: " << t.root << "." << std::endl;
}

Trie::~Trie(void)
{
    std::cout << "Destroyed trie." << std::endl;
}

void Trie::insertStringInTrie(  const std::string& s                    ,
                                std::shared_ptr<TrieNode> current_node  ,
                                long unsigned int current_index         )
{
    if(current_index >= s.size() || current_node == nullptr)
        return;

    std::shared_ptr<TrieNode> tn = current_node->getPendingLetter(s[current_index]);

    if(tn == nullptr)
        current_node->addPendingNode(s[current_index]);
    
    tn = current_node->getPendingLetter(s[current_index]);

    ++current_index;
    this->insertStringInTrie(s, tn, current_index);
}

void Trie::insertString(const std::string s)
{
    this->insertStringInTrie(s, this->root);
}
