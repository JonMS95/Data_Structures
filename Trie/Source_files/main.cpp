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

    std::string test_string_1 = "and";
    std::cout << std::endl << "******* t2.getAllStringsFromStartingString(\"" << test_string_1 << "\") *******" << std::endl;
    for(std::string s : t2.getAllStringsFromStartingString(test_string_1))
        std::cout << s << std::endl;
    
    std::string test_string_2 = "da";
    std::cout << std::endl << "******* t2.getAllStringsFromStartingString(\"" << test_string_2 << "\") *******" << std::endl;
    for(std::string s : t2.getAllStringsFromStartingString(test_string_2))
        std::cout << s << std::endl;
    
    std::string test_string_3 = "ande";
    std::cout << std::endl << "******* t2.getAllStringsFromStartingString(\"" << test_string_3 << "\") *******" << std::endl;
        for(std::string s : t2.getAllStringsFromStartingString(test_string_3))
            std::cout << s << std::endl;
    
    std::cout << std::endl << "******* t2.getAllStringsInTrie() *******" << std::endl;
    for(std::string s : t2.getAllStringsInTrie())
        std::cout << s << std::endl;
}