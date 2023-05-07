#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#define MAX 25

using namespace std;


//A1
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
    //Account* ptr = new Account;
    //Account House;
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