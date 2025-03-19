#ifndef BANKACCOUNT_H 
#define BANKACCOUNT_H
#include <string>

class BankAccount {
    std::string m_accountHolder;
    int m_accountNumber;
    double m_balance;
public:
    BankAccount();
    BankAccount(const std::string& accountHolder, int accountNumber, double balance);
    BankAccount(const BankAccount& other);
    BankAccount& operator=(const BankAccount& other);
    ~BankAccount();
    
    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;
    int getAccountNumber() const;
};

#endif
