#include <iostream>
#include <string>
#include "Trie.h"
using namespace std;

void insertSuffix(Trie t, string word)
{
    while (word.size())
    {
        t.insertW(word);
        word = word.substr(1);
    }
}

int main()
{
    Trie t;
    insertSuffix(t, "boyi");
    cout << t.searchPatterW("oy");
}