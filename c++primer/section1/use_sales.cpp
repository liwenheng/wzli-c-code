#include<iostream>
#include"newSale.h"
using namespace std;

int main(void){
    
    Sale total;
    if (std::cin >> total)
    {
        Sale trans;
        while (std::cin >> trans)
        {
            if (total.isbn() == trans.isbn())
            {
                total += trans;
            }
            else
            {
                std::cout << total << std::endl;
                total = trans;
            }
            
            
        }
        std::cout << total << std::endl;
    }
    else
    {
        std::cerr << "No data?! "<< std::endl;
        return -1;
    }
    return 0;
}