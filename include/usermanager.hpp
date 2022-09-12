#ifndef INCLUDE_USER_MANAGER_H_
#define INCLUDE_USER_MANAGER_H_

#include <iostream>
#include <map>
#include "utils.hpp"
#include "user.hpp"
#include "customer.hpp"

using namespace std;


class UserManager {
	protected:
		User* m_current_user = nullptr;
		map<string, User*> m_userid_userobject_map;
			

	public:
		UserManager();
		~UserManager(); 
		UserManager(const UserManager&) = delete;
		void operator=(const UserManager&) = delete;
		void load_database();
		bool user_access_management();
		bool do_login();
		void do_signup();
		void do_exit();
		User* get_current_user() const ;
		void free_n_clear_data();
		void list_users();


};



#endif /* INCLUDE_USER_MANAGER_H_ */