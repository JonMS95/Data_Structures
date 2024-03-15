#include "Trie.hpp"
#include <vector>
#include <string>

void testAddStringsToTrie(Trie& t, std::vector<std::string>& strings_to_add)
{
    for(std::string s:strings_to_add)
        t.insertString(s);
}

void testSearchStringsFromStartingString(Trie& t, std::vector<std::string>& strings_to_search)
{
    for(std::string string_to_search:strings_to_search)
    {
        std::cout << std::endl << "******* t2.getAllStringsFromStartingString(\"" << string_to_search << "\") *******" << std::endl;
        for(std::string s : t.getAllStringsFromStartingString(string_to_search))
            std::cout << s << std::endl;
    }
}

int main()
{
    std::vector<std::string> strings_to_add =
    {
        "and"    ,
        "ant"    ,
        "dad"    ,
        "do"     ,
        "dance"  ,
        "dank"   ,
        "dank"   
    };

    std::vector<std::string> strings_to_search = 
    {
        "and"   ,   // This one does exist in the Trie, but no other string starts with those characters.
        "da"    ,
        "ande"      // Last one does not exist in the Trie, so it should return nothing.
    };

    Trie t(false);

    testAddStringsToTrie(t, strings_to_add);

    Trie t2 = t;

    t.clear();

    testSearchStringsFromStartingString(t2, strings_to_search);
    
    std::cout << std::endl << "******* t2.getAllStringsInTrie() *******" << std::endl;
    for(std::string s : t2.getAllStringsInTrie())
        std::cout << s << std::endl;
    std::cout << std::endl;
}