#include<iostream>
using namespace std;
class account
{
 protected:
    char name[30];
    int acc_no;
    float bal;
 public:
    void get_cus_details()
    {
      cout<<"enter name,acc_no"<<endl;
      cin>>name>>acc_no;
    }

    void display()
    {
     cout<<"your current account balance is "<<bal;
    }

};
class savings_acc:public account
{
  protected:
    float ci;
  public:
    void comint()
    {
       int n;
       float r=0.1;
       cout<<"enter duration of years"<<endl;
       cin>>n;
       ci=bal*n*r;
       bal=bal+ci;
    }
    void withdrawal()
    {
      int amt;
      cout<<endl<<"enter the withdrawal amount"<<endl;
      cin>>amt;
      bal=bal-amt;
    }
    void deposit()
    {
      float dep;
      cout<<endl<<"enter the deposit amount"<<endl;
      cin>>dep;
      bal=bal+dep;
     }
};
class current_acc:public savings_acc
{


protected:
   float penalty;
public:
     void withdrawal()
     {
      int amt;
      cout<<"enter the withdrawal amount"<<endl;
      cin>>amt;
      bal=bal-amt;
     }

     void min_bal()
      {
         if(bal<2000)
         penalty=bal-200;
      }

 };
int main()
{
   int type;
   cout<<"enter 1 for savings account and 2 for current account"<<endl;
   cin>>type;
   switch(type)
      {
       case 1:
           {
           savings_acc s;
           s.get_cus_details();
           s.deposit();
           s.display();
           s.withdrawal();
           s.display();
           s.comint();
           s.display();
           break;
           }
       case 2:
           {
           current_acc c;
           c.get_cus_details();
           c.deposit();
           c.display();
           c.withdrawal();
           c.min_bal();
           c.display();
           break;
           }
      }
}
