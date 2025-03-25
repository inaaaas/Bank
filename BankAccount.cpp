#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount() {
    this -> m_accountHolder = "Unknown";
    this -> m_accountNumber = 0;
    this -> m_balance = 0.0;
}
/*
BankAccount::BankAccount() : m_accountHolder("Unknown"), m_accountNumber(0), m_balance(0.0) {}
*/
BankAccount::BankAccount(const std::string& accountHolder, int accountNumber, double balance) {
    this -> m_accountHolder = accountHolder;
    this -> m_accountNumber = accountNumber;
    this -> m_balance = balance;
}
BankAccount::BankAccount(const BankAccount& other) 
    : m_accountHolder(other.m_accountHolder),
      m_accountNumber(other.m_accountNumber),
      m_balance(other.m_balance) {}

BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        m_accountHolder = other.m_accountHolder;
        m_accountNumber = other.m_accountNumber;
        m_balance = other.m_balance;
    }
    return *this;
}

BankAccount::~BankAccount() {
    std::cout << "Account number " << m_accountHolder << " is destroyed." << std::endl;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        m_balance += amount;
    }
}
bool BankAccount::withdraw(double amount) {
    if (m_balance >= amount && amount > 0) {
        m_balance -= amount;
        return true;
    }
    std::cout << "Error: not enough money" << std::endl;
    return false;

}
void BankAccount::display() const {
    std::cout << "Account Holder: " << m_accountHolder 
    << ", Account Number:  " << m_accountNumber 
    << ", Account balance: " << m_balance << std::endl;
}
int BankAccount::getAccountNumber() const {
    return this -> m_accountNumber;
}
