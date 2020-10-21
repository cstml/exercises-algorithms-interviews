#pragma once
#include <iostream>
#include <vector>

class Matrix{
public:
    template <class T>
    static void PrintM (std::vector<std::vector<T>>& mat)
    {
        for (std::vector<T> b : mat)
        {
            for (T j : b )
                std::cout<<j<<" ";
            std::cout << "\n";
        }
    }
};

