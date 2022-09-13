#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    unordered_map<string, int> map;
    map["abc"] = 78;
    cout << map["abc"];
    cout << "Check Presence \n"
         << map.count("def") << endl;
    cout << "Check At \n"
         << map.at("abc");
}