#ifndef user_hpp
#define user_hpp
#include <iostream>
using namespace std;
class user
{
private:
    string username;
    string password;
public:
    user();
    user(string username, string password);
    ~user();

    string getUsername();
    string getPassword();
};

#endif