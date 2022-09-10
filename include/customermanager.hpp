#ifndef INCLUDE_CUSTOMER_MANAGER_H_
#define INCLUDE_CUSTOMER_MANAGER_H_

#include <iostream>
#include "utils.hpp"
#include "user.hpp"
#include "customer.hpp"


using namespace std;

class ExpediaManager{};

class CustomerManager {
    public:
        CustomerManager(User *user, ExpediaManager &expedia_manager);
        const Customer* get_customer() const;

    private:
        Customer *customer;
        ExpediaManager &expedia_manager;

};

#endif