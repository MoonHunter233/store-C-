#ifndef commodity_hpp
#define commodity_hpp
#include<iostream>
using namespace std;
class commodity
{   
private:
    static int n;
    int id;
    string name;
    int price;
    int stock;
    int order;
    int cost;
public:
    commodity();
    commodity(string name, int price, int stock, int order, int coust);
    ~commodity();
    int getId();
    string getName();
    int getPrice();
    int getStock();
    int getOeder();
    int getCost();

    void setName(string name);
    void setPrice(int price);
    void setStock(int stock);
    void setOrder(int order);
    void setCost(int cost);

};
#endif