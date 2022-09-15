#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
string remove_duplicates(string s)
{
    unordered_map<char, bool> m;
    string s_d = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (m.count(s[i]) > 0)
        {
            continue;
        }
        s_d.push_back(s[i]);
        m[s[i]] = true;
    }
    return s_d;
}

int main()
{
    string s = "mynameisvivek";
    string s_d = remove_duplicates(s);
    cout << s_d;
}