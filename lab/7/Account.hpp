#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

/**
 * This class represents a bank account and maintains a balance.
 */
class Account
{
public:
	/**
	 * Default constructor creates an Account object with 0 balance 
	 */
	Account() : balance(0) {}

	/**
	 * Constructor that creates an Account object with the specified
	 * balance.
	 * @param initialDeposit The initial balance of the Account
	 */
	Account(double initialDeposit) : balance(initialDeposit) {}

	/**
	 * Returns the balance of the Account
	 * @return the balance of the Account
	 */
	double getBalance() { return balance; }
	
	/**
	 * Deposits a given amount into the account
	 * @param amount The amount to deposit
	 * @return Returns new balance or -1 if error
	 */
	double deposit(double amount);

	/**
	 *
	 * Attempts to withdraw the specified amount from the bank account
	 * @param amount The amount to withdraw
	 * @return returns the new balance or -1 if amount is invalid
	 */
	double withdraw(double amount);

private:

	/**
	 * The balance in the account
	 */
	double balance;
};

#endif
