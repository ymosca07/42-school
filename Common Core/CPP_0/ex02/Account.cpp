#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts;
    _totalAmount += initial_deposit;
    _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
};

void	Account::_displayTimestamp( void ) {
    std::cout << "[19920104_091532] ";
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    std::cout << "[" << (now->tm_year + 1900) << (now->tm_mon + 1) << now->tm_mday << "_" << now->tm_hour << now->tm_min << now->tm_sec << "]";
};

int	Account::getNbAccounts( void ) {
    return Account::_nbAccounts;
};

int	Account::getTotalAmount( void ) {
    return Account::_totalAmount;
};

int	Account::getNbDeposits( void ){
    return Account::_totalNbDeposits;
};

int	Account::getNbWithdrawals( void ) {
    return Account::_totalNbWithdrawals;
};

void	Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
};

void	Account::makeDeposit( int deposit ) {
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
};


bool	Account::makeWithdrawal( int withdrawal )
{
    if (withdrawal > _amount) {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
};

int		Account::checkAmount( void ) const {
    return _amount;
};


void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
};

Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
};