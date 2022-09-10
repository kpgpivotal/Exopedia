#ifndef INCLUDE_USER_H_
#define INCLUDE_USER_H_

#include <iostream>
#include "utils.hpp"

using namespace std;

enum class UserType {
	CusomterUser = 0, AdminUser = 1
};

ostream &operator << ( ostream& os, UserType user_type );


class User {
protected:
	string user_id;
	string password;
	string name;
	string email;
	UserType type = UserType::CusomterUser;

public:
	User(const User& rhs) = delete;
	void operator=(const User& rhs) = delete;
	User();
	virtual ~User();
	string to_string() const;
	void read_data(const string &user_id);
	const string& get_email() const ;
	void set_email(const string& email);
	const string& get_name() const;
	void set_name(const string& name);
	const string& get_password() const;
	void set_password(const string& password);
	const string& get_user_name() const;
	void set_user_id(const string& userid) ;
    const string& get_user_id() const;
	UserType get_type() const;
	void set_type(UserType type);
};

class Admin: public User {
protected:
public:
	Admin(const Admin&) = delete;
	void operator=(const Admin&) = delete;
	Admin();
};



#endif