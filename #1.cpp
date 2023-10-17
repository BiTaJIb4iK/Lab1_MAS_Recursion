
#include <iostream>
#include <string.h>

// #3 Recursion
void PrintReverse_recur(std::string& str, int index) {
    if (index >= 0 && index < str.length()) {
        std::cout << str[index];
        PrintReverse_recur(str, index - 1);
    }
}

void PrintReverse(const std::string& str) {
    // #1 Printing in reverse each char int string
    for (int i = str.length() - 1; i >= 0; i--) {
        std::cout << str[i];
    }
    std::cout << '\n';

    // #2 Reversing string and printing it
    std::string s = str;
    std::reverse(s.begin(), s.end());

    std::cout << s << '\n';
}

int main()
{
    std::string str = "Tiger";
    PrintReverse(str);

    PrintReverse_recur(str, str.length() - 1);
}
