#include "store.h"
store::store(commodity *commodity, int amount)
{
    this->comodities = commodity;
    this->amount = amount;
    for (size_t i = 0; i < this->amount; i++)
    {
        this->comodities[i] = commodity[i]; 
    }
    
    this->max = 10;
}
store::store(){
    this->amount = 0;
    this->max = 10;
    this->comodities = new commodity[10];
}

store::~store()
{
    cout<<"离开商店"<<endl;
}

commodity store::getCommodity(int id){
    for (size_t i = 0; i < this->amount; i++)
    {
        if (this->comodities[i].getId() == id)
        {
            return this->comodities[i];
        }
        
    }
    cout<<"查询失败"<<endl;

    throw "cannot match";
}

void store::addCommodity(commodity *commodity){
    if (this->amount < this->max)
    {
        cout<<"添加成功"<<endl;
        this->comodities[this->amount] = *commodity;
        this->amount+=1;
    }
    
}

int store::getAmount(){
    return this->amount;
}

void store::change(int i){
    this->comodities[i-1].setStock(this->comodities[i-1].getStock()-1);
    this->comodities[i-1].setOrder(this->comodities[i-1].getOeder()+1);
}
