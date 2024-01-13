#include<iostream>
#include<vector>

void bubbleSort(std::vector<int>& vec)
{
    for(int j{0}; j < vec.size()-1; ++j)
    {
        bool swapped{false};
        for(int i{0}; i < vec.size()-j-1; ++i)
        {
            if(vec[i] > vec[i+1])
            {
                std::swap(vec[i], vec[i+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

void getUserInput(std::vector<int>& vec)
{
    while(!std::cin.eof())
    {
        int num{};
        std::cin >> num;
        vec.push_back(num);
    }
}

void printVector(std::vector<int>& vec)
{
    std::cout << "{ ";
    for(int i{0}; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ((i == vec.size() -1)? " }\n" : ", ");
    }
}

int main()
{
    std::vector<int> vec;
    getUserInput(vec);
    printVector(vec);
    bubbleSort(vec);
    printVector(vec);
}
