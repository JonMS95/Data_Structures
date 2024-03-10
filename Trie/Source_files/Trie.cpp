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

void Trie::getAllStringsInTrie( std::shared_ptr<TrieNode> current_node      ,
                                std::string& current_string                 ,
                                std::vector<std::string>& strings_in_trie   )
{
    current_string += current_node->getTrieNodeLetter();

    if(current_node->getShallowPendingChars().size() != 0)
        for(char c:current_node->getShallowPendingChars())
            this->getAllStringsInTrie(current_node->getPendingLetter(c), current_string, strings_in_trie);
    else
        strings_in_trie.emplace_back(current_string);
    
    if(current_string.size() > 0)
        current_string.pop_back();
}

std::shared_ptr<TrieNode> Trie::getlastNodeFromStartingString(std::shared_ptr<TrieNode> current_node, const std::string& starting_string, unsigned int current_index)
{
    if(current_node == nullptr)
        return nullptr;

    if(current_index < starting_string.size())
    {
        for(char c:current_node->getShallowPendingChars())
            if(c == starting_string[current_index])
            {
                ++current_index;
                return this->getlastNodeFromStartingString(current_node->getPendingLetter(c), starting_string, current_index);
            }
    }

    return current_node;
}

// std::vector<std::string> Trie::getAllStringsFromStartingNode(std::shared_ptr<TrieNode> current_node, std::string& starting_string, unsigned int current_index = 0)
// {
//     if(current_node)
//     if(current_node->getShallowPendingChars().size() != 0)
//     for(char c:current_node->getShallowPendingChars())
//         if(c == starting_string[current_index])
//         {
//             ++current_index;
//             this->getAllStringsFromStartingNode(current_node->getPendingLetter(c), starting_string, current_index);
//         }
// }

std::vector<std::string> Trie::getAllStrings(void)
{
    std::vector<std::string> strings_in_trie;
    std::string current_string = "";
    
    for(char c:this->root->getShallowPendingChars())
        this->getAllStringsInTrie(this->root->getPendingLetter(c), current_string, strings_in_trie);
    
    return strings_in_trie;
}
