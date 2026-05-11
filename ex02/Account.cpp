#include <ctime>
#include <iostream>
#include "Account.hpp"
#include <string>


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
    // index:0;amount:42;created
    this->_amount = initial_deposit;
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts += 1;
    Account::_totalAmount += this->_amount;
    this->_displayTimestamp();
    std::cout 
    << "index:" << this->_accountIndex << ";" 
    << "amount:" << this->_amount << ";" 
    << "created"
    << std::endl;
}

Account::~Account()
{
    Account::_nbAccounts -= 1;
    this->_displayTimestamp();
    std::cout 
    << "index:" << this->_accountIndex << ";" 
    << "amount:" << this->_amount << ";" 
    << "closed"
    << std::endl;
}

int Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

 void Account::displayAccountsInfos(void)
{
    // accounts:8;total:20049;deposits:0;withdrawals:0
    Account::_displayTimestamp();
    std::cout 
    << "accounts:" << Account::getNbAccounts() << ";" 
    << "total:" << Account::getTotalAmount() << ";" 
    << "deposits:" << Account::getNbDeposits() << ";"
    << "withdrawals:" << Account::getNbWithdrawals() 
    << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int prev = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    Account::_displayTimestamp();
    std::cout 
    << "index:" << this->_accountIndex << ";" 
    << "p_amount:" << prev << ";" 
    << "deposit:" << deposit << ";"
    << "amount:" << this->_amount << ";" 
    << "nb_deposits:" << this->_nbDeposits
    << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if(withdrawal > this->_amount)
    {
        this->_displayTimestamp();
        std::cout 
        << "index:" << this->_accountIndex << ";" 
        << "p_amount:" <<  this->_amount << ";" 
        << "withdrawal:" << "refused"
        << std::endl;
        return (0);
    }
    int prev = this->_amount;
    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;
    Account::_displayTimestamp();
    std::cout 
    << "index:" << this->_accountIndex << ";" 
    << "p_amount:" << prev << ";" 
    << "withdrawal:" << withdrawal << ";"
    << "amount:" << this->_amount << ";" 
    << "nb_withdrawals:" << this->_nbWithdrawals
    << std::endl;
    return (1);
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout 
    << "index:" << this->_accountIndex << ";" 
    << "amount:" << this->_amount << ";" 
    << "deposits:" << this->_nbDeposits << ";"
    << "withdrawals:" << this->_nbWithdrawals 
    << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm* local_time = std::localtime(&now);
    std::cout <<"[" 
    << local_time->tm_year + 1900;
    if(local_time->tm_mon < 10)
        std::cout << "0";
    std::cout<< local_time->tm_mon;
    if(local_time->tm_mday < 10)
        std::cout << "0";
    std::cout<< local_time->tm_mday
    << "_";
    if(local_time->tm_hour < 10)
        std::cout << "0";
    std::cout<< local_time->tm_hour;
    if(local_time->tm_min < 10)
        std::cout << "0";
    std::cout << local_time->tm_min;
    if(local_time->tm_sec < 10)
        std::cout << "0";
    std::cout << local_time->tm_sec
    << "]" << " " ;
}