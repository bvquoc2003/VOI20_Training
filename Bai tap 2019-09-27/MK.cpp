#include <bits/stdc++.h>
using namespace std;
int main () {
    string str1="qưertyuiopasdfghjk", str2="xx";
    hash<string> str_hash;
    std::cout << "same hashes:\n" << std::boolalpha;
    std::cout << "str1 and str2: " << (str_hash(str1)==str_hash(str2)) << '\n';
    std::cout << "hash code str1: " << str_hash(str1) << '\n';
    return 0;
}