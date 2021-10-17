#include "login.h"

login::login()
{
    //ctor
}
string login::check_username(string name)
{
    int p=0;
    string testname;
    testname=name;
    p=testname.find('_');
    if(p!=-1)
    {
        testname=testname.erase(p,1);
    }
    int c=0;
    if(name[0]=='_' || name[ name.size()-1 ]=='_')
        throw invalid_argument("invalid username");
    for(int i=0; i<name.size()-1; i++)
    {
        if(!((testname[i]>='A' && testname[i]<='Z') || (testname[i]>='a' && testname[i]<='z')))
        {
            throw invalid_argument("invalid username");
        }
    }
    return name;
}

void login::set_username(string name)
{
    this->username=check_username(name);
}
string login::check_password(string pass)
{
    int n=0;
    int a=1,b=1,c=1;

    if(pass.size() < 8)
    {
        throw invalid_argument("invalid username");
    }
    for(int i=0; i<pass.size()-1; i++)
    {
        if(pass[i]>='A' && pass[i]<='Z')
        {
            if(a==1)
            {
                n++;
                a++;
            }

        }
        if(pass[i]>='a' && pass[i]<='z')
        {
            if(b==1)
            {
                n++;
                b++;
            }
        }
        if(pass[i]>='0' && pass[i]<='9')
        {
            if(c==1)
            {
                n++;
                c++;
            }
        }
    }
    if(n!=3)
    {
        throw invalid_argument("invalid username");
    }
    return pass;

}
void login::set_password(string pass)
{
    this->password=check_password(pass);
}
string login::check_user_id(string user)
{
    int sum=0;
    int n;
    for(int i=0; i<user.size()-1; i++ )
    {
        //(int)(user[i]-48);// num=(int)(user[i]-'0')
        sum+=( ( (int)(user[i]-48) )* (10-i) );
    }
    n=sum%11;
    if(n<=2)
    {
        if(((int)(user[9]-48)) != n)
            throw invalid_argument("invalid user id ");
    }
    if(n>2)
    {
        if(( (int)(user[9]-48)) != (11-n))
        {
            throw invalid_argument("invalid user id ");
        }
    }
    return user;
}
void login::set_user_id(string user)
{

    this->user_id=check_user_id(user);

}
string login::check_phone_number(string phone)
{
    int p,q;
    string num;
    if( !(phone.size()==11) || (phone.size()==13) )
    {
        throw invalid_argument("invalid phone number");
    }
    if(phone.size()==11)
    {
        num=phone.substr(0,2);
        if(num!="09")
            throw invalid_argument("invalid phone number");
    }
    if(phone.size()==13)
    {
        num=phone.substr(0,4);
        if(num!="+989")
            throw invalid_argument("invalid phone number ");
    }
    if(phone.size()==13)
    {
        phone=phone.replace(0,3,"0");
    }

    return phone;
}
void login::set_phone_number(string phone)
{
    this->phone=check_phone_number(phone);
}
string login::check_email(string email)
{
    string first,second,third;
    first=email.substr(0,email.find("@"));
    second=email.substr(email.find("@")+1,(email.find(".")-1)-email.find("@"));
    third=email.substr(email.find(".")+1,(email.size())-email.find("."));
    for(int i=0; i<first.size(); i++)
    {
        if(!( (first[i]>='0' && first[i]<='9')||(first[i]>='A' && first[i]<='Z') ||
                (first[i]>='a' && first[i]<='z') || (first[i]=='-') ||(first[i]=='_')))
        {
            throw invalid_argument("invalid email ");
        }
    }
     for(int i=0; i<second.size(); i++)
     {
     if(!( (second[i]>='0' && second[i]<='9')||(second[i]>='A' && second[i]<='Z') ||
                (second[i]>='a' && second[i]<='z') || (second[i]=='-') ||(second[i]=='_')))
        {

            throw invalid_argument("invalid email ");
        }
     }
     if(!((third.size()>2) || (third.size()<5 )))
     {
         throw invalid_argument("invalid email ");
     }
     for(int i=0; i<third.size(); i++)
     {
       if(!( (third[i]>='a' && third[i]<='z')||(third[i]>='A' && third[i]<='Z')))
          throw invalid_argument("invalid email ");
     }












    return email;
}
void login::set_email(string email)
{
    this->email=check_email(email);
}
login::~login()
{
    //dtor
}
