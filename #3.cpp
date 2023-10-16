
#include <iostream>
#include <string.h>
#include <unordered_map>

int F(int n, int& func_calls) {
    if (n < 0)
        throw "Error, value is less then 0!";

    func_calls++;

    if (n <= 1)
        return n;

    return F(n - 1, func_calls) + F(n - 2, func_calls);
}

int F2(int n, int& func_calls, std::unordered_map<int, int>& map) {
    if (n < 0)
        throw "Error, value is less then 0!";

    func_calls++;

    if (n <= 1) {
        map[n] = n;
        return n;
    }
    int value = 0;

    if (map.find(n - 1) != map.end()) {
        value += map[n - 1];
    }
    else {
        int l_val = F2(n - 1, func_calls, map);
        map[n - 1] = l_val;
        value += l_val;
    }

    if (map.find(n - 2) != map.end()) {
        value += map[n - 2];
    }
    else {
        int l_val = F2(n - 2, func_calls, map);
        map[n - 2] = l_val;
        value += l_val;
    }

    return value;
}

int main()
{
    const int n = 15;

    int func_calls = 0;
    std::cout << F(n, func_calls) << '\n';

    std::cout << "Func Calls : " << func_calls << '\n';

    func_calls = 0;

    std::unordered_map<int, int> map;

    std::cout << F2(n, func_calls, map) << '\n';

    std::cout << "Func Calls : " << func_calls << '\n';

}

/*
F(15)

OUTPUT : 

F():

610
Func Calls : 1973


F2() using map to store data

610
Func Calls : 16

*/
