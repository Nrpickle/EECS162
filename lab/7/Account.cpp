/**
 * This class represents a bank account and maintains a balance.
 */
#include <iostream>
#include "Account.hpp"

double Account::deposit(double amount) {
  try
  {
  if( amount > 0 )
    balance += amount;
  else
    throw amount;
  }
  catch (double amount){
    std::cout << amount << " is less than 0. Please try again." << std::endl;
  }
  return balance;
}



double Account::withdraw(double amount) {
  try
  {
  if( (amount < balance) && (amount >0) )
    balance -= amount;
  else
    throw amount;
  }
  catch (double amount){
    if(amount < 0)
      std::cout << amount << " is less than 0. Please try again." << std::endl;
    if(amount > balance)
      std::cout << amount << " is more than your balance of " << balance << ". Please try again." << std::endl;
  }
  return balance;
}


int main(int argc, char** argv) {
  Account main;
  std::cout << "Deposit 10." << std::endl;
  main.deposit(10);
  std::cout << "Account balance: " << main.getBalance() << std::endl << std::endl;
  std::cout << "Deposit -10." << std::endl;
  main.deposit(-10);
  std::cout << "Account balance: " << main.getBalance() << std::endl << std::endl;
  std::cout << "Withdraw 5." << std::endl;
  main.withdraw(5);
  std::cout << "Account balance: " << main.getBalance() << std::endl << std::endl;
  std::cout << "Withdraw 10." << std::endl;
  main.withdraw(10);
  std::cout << "Account balance: " << main.getBalance() << std::endl << std::endl;
  std::cout << "Withdraw -10." << std::endl;
  main.withdraw(-10); 
  std::cout << "Account balance: " << main.getBalance() << std::endl << std::endl;
  return 0;
}
