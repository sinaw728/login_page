#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <string>
using namespace std;
class login
{
public:
    login();
    virtual ~login();
    void set_username(string);
    void set_password(string);
    void set_user_id(string);
    void set_phone_number(string);
    void set_email(string);
string check_user_id(string);







private:
    string check_username(string);
    string check_phone_number(string);
    string check_password(string);
    string check_email(string);
    string username;
    string password;
    string user_id;
    string phone;
    string email;
};

#endif // LOGIN_H
