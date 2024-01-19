#include "vector_functions.h"
#include <algorithm>
#include <iostream>

// write your print vector function here

int countMultiplesOfFive(std::vector<int> v)
{
    int count = 0;
    for(auto num : v) {
        if(num % 5 == 0) {
            count += 1;
        }
    }

    return count;
}


void addElements(std::vector<int> v, int x, int n)
{
    for(int i = 0; i < n; i++)
    {
        v.push_back(x);
    }
}