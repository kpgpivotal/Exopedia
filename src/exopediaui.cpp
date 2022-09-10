#include "exopediaui.hpp"


ExopediaUI::ExopediaUI() : m_p_user_manager{ new UserManager{} } {
    debug("ExopediaUI::ExopediaUI()");
}

ExopediaUI::~ExopediaUI(){

    debug("~ExopediaUI() Destructor");

    if (nullptr != m_p_user_manager){
        delete m_p_user_manager;
        m_p_user_manager = nullptr;
    }

}

void ExopediaUI::run(){
    bool return_value{};
    UserType utype;

    clear_console();
    message("Welcome to Exopedia UI application...");
    load_database();

		while (true) {
			return_value = m_p_user_manager->user_access_management();	


            utype = m_p_user_manager->get_current_user()->get_type();
            cout << "\n Type : " << utype;
			if ( utype == UserType::CusomterUser) {

/*
				m_p_user_manager = new CustomerManager(users_manager->get_current_user(), *expedia_manager);
				CustomerView view(*customer_manager);
				view.Display();
*/                
			}
			else {
                assert(false);
            }
				

           if (return_value) {
            break;
           }
		}


}


int ExopediaUI::load_database(){
    m_p_user_manager->load_database();

    return 1;
}