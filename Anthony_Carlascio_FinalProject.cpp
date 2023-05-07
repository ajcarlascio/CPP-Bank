// Anthony_Carlascio_FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
//#include "FinalHeader.h"
//#include "Final.cpp"

#define MAX 25

using namespace std;

class Expense {
protected:
    float payment;
    string type;
public:
    Expense(float p, string t) : payment{ p }, type{ t }
    {}

    void virtual expenseDetails()
    {
        cout << endl << "You have made a payment of " << setprecision(2) << fixed << payment << " for " << type;
    }

    void setPayment(float p)
    {
        payment = p;
    }

    float getPayment()
    {
        return payment;
    }

    void setType(string t)
    {
        type = t;
    }

    string getType()
    {
        return type;
    }
};

//A2
class cashTransaction : public Expense {
public:

    void expenseDetails()
    {
        cout << endl << "You have made a cash payment of " << setprecision(2) << fixed << payment << " for " << type;
    }
};

//A3
class creditCardTransaction : public Expense {
protected:
    string cardName;
    string expire;
    int cardNumber;
public:
    creditCardTransaction(float pay, string billT, string Pname, string ex, int cardNo)
        : Expense{ pay , billT }
    {
        cardName = Pname;
        expire = ex;
        cardNumber = cardNo;
    }

    void expenseDetails()
    {
        cout << endl << "You have made a credit card payment of " << setprecision(2) << fixed << payment << " for " << type;
        cout << "This payment was made with card number " << cardNumber << " with expiry date " << expire << " in the name of " << cardName << endl;
    }
};

//B1
class Household {
protected:
    string houseName;
    long id;
    //B2
    //Account* p[3];
public:
    Household(string Name, long ident) : houseName{ Name }, id{ ident }
    {
        
    }

    string getHouse()
    {
        return houseName;
    }

    void setHouse(string house)
    {
        houseName = house;
    }

    long getId()
    {
        return id;
    }

    void setId(long ident)
    {
        id = ident;
    }

    void houseDeets()
    {
        cout << "Name:           " << houseName << endl;
        cout << "Identification: " << id << endl;
    }
};

//C1
class Account {
private:
    float balance;
    string accountHolder;
public:
    Account(float bal, string Pname) : balance{ bal }, accountHolder{ Pname }
    {}

    string getPerson()
    {
        return accountHolder;
    }

    void setPerson(string name)
    {
        accountHolder = name;
    }

    float getBalance()
    {
        return balance;
    }

    void setBalance(float amount)
    {
        balance = amount;
    }

    void virtual deposit(float depo)
    {
        balance = balance + depo;
    }

    void virtual withdraw(float number)
    {
        while (number > balance)
        {
            cout << endl << "Debit amount exceeds account balance please enter another number >";
            cin >> number;
        }

        balance = balance - number;
    }
};

class savingsAccount : public Account {
protected:
    double interest = 1.03;
public:
    savingsAccount(float bal, string Pname) : Account(bal, Pname)
    {
    }

    void deposit(float number)
    {
        float tempBalance = getBalance() + number;
        setBalance(tempBalance);
    }

    void calculateInterest()
    {
        float tempBalance = getBalance() * interest;
        setBalance(tempBalance);
    }
};

class checkingAccount : public Account {
protected:
    float transactionFee = 1.00;
public:
    checkingAccount(float bal, string Pname) : Account(bal, Pname)
    {
    }

    void deposit(float number)
    {
        float tempBalance = getBalance() + number - transactionFee;
        setBalance(tempBalance);
    }

    void withdraw(float number)
    {
        float totWith = number + transactionFee;

        if (totWith < getBalance())
        {
            float tempBalance = getBalance() - totWith;
            setBalance(tempBalance);
        }
        else
            cout << endl << "Insufficient funds" << endl;
    }
};

void printer1(long &ident, string &cx);
void printer2(float& pay, string& typer);

