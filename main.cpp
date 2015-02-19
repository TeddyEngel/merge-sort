//
//  main.cpp
//  MergeSort
//
//  Created by Teddy Engel on 19/02/2015.
//  Copyright (c) 2015 Teddy Engel. All rights reserved.
//

#include <vector>
#include <iostream>

#define INVALID -1

void PrintVectorInline(std::vector<int>& values)
{
    int i;
    
    for(i = 0; i < values.size(); i++)
    {
        std::cout << values[i] << ' ';
    }
    std::cout << std::endl;
}

void PrintVectorPos(std::vector<int>& values, const int &begin, const int &end)
{
    int i;
    
    for(i = begin; i < end; i++)
    {
        std::cout << values[i] << ' ';
    }
    std::cout << std::endl;
}

void PrintVector(std::vector<int>& values)
{
    int i;
    
    for(i = 0; i != values.size(); i++)
    {
        std::cout << values[i] << std::endl;
    }
}

// Merges the 2 collections left and right into a new collection
void Merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& result)
{  
    // Adding collection in order
    while (left.size() > 0 && right.size() > 0)
    {
        if (left[0] < right[0])
        {
            result.push_back(left[0]);
            left.erase(left.begin());
        }
        else
        {
            result.push_back(right[0]);
            right.erase(right.begin());   
        }
    }
    // Remaining bit
    if (left.size() > 0)
        result.push_back(left[0]);
    else if (right.size() > 0)
        result.push_back(right[0]);
    
}

// Splits the origin collection into 2 collections left and right, split at the middle
bool Divide(std::vector<int>& origin, std::vector<int>& left, std::vector<int>& right)
{
    if (origin.size() < 2)
        return false;
    int i = 0;
    int middle = origin.size() / 2;

    left.assign(origin.begin(), origin.begin() + middle);
    right.assign(origin.begin() + middle, origin.end());
    return true;
}

void MergeSort(std::vector<int>& values, std::vector<int>& result)
{
    std::vector<int> left;
    std::vector<int> right;
    std::vector<int> resultLeft;
    std::vector<int> resultRight;

    // If we can divide the collection in 2 collections
    if (Divide(values, left, right))
    {
        // We recursively merge sort the left collection...
        MergeSort(left, resultLeft);
        // ... and the right collection...
        MergeSort(right, resultRight);
        // ... and we merge both collections back into result, sorted
        Merge(resultLeft, resultRight, result);
    }
    else if (values.size() > 0)
    {
        // We just push value into result
        result.push_back(values[0]);
    }
}

int main(int argc, const char* argv[]) {
    std::vector<int> values = {10, 0, 2, 5, -4, 3, 2};
    std::vector<int> result;
    
    std::cout << "Unsorted collection:" << std::endl;
    PrintVector(values);
    MergeSort(values, result);
    std::cout << "Sorted collection:" << std::endl;
    PrintVector(result);
    return 0;
}
