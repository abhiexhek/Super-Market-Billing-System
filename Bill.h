#pragma once
#include <string>
#include <unistd.h>
#include <fstream>
#include <sstream>

class Bill
{
    private:
        std::string Item;
        double Rate;
        int Quantity;

    public:
        Bill():Item(""), Rate(0.0), Quantity(0)
        {

        }
        void setItem(std::string item)
        {
            Item = item;
        }
        void setRate( double rate)
        {
            Rate = rate;
        }
         void setQuant(int quant)
        {
            Quantity = quant;
        }

        std::string getItem()
        {
            return Item;
        }

        double getRate()
        {
            return Rate;
        }
        int getQuant()
        {
            return Quantity;
        }
};