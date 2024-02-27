#include <iostream>
using namespace std;


class Savingaccount 
{
    protected:
    int interest;
    double balance;

public:
    void savinginterest(float interestrate)
    {
        interest = balance * (interestrate / 100);
    }

    void savingcheckbook()
    {
        cout << "Checkbook not available" << endl;
    }

    void savingwithdrawl(double amt) 
    {
        if (amt <= balance)
        {
            cout << "Interest applied: " << interest << endl;
            balance = balance - (amt + interest);
            cout << "Amount deducted: " << amt+interest << endl;
        }
        else
        {
            cout << "Insufficient funds" << endl;
        }
    }
};

class Currentaccount
{ 
    
    protected:
    double cbalance;
    public:
   static  double minbalance;
   static  double servicecharge;

    void currentinterest()
    {
        cout << "Function not available" << endl;
    }

   void currentcheckbook(double amm)
   {
       cout<<"checkbook of amount :"<<amm<<"created"<<endl;
   }
    void currentwithdrawl(double amt) 
    {
        if (amt <= cbalance)
        {
            cbalance = cbalance - amt;
            cout << "Amount deducted: " << amt << endl;
             if (cbalance < minbalance)
            {
                cbalance = cbalance - servicecharge;
                cout << "Service charge applied: " << servicecharge << " due to insufficient balance" << endl;
            }
        }
        else
        {
            cout << "Insufficient funds" << endl;
            if (cbalance < minbalance)
            {
                cbalance = cbalance - servicecharge;
                cout << "Service charge applied: " << servicecharge << " due to insufficient balance" << endl;
            }
        }
    }
};

class Bankaccount : public Savingaccount,public Currentaccount
{
protected:
    string name;
    double accno;
    string type;

public:
    void savingdeposit(double amount)
    {
        balance = balance + amount;
        cout << "Deposit of amount: " << amount << " successful" << endl;
    }
    
     void currentdeposit(double amount)
    {
        cbalance = cbalance + amount;
        cout << "Deposit of amount: " << amount << " successful" << endl;
    }

    void setdetails(string name, double accno)
    {
        this->name = name;
        cout << "Name verified" << endl;
        this->accno = accno;
        cout << "Account no verified" << endl;
    }

    void getdetails()
    {
        cout << "Name is: " << name << endl;
        cout << "Account no is: " << accno << endl;
        cout << "Account type is: " << type << endl;
    }

    void balanceamt()
    {
        cout<<"account type saving"<<endl;
        cout << "Balance in account is: " << balance << endl;
    }
     void cbalanceamt()
    {
         cout<<"account type current"<<endl;
        cout << "Balance in account is: " << cbalance << endl;
    }

    
};

double Currentaccount :: minbalance = 20;
double Currentaccount :: servicecharge = 10;

int main()
{
    Bankaccount c1[100];
    int i = 0;
    int ch;
    int ans;
    do{
    
       cout <<"menu"<<endl;
       cout<<"enter choice"<<endl;
       cout<<" 1. enter details"<<endl;
       cout<<" 2. fetch details"<<endl;
       cout<<" 3. saving deposit "<<endl;
       cout<<" 4. current deposit "<<endl;
       cout<<" 5. saving withdraw "<<endl;
        cout<<" 6.current withdraw "<<endl;
       cout<<" 7. saving balance"<<endl;
        cout<<" 8. current balance"<<endl;
        cout<<"9. saving checkbook"<<endl;
        cout<<"10. current checkbook"<<endl;
       cout<<"11. enter another person"<<endl;
       cin>>ch;
       
       switch (ch)
       {
           case 1:
           {
               string nm;
               double acno;
               cout<<"enter name : ";
               cin>>nm;
               cout<<"enter acc no : ";
               cin>>acno;
              c1[i].setdetails(nm, acno); 
              break;
           }
           
           case 2:
           {
                c1[i].getdetails();
                break;
           }
           
           case 3:
           {
              double dpamt;
              cout<<"enter amount to be deposited : ";
              cin>>dpamt;
               c1[i].savingdeposit(dpamt);
               break;
           }
           
            case 4:
           {
              double dpamt;
              cout<<"enter amount to be deposited : ";
              cin>>dpamt;
               c1[i].currentdeposit(dpamt);
               break;
           }
           
           case 5:
           {
               double withamt;
               float intrate;
               cout<<"enter your interest rate : ";
               cin>>intrate;
               cout<<"enter withdrawl amount";
               cin>>withamt;
               c1[i].savinginterest(intrate); 
               c1[i].savingwithdrawl(withamt);
               break;
           }
           
            case 6:
           {
               double withamt;
               float intrate;
               cout<<"enter withdrawl amount";
               cin>>withamt;
               c1[i].currentinterest(); 
               c1[i].currentwithdrawl(withamt);
               break;
           }
           case 7:
           {
             c1[i].balanceamt(); 
             break;
           }
           
           case 8:
           {
             c1[i].cbalanceamt(); 
             break;
           }
           case 9:
           {
              c1[i].savingcheckbook();
              break;
           }
           
           case 10:
           {
               double chkamt;
              cout<<"enter checkbook amount : "; 
              cin>>chkamt;
              c1[i].currentcheckbook(chkamt);
              break;
           }
           
           case 11:
           {
                i++;
               cout<<"select menu for new person"<<endl;
               break;
           }
          
       }
        cout<<"do u want to continue 1-yes || 0-no";
        cin>>ans;
    }while(ans == 1);
    
    return 0;
}
