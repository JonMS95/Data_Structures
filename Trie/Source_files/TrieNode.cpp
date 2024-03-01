#include "TrieNode.hpp"

TrieNode::TrieNode(char c, bool case_sensitive): letter(c), case_sensitive(case_sensitive)
{
    std::cout << "Created Trie node with letter \'" << this->letter << "\' and no pending nodes." << std::endl;
}

TrieNode::TrieNode(char c, std::vector<char> pending_letters, bool case_sensitive): letter(c), case_sensitive(case_sensitive)
{
    for(char p_letter:pending_letters)
        this->addPendingNode(p_letter);
}

TrieNode::~TrieNode()
{
    std::cout << "Deleted node with letter \'" << this->letter << "\' and " << (this->pending_letters.size() == 0 ? "no" : this->getPendingNodesAsString()) << " pending nodes." << std::endl;
}

TrieNode::TrieNode(const TrieNode& tn): letter(tn.letter), case_sensitive(tn.case_sensitive)
{
    for(auto it = tn.pending_letters.begin(); it != tn.pending_letters.end(); it++)
        this->addPendingNode(it->first);
    
    // for(auto it = this->pending_letters.begin(); it != this->pending_letters.end(); it++)
    //     TrieNode
}

void TrieNode::addPendingNode(char c)
{
    if(!this->case_sensitive)
        c = std::tolower(c);
    
    if(!this->pending_letters.count(c))
        this->pending_letters[c] = std::make_shared<TrieNode>(c, this->case_sensitive);
}

std::string TrieNode::getPendingNodesAsString(void)
{
    std::string ret = "{";

    std::map<char, std::shared_ptr<TrieNode>>::iterator it;
    std::map<char, std::shared_ptr<TrieNode>>::iterator it_last = this->pending_letters.end();
    --it_last;

    for(it = this->pending_letters.begin(); it != it_last; it++)
    {
        ret += it->first;
        ret += ", ";
    }

    ret += it_last->first;

    ret += '}';

    return ret;
}

char TrieNode::getTrieNodeLetter(void)
{
    return this->letter;
}

std::shared_ptr<TrieNode> TrieNode::getPendingLetter(char c)
{
    if(!this->case_sensitive)
        c = std::tolower(c);
    
    if(!this->pending_letters.count(c))
        return nullptr;
    
    return this->pending_letters[c];
}
