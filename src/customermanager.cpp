#include "customermanager.hpp"



CustomerManager::CustomerManager(User *user, ExpediaManager &the_expedia_manager):
			customer(dynamic_cast<Customer*>(user)), expedia_manager(the_expedia_manager) {

		if (customer == nullptr) {
			cout << "Error: User is null pointer as input\n";
			assert(customer != nullptr);
		}

	}

const Customer* CustomerManager::get_customer() const {
		return customer;
}