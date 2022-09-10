#ifndef INCLUDE_CUSTOMER_VIEW_H_
#define INCLUDE_CUSTOMER_VIEW_H_

#include <iostream>
#include "utils.hpp"
#include "customermanager.hpp"
#include "customer.hpp"

using namespace std;

class CustomerView {

    private:
        CustomerManager &customer_manager;
        const Customer& customer;
        //ItineraryReservation current_itinerary;

    public:
        CustomerView(CustomerManager &customer_manager);
        void display();


};


#endif 

