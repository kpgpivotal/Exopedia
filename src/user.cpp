#include "user.hpp"

User::User() {
}

User::~User() {	// To allow dynamic casting, we need 1+ virtual function
    debug("User::~User() Destructor ");
}

string User::to_string() const {
    ostringstream oss;
    oss << "Name: " << name;
    if (type == UserType::AdminUser)
        oss << " | Admin";
    oss << "\n";
    oss << "Email: " << email << "\n";
    oss << "User id: " << user_id << "\n";
    return oss.str();
}

void User::read_data(const string &user_id) {
    set_user_id(user_id);

    string str;

    str = get_input_string("Enter password");
    set_password(str);

    str = get_input_string("Enter name");
    set_name(str);

    str = get_input_string("Enter email");
    set_email(str);
}

const string& User::get_email() const {
    return email;
}

void User::set_email(const string& email) {
    this->email = email;
}

const string& User::get_name() const {
    return name;
}

void User::set_name(const string& name) {
    this->name = name;
}

const string& User::get_password() const {
    return password;
}

void User::set_password(const string& password) {
    this->password = password;
}

const string& User::get_user_id() const {
    return user_id;
}

void User::set_user_id(const string& userid) {
    this->user_id = userid;
}


UserType User::get_type() const {
    return type;
}

void User::set_type(UserType type) {
    this->type = type;
}

ostream &operator << ( ostream& os, UserType user_type )
{
	switch(user_type)
	{
		case UserType::CusomterUser:
		os << "CusomterUser";
		break;
		case UserType::AdminUser:
		os << "AdminUser";
		break;
	}
	return os;

}

Admin::Admin() {

};