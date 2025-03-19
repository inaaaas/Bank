#include "BankSystem.h"
#include <iostream>

void BankSystem::addAccount(const std::string& name, int accountNumber, double initialBalance) {
    BankAccount newAccount(name, accountNumber, initialBalance);
    m_accounts.push_back(newAccount);
}
BankAccount* BankSystem::findAccount(int accountNumber) {
    for (int i = 0; i < m_accounts.size(); ++i) {
        if (m_accounts[i].getAccountNumber() == accountNumber) {
            return &m_accounts[i];
        }
    }
    /*
    for (auto& account : m_accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;
        }
    }*/
    return nullptr;
}

void BankSystem::transferFunds(int senderAcc, int receiverAcc, double amount) {
    BankAccount* sender = findAccount(senderAcc);
    BankAccount* reciever = findAccount(receiverAcc);
    if (sender != nullptr && reciever != nullptr && sender -> withdraw(amount)) {
        reciever -> deposit(amount);
    }
}
void BankSystem::displayAllAccounts() const {
    for (const auto& account : m_accounts) {
        account.display();
    }
}
