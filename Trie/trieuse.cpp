#include <iostream>
#include "Trie.h"

using namespace std;

int main()
{
    Trie t;
    t.insertW("vivek");
    cout << t.searchW("vivek");
    cout << t.searchW("vikas");
    t.removeW("vivek");
    cout << t.searchW("vivek");
}