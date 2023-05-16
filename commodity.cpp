#include "commodity.h"
int commodity::n = 1;
commodity::commodity(string name, int price, int stock, int order, int cost)
{
    this->id = n++;
    this->name = name;
    this->price = price;
    this->stock = stock;
    this->order = order;
    this->cost = cost;
}

commodity::commodity(){}

commodity::~commodity()
{
}

int commodity::getId(){
    return this->id;
}
string commodity::getName(){
    return this->name;
}
int commodity::getPrice(){
    return this->price;
}
int commodity::getStock(){
    return this->stock;
}
int commodity::getOeder(){
    return this->order;
}
int commodity::getCost(){
    return this->cost;
}

void commodity::setName(string name){
    this->name = name;
}
void commodity::setPrice(int price){
    this->price = price;
}
void commodity::setStock(int stock){
    this->stock = stock;
}
void commodity::setOrder(int order){
    this->order = order;
}
void commodity::setCost(int cost){
    this->cost = cost;
}