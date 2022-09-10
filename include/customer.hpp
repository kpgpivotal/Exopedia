#ifndef INCLUDE_CUSTOMER_H_
#define INCLUDE_CUSTOMER_H_

#include <iostream>
#include "utils.hpp"
#include "user.hpp"

using namespace std;

class Customer : public User {
    public:
        Customer();

    private:
        Customer(const Customer&) = delete;
	    void operator=(const Customer&) = delete;


};

#endif