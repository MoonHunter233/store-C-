#include "store.h"
#include "user.h"
#include <fstream>
const int number = 6;
int main(int argc, char const *argv[])
{
    commodity a("pencile", 8, 25, 5,5), b("pen", 10, 20, 10,6), c("ballpen", 9, 0, 20, 6),
              d("ruler", 4 , 10, 0, 2), e("rubber", 4, 20 , 0, 2), f("type", 3 ,20 ,0 ,1);
    commodity commodities[number] = {a, b, c, d, e, f};
    ofstream ofstream("./data/data.dat",ios::out | ios::binary);
    if (ofstream.is_open() == false)
    {
        cout<<"打开文件失败"<<endl;
    } else {
        for (size_t i = 0; i < number; i++)
        {
            ofstream.write((char*)& commodities[i], sizeof(commodity));
        }
        
        ofstream.close();
    }

    user g("syh","syh"),h("admin","admin123");
    // user users[2] = {g, h};

    ofstream.open("./data/users.dat");
    if (ofstream.is_open() == false)  
    {
        cout<<"打开文件失败2"<<endl;
    } else {
        ofstream.write((char*)& g,sizeof(user));
        ofstream.write((char*)& h,sizeof(user));
        ofstream.close();
    }
    
    

    cout<<"初始化完成"<<endl;

    // commodity co;
    // commodity com[10];
    // ifstream ifstream("./data/data.dat",ios::binary);
    // if (ifstream.is_open() == false)
    // {
    //     cout<<"打开失败"<<endl;
    // } else {
    //     cout<<"test1"<<endl;
    //     int i = 0;
    //     while (ifstream.read((char*)&co,sizeof(commodity))){
    //         com[i++]= co;
    //     }
    //     ifstream.close();
    // } 
    
    return 0;
}
