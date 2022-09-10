#include "usermanager.hpp"


UserManager::UserManager(){
        load_database();
}

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
    free_n_clear_data();
/*
    // Some "Dummy Data" for simplicity
    Admin* admin_user = new Admin();
    admin_user->set_user_id("kishore");
    admin_user->set_password("111");
    admin_user->set_email("kishore@gmail.com");
    admin_user->set_name("Kishore George");
    m_userid_userobject_map[admin_user->get_user_id()] = admin_user;

    Customer* customrUser = new Customer();
    customrUser->set_user_id("nash");
    customrUser->set_password("123");
    customrUser->set_email("nash@gmail.com");
    customrUser->set_name("Nash George");

/*
    DebitCard* debitCard = new DebitCard();
    debitCard->SetOwnerName(customrUser->GetName());
    debitCard->SetCardNumber("11-22-33-44");
    debitCard->SetExpiryDate("11/20");
    debitCard->SetSecurityCode(111);
    debitCard->SetBillingAddress("111 hello st, BC, Canada");
    customrUser->AddPaymentCard(*debitCard);

    CreditCard* creditCard = new CreditCard();
    creditCard->SetOwnerName(customrUser->GetName());
    creditCard->SetCardNumber("22-11-03-44");
    creditCard->SetExpiryDate("11/25");
    creditCard->SetSecurityCode(1117);
    customrUser->AddPaymentCard(*creditCard);
    
*/
  //  m_userid_userobject_map[customrUser->get_user_id()] = customrUser;

}

bool UserManager::user_access_management(){
    int choice{};
    bool return_value{};
    
    choice = show_read_menu_choice( { "Login", "Customer Sign Up", "Exit"});
    //cout << "\n@@@@@@@@@@@\t Choice : " << choice << endl;

    if (choice == 3) {
        do_exit();
        return_value = true;
    }
        
    else
    {
        if (choice == 1)
            return_value = do_login();
        else
            do_signup();
    }

    if ( false == return_value) {
        user_access_management();
    }

    return return_value;
}
    

bool UserManager::do_login() {


    if ( 0 == m_userid_userobject_map.size() ) {
        message("There were no registered users found. Please register as a user.");
        return false; 
    }

    while (true) {
        string user_id{}, password{};

        user_id = get_input_string("Enter your user id");
        password = get_input_string("Enter password");

        if (!m_userid_userobject_map.count(user_id)) {
            message("Invalid  user_id. Try again");
            continue;
        }
        User* user_exist = m_userid_userobject_map.find(user_id)->second;

        if (password != user_exist->get_password()) {
            message("Invalid user user_name or password. Try again");
            continue;
        }
        m_current_user = user_exist;
        //message(m_current_user->get_user_id() + " soccessfully logged in.");
        break;
    }

    return true;
}

void UserManager::do_signup() {
    string user_id;
    while (true) {
        user_id = get_input_string("Enter your preferred  user id");
        

        if (m_userid_userobject_map.count(user_id))
            cout << "Already used. Try again\n";
        else
            break;
    }
    m_current_user = new Customer();
    m_current_user->read_data(user_id);
    m_current_user->set_type(UserType::CusomterUser);
    m_userid_userobject_map[m_current_user->get_user_id()] = m_current_user; 
}

User* UserManager::get_current_user() const {
    return m_current_user;
}


void UserManager::do_exit(){
    clear_console();
    message("Thank you for choosing Exopedia!");
    exit(EXIT_SUCCESS);
}