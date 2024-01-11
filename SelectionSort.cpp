#include<iostream>
#include<vector>

void selectionSort(std::vector<int>& vec)
{
    for(int i{0}; i < vec.size() - 1; ++i)
    {
        int min{i};
        for(int j{i+1}; j < vec.size(); ++j)
        {
            if(vec[min] > vec[j])
            {
                min = j;
            }
        }
        if(min != i )
        {
            std::swap(vec[min], vec[i]);
        }
    }
}


void printVec(std::vector<int>& vec)
{
    std::cout << "{ ";
    for(int i{0}; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ((i != vec.size() -1)? ", " : "}\n");
    }
}

int main()
{
    std::vector<int> input;
    while(!std::cin.eof())
    {
        int num{};
        std::cin >> num;
        input.push_back(num);
    }
    printVec(input);
    selectionSort(input);
    printVec(input);
}
