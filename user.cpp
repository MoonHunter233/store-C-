#include "user.h"
user::user(/* args */)
{
}

user::user(string username,string password){
    this->username = username;
    this->password = password;
}
user::~user()
{
}

string user::getUsername(){
    return this->username;
}

string user::getPassword(){
    return this->password;
}