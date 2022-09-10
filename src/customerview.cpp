#include "customerview.hpp"

CustomerView::CustomerView(CustomerManager &customer_manager) :
			customer_manager(customer_manager), customer(*customer_manager.get_customer()) {
	}

void CustomerView::display() {
    cout << "\n\nHello " << customer.get_name() << " | User View\n";
}