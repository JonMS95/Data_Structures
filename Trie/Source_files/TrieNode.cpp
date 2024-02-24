#include "TrieNode.hpp"

std::string TrieNode::getPendingNodesAsString(void)
{
    std::string ret = "{";
    
    for(int i = 0; i < this->pending_nodes.size(); i++)
    {
        ret += pending_nodes[i]->getTrieNodeLetter();

        if(i < (this->pending_nodes.size() - 1) )
            ret += ", ";
    }

    ret += '}';

    return ret;
}

TrieNode::TrieNode(char c): letter(c)
{
    std::cout << "Created Trie node with letter \'" << this->letter << "\' and no pending nodes." << std::endl;
}

TrieNode::TrieNode(char c, std::vector<std::shared_ptr<TrieNode>> nodes): letter(c), pending_nodes(nodes)
{
    std::cout << "Created Trie node with letter \'" << this->letter << "\' and a set of pending nodes." << std::endl;
}

TrieNode::TrieNode(char c, std::vector<char> nodes): letter(c)
{
    for(char n:nodes)
        this->pending_nodes.emplace_back(std::make_shared<TrieNode>(n));
    
    std::cout << "Created Trie node with letter \'" << this->letter << "\' and a set of pending nodes." << std::endl;
}

TrieNode::~TrieNode()
{
    std::cout << "Deleted node with letter \'" << this->letter << "\' and " << (this->pending_nodes.size() == 0 ? "no" : this->getPendingNodesAsString()) << " pending nodes." << std::endl;
}

char TrieNode::getTrieNodeLetter(void)
{
    return this->letter;
}

void TrieNode::addPendingNode(char c)
{
    this->pending_nodes.emplace_back(std::make_shared<TrieNode>(c));
}

std::shared_ptr<TrieNode> TrieNode::pendingNodeExists(char c)
{
    for(int i = 0; i < this->pending_nodes.size(); i++)
        if(c == this->pending_nodes[i]->letter)
            return this->pending_nodes[i];

    return nullptr;
}