int main()
{
    //D1 (see below for A4, B3, C2)
    Account* p[3];
    string customer;
    long id1;
    int i = 0, j = 0;
    float paym;
    string t;
    Household* tempPtr;
    Expense* tempPtr1;

    const size_t people{ 6 }; 
    const size_t bills{ 20 };

    vector <Household> container1;
    vector <Expense> container2;

    printer1(id1, customer);
    printer2(paym, t);
    Expense p1(paym, t);
    container2.push_back(p1);
    //tempPtr1 = &p1;
    Household h1(customer, id1);
    //tempPtr = &h1;
    container1.push_back(h1);
    //Node n1(tempPtr1, tempPtr);

    printer1(id1, customer);
    printer2(paym, t);
    Expense p2(paym, t);
    container2.push_back(p2);
    Household h2(customer, id1);
    container1.push_back(h2);
    //tempPtr = &h2;
    //tempPtr1 = &p2;
    //Node n2(tempPtr1, tempPtr);
    
    printer1(id1, customer);
    printer2(paym, t);
    Expense p3(paym, t);
    container2.push_back(p3);
    Household h3(customer, id1);
    container1.push_back(h3);
    //tempPtr = &h3;
    //tempPtr1 = &p3;
    //Node n3(tempPtr1, tempPtr);

    printer1(id1, customer);
    printer2(paym, t);
    Expense p4(paym, t);
    container2.push_back(p4);
    Household h4(customer, id1);
    container1.push_back(h4);
    //tempPtr = &h4;
    //tempPtr1 = &p4;
    //Node n4(tempPtr1, tempPtr);

    printer1(id1, customer);
    printer2(paym, t);
    Expense p5(paym, t);
    container2.push_back(p5);
    Household h5(customer, id1);
    container1.push_back(h5);
    //tempPtr = &h5;
    //tempPtr1 = &p5;
    //Node n5(tempPtr1, tempPtr);

    //D2
    h1.houseDeets();
    p1.expenseDetails();
    
    h2.houseDeets();
    p2.expenseDetails();
    
    h3.houseDeets();
    p3.expenseDetails();
    
    h4.houseDeets();
    p4.expenseDetails();

    h5.houseDeets();
    p5.expenseDetails();
    /**************************************************************************\
    /**********************************A4***************************************\
    
    float amount;
    string payType;
    string expiry;
    int cardNo;
    string Name;

    cout << "Please enter which bill you'd like to pay >";
    getline(cin, payType);
    cout << endl << "Next enter the amount that you would like to pay >";
    cin >> amount;

    cashTransaction Jim(amount, payType);
    Jim.expenseDetails();

    cout << "Please enter which bill you'd like to pay >";
    getline(cin, payType);
    cout << endl << "Next enter the amount that you would like to pay >";
    cin >> amount;

    cashTransaction Pam(amount, payType);
    Pam.expenseDetails();

    cout << endl << "Please enter a bill to make a credit card payment towards >";
    getchar();
    getline(cin, payType);
    cout << endl << "Please enter the amount of cash you would like to pay >";
    cin >> amount;
    cout << endl << "Please enter the Expiry date [MM/YY] >";
    getchar();
    getline(cin, expiry);
    cout << endl << "Please enter the number on the credit card >";
    cin >> cardNo;
    cout << endl << "Please enter the Name as it appears on the card >";
    getchar();
    getline(cin, Name);

    creditCardTransaction Fred(float amount, string payType, string Name, string expiry, int cardNo)
    Fred.expenseDetails();

    cout << endl << "Please enter a bill to make a credit card payment towards >";
    getchar();
    getline(cin, payType);
    cout << endl << "Please enter the amount of cash you would like to pay >";
    cin >> amount;
    cout << endl << "Please enter the Expiry date [MM/YY] >";
    getchar();
    getline(cin, expiry);
    cout << endl << "Please enter the number on the credit card >";
    cin >> cardNo;
    cout << endl << "Please enter the Name as it appears on the card >";
    getchar();
    getline(cin, Name);

    creditCardTransaction Wilma(float amount, string payType, string Name, string expiry, int cardNo)
    Wilma.expenseDetails()
    
    ***************************************************************************/

    /**************************************************************************\
    /**********************************B3***************************************\

    string name;
    long ident;

    cout << "Please enter the household name >";
    getline(cin, name);

    cout << endl << "Please enter an identification >";
    cin >> ident;
    cout << endl;

    Household h1 (name, ident);
    h1.getId();
    h1.getHouse();
    h1.setId(0001);
    h1.getId();
    h1.setHouse("Anthony");
    h1.getHouse();

    ***************************************************************************/

    /**************************************************************************\
    /**********************************C3***************************************\

    float bal = 100.00;
    string Name = "Anthony";

    Account cx1(bal, Name);
    cx1.setPerson("Ezio");
    cx1.setBalance(100000000.00);
    cout << cx1.getBalance() << endl;
    cout << cx1.getPerson() << endl;
    cx1.deposit(250000.00);
    cout << cx1.getBalance() << endl;
    cx1.withdraw(50000000.00);
    cout << cx1.getBalance() << endl;

    savingsAccount cx2(bal, Name);
    Account* aPtr1 = &cx2;
    aPtr1->deposit(100);

    checkingAccount cx3(bal, Name);
    aPtr1 = &cx3;
    aPtr1->withdraw(50.00);
    aPtr1->deposit(100.50);

    ***************************************************************************/
}

void printer1(long &ident, string &cx)
{
    cout << endl << "Please enter you identification number >";
    cin >> ident;
    cout << endl << "Please enter you name >";
    getline(cin, cx);
    cout << endl;
}

void printer2(float& pay, string& typer)
{
    cout << endl << "Please enter the amount of the payment >";
    cin >> pay;
    cout << endl << "Please enter the name of the expense >";
    getline(cin, typer);
    cout << endl;
}
