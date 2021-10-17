#include <iostream>
#include <string>
#include "login.h"
using namespace std;

int main()
{
    login log;

    try
    {
    cout<<"fillout the form"<<endl;
    cout<<log.check_user_id("1271303957");
    }
    catch (invalid_argument &err)
    {
        cout<<err.what();
    }



    return 0;
}
