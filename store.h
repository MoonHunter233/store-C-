#ifndef store_hpp
#define store_hpp
#include "commodity.h"
class store
{
private:
    commodity *comodities;
    int amount;
    int max;
public:
    store();
    store(commodity *commodity, int amount);
    ~store();
    int getAmount();
    commodity getCommodity(int id);
    void addCommodity(commodity *commodity);
    void change(int i);
};


#endif