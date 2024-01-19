#include <iostream>
#include "Bill.h"
void addItem(Bill b)
{
    bool close = false;
    while (!close)
    {
        int choice;
        std::cout<<"\t1.Add."<<std::endl;
        std::cout<<"\t2.Close."<<std::endl;
        std::cout<<"\tEnter Choice: ";
        std::cin>>choice;
        
        if(choice == 1)
        {
            system("clear");
            std::string item;
            double rate;
            int quant;

            std::cout<<"\tEnter Item Name: ";
            std::cin>>item;
            b.setItem(item);

            std::cout<<"\tEnter Rate Of Item: ";
            std::cin>>rate;
            b.setRate(rate);

            std::cout<<"\tEnter Quantity Of Item: ";
            std::cin>>quant;
            b.setQuant(quant);

            std::ofstream out("bill.txt",std::ios::app);
            if(!out)
            {
                std::cout<<"\tError: File Can't Open!"<<std::endl;
            }
            else
            {
                out<<"\t"<<b.getItem()<<" : "<<b.getRate()
                <<" : "<<b.getQuant()<<std::endl<<std::endl;
            }
            out.close();
            std::cout<<"\tItem Added Succesfull"<<std::endl;
            sleep(1);
        }
        else if(choice == 2)
        {
            system("clear");
            close = true;
            std::cout<<"\tBack To Main Menu!"<<std::endl;
            sleep(1);
        }
    }
    
}

void printBill()
{
    system("clear");
    int count = 0;
    bool close = false;
    while (!close)
    {
        system("clear");
        int choice;
        std::cout<<"\t1.Add Bill."<<std::endl;
        std::cout<<"\t2.Close Session."<<std::endl;
        std::cout<<"\tEnter Choice: ";
        std::cin>>choice;
        if(choice==1)
        {
            std::string item;
            int quant;
            std::cout<<"\tEnter Item: ";
            std::cin>>item;
            std::cout<<"\tEnter Quantity: ";
            std::cin>>quant;

            std::ifstream in("bill.txt");
            std::ofstream out("bill temp.txt");

            std::string line;
            bool found = false;
            while(getline(in, line))
            {
                std::stringstream ss;
                ss<<line;
                std::string itemName;
                double itemRate;
                int itemQuant;
                char delimiter;
                ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuant;

                if(item == itemName)
                {
                    found = true;
                    if(quant <= itemQuant)
                    {
                        int amount = itemRate * quant;
                        std::cout<<"\t Item | Rate | Quantity | Amount"<<std::endl;
                        std::cout<<"\t"<<itemName<<"\t"<<itemRate<<"  \t"<<quant<<"\t"<<amount<<std::endl;
                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;
                        count += amount;

                        out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<std::endl;
                    }
                    else
                    {
                        //quantity less than require
                        std::cout<<"\tSorry, "<<item<<" Emded!"<<std::endl;
                    }
                }
                else
                {
                    /**item not found*/
                    out<<line<<std::endl;
                }
            }
            if(!found)
            {
                std::cout<<"\tItem Not Available!"<<std::endl;
            }
            out.close();
            in.close();
            remove("bill.txt");
            rename("bill temp.txt", "bill.txt");
        }
        else if(choice == 2)
        {
            close = true;
            std::cout<<"\tCounting Total Bill"<<std::endl;

        }
        sleep(3);
    }
    system("clear");
    std::cout<<std::endl<<std::endl;
    std::cout<<"\t Total Bill ---------------------: "<<count<<std::endl<<std::endl;
    std::cout<<"\tThanks For Shopping!"<<std::endl;
    sleep(5);
    
}
