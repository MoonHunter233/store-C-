#include "store.h"
#include "commodity.h"
#include "user.h"
#include <fstream>
#include <string.h>
int n = 0;
static fstream fst;
static user users[2];
commodity commodities[10];
static store *store1;

void addLine(){
    cout<<"╞══════════════════════════════════════════════════════╡"<<endl;
}

//“渲染”商店
void render(){
    int profit = 0;
    // int number = store.getAmount();
    cout<<"\n\n\n"<<endl;
    addLine();
    cout<<"|"<<setw(12)<<setfill(' ')<<left<<"编号"
        <<"|"<<setw(12)<<setfill(' ')<<left<<"名称"
        <<"|"<<setw(12)<<setfill(' ')<<left<<"价格"
        <<"|"<<setw(12)<<setfill(' ')<<left<<"库存"
        <<"|"<<setw(12)<<setfill(' ')<<left<<"已订"
        <<"|"<<endl;
    addLine();
    for (size_t i = 0; i < store1->getAmount(); i++)
    {   
        commodity com = store1->getCommodity(i+1);
        cout<<"|"<<setw(10)<<setfill(' ')<<left<<com.getId()
            <<"|"<<setw(10)<<setfill(' ')<<left<<com.getName()
            <<"|"<<setw(10)<<setfill(' ')<<left<<com.getPrice()
            <<"|"<<setw(10)<<setfill(' ')<<left<<com.getStock()
            <<"|"<<setw(10)<<setfill(' ')<<left<<com.getOeder()
            <<"|"<<endl;
        addLine();
        profit += (com.getPrice() - com.getCost()) * com.getOeder();
    }  
    
    cout<<"|"<<setw(55)<<setfill(' ')<<right<<"当前获利"<<profit<<"|"<<endl;
    addLine();
}

//启动
void startStore(){

    fst.open("./data/data.dat",ios::in | ios:: binary);
    if (fst.is_open() == false)
    {
        cout<<"商店启动失败"<<endl;
    } else {
        commodity com;
        int i = 0;
        while (fst.read((char *)& com,sizeof(commodity))){
            commodities[i++] = com;
        }
        fst.close();
        store1 = new store(commodities,i);
        render();
    }
}
//保存商店数据
void reStore(){
    fst.open("./data/data.dat",ios::out | ios::binary);
    if (fst.is_open() == false)
    {
        cout<<"保存失败"<<endl;
    } else {
        for (size_t i = 0; i < store1->getAmount(); i++)
        {
            commodity com = store1->getCommodity(i+1);
            fst.write((const char*)& com,sizeof(commodity));
        }
    }
    fst.close();
}

//购买ing
void shopping(int id){
    int i;
    string address;
    try
    {
        commodity com = store1->getCommodity(id);

        if (com.getStock()>0)   
        {
            cout<<"编号:"<<com.getId()<<",名称:"<<com.getName()<<",价格:"<<com.getPrice()<<endl;
            cout<<"请输入收货地址"<<endl;
            cin>>address;
            cout<<"输入1确认购买"<<endl;
            cin>>i;
            if(i == 1){
                ofstream ofs("./data/order.txt",ios::app);
                if (ofs.is_open() == false)
                {
                    cout<<"购买失败"<<endl;
                } else {
                    store1->change(id);
                    
                    reStore();
                    
                    ofs<<"id:"<<id<<",address:"<<address<<"\n";
                    ofs.close();
                    cout<<"购买成功！"<<endl;
                }
            } else {
                cout<<"购买取消"<<endl;
            }  
        } else {
            cout<<"库存不足，购买取消"<<endl;
        }
    }
    catch(...)
    {
        cout<<"无法查询到此产品"<<endl;
    }
    render();
    
}

//进货
void buy(){
    string name;
    int num, price, cost;
    cout<<"name:";
    cin>>name;
    cout<<"num:";
    cin>>num;
    cout<<"price:";
    cin>>price;
    cout<<"cost:";
    cin>>cost;
    commodity *com = new commodity(name,price,num,0,cost);
    store1->addCommodity(com);
    delete com;
    reStore();
    startStore();
}

//登录
bool login(){
    fst.open("./data/users.dat",ios::in | ios::binary);
    if (fst.is_open() == true)
    {
        for (size_t i = 0; i < sizeof(users)/sizeof(user); i++)
        {
            fst.read((char*)& users[i],sizeof(user));
        }
        fst.close();
        
    }
    string username;
    string password;
    cout<<"username:";
    cin>>username;
    // cout<<endl;
    cout<<"password:";
    cin>>password;
    for (size_t i = 0; i < sizeof(users)/sizeof(user); i++)
    {
        if (users[i].getUsername() == username)
        {
            if (users[i].getPassword() == password)
            {
                return true;
            }
            
        }
        
    }
    cout<<"用户名不存在或密码错误"<<endl;
    return false;
}


int main(int argc, char const *argv[])
{
    while(!login());
    startStore();
    while (n != -1)
    {    
        if (n == 1)
        {
            cout<<"请输入商品编号"<<endl;
            int i;
            cin>>i;
            shopping(i);
        }
        // 
        cout<<"输入1进行选购,-1退出"<<endl;
        cin>>n;
    }
    delete store1;
    return 0;
}
