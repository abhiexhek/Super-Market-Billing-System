#include <iostream>
#include "Bill.h"
int main()
{
    Bill objB;
    bool exit = false;
    while (!exit)
    {
        system("clear");
        int value;
        std::cout<<"\tWelcome To Super Market Billing System"<<std::endl;
        std::cout<<"\t**************************************"<<std::endl;
        std::cout<<"\t\t1. Add Item."<<std::endl;
        std::cout<<"\t\t2. Print Bill."<<std::endl;
        std::cout<<"\t\t3. Exit."<<std::endl;
        std::cout<<"\t\tEnter Choice: ";
        std::cin>>value;

        switch (value)
        {
        case 1:
            system("clear");
            addItem(objB);
            sleep(2);
            break;
        
        case 2:
            printBill();
            break;

        case 3:
            system("clear");
            exit = true;
            std::cout<<"\tGood Luck!"<<std::endl;
            sleep(2);
            break;

        default:
            break;
        }
    }
}
