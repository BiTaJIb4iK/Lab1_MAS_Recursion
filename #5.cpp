
#include <iostream>
#include <string.h>
#include <unordered_map>

double myPow(double x, int n) {
    if (n == 0) 
        return 1;

    double t = myPow(x, n / 2);

    if (n % 2) 
        return n < 0 ? 1 / x * t * t : x * t * t;
    else 
        return t * t;
}

int main()
{
    std::unordered_map<int, float> inputs = { {1, 2.3}, {5, 6.3}, {2, 4}, {-7, 7.3} };

    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        std::cout << "X = " << it->second << "\nN = " << it->first << "\nOutput : " << myPow(it->second, it->first) << "\n\n";
    }
}

/*
X = 2.3
N = 1
Output : 2.3

X = 6.3
N = 5
Output : 9924.37

X = 7.3
N = -7
Output : 9.0519e-07

X = 4
N = 2
Output : 16
*/