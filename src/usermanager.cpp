#include "usermanager.hpp"


UserManager::UserManager(){}

UserManager::~UserManager(){

    debug("UserManager::~UserManager  Destructor");
    free_n_clear_data();

}

void UserManager::free_n_clear_data() {
    for (auto pair : m_userid_userobject_map) {
        delete pair.second;
    }
    m_userid_userobject_map.clear();
    m_current_user = nullptr;
}

void UserManager::load_database(){
    message("UserManager::load_database()");
}

void UserManager::access_system(){
    message("UserManager::access_system()");
}
    

void UserManager::do_login() {
    load_database();

    while (true) {
        string user_name, pass;
        cout << "Enter user user_name & password: ";
        cin >> user_name >> pass;

        if (!m_userid_userobject_map.count(user_name)) {
            cout << "\nInvalid user user_name or password. Try again\n\n";
            continue;
        }
        User* user_exist = m_userid_userobject_map.find(user_name)->second;

        if (pass != user_exist->get_password()) {
            cout << "\nInvalid user user_name or password. Try again\n\n";
            continue;
        }
        m_current_user = user_exist;
        break;
    }
}

void UserManager::do_signup() {
    string user_name;
    while (true) {
        cout << "Enter user name. (No spaces): ";
        cin >> user_name;

        if (m_userid_userobject_map.count(user_name))
            cout << "Already used. Try again\n";
        else
            break;
    }
    m_current_user = new Customer();
    m_current_user->read_data(user_name);
    m_userid_userobject_map[m_current_user->get_user_id()] = m_current_user; 
}

User* UserManager::get_current_user() const {
    // For simplicity, I don't return it as const, which is not good
    // One ok way: return as const, and user support clone + copy contstructor. Then caller can make his own copy
    return m_current_user;
}


