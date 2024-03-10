#include "Trie.hpp"

int main()
{
    Trie t(false);
    t.insertString("and"    );
    t.insertString("ant"    );
    t.insertString("dad"    );
    t.insertString("do"     );
    t.insertString("dance"  );
    t.insertString("dank"   );
    t.insertString("dank"   );

    Trie t2(t);

    std::cout << "Strings in t2:" << std::endl;
    for(auto s:t2.getAllStrings())
        std::cout << s << std::endl;
    
    std::string test_str = "an";
    std::shared_ptr test_ptr = t2.getlastNodeFromStartingString(t2.root, test_str);
    std::cout << "test_ptr->getTrieNodeLetter() = " << test_ptr->getTrieNodeLetter() << std::endl;
    if(test_ptr->getTrieNodeLetter() != '\0')
    {
        std::vector<char> test_ptr_pending_nodes = test_ptr->getShallowPendingChars();
        std::cout << "Pending nodes for test_ptr node: " << std::endl;
        for(char c:test_ptr_pending_nodes)
            std::cout << c << " ";
        std::cout << std::endl;
    }
    
    // t2.getAllStringsFromStartingString()
}