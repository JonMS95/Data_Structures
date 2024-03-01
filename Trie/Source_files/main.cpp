#include "Trie.hpp"
#include "TrieNode.hpp"

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
}