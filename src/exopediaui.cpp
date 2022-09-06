#include "exopediaui.hpp"


ExopediaUI::ExopediaUI() : m_p_user_manager{ new UserManager{} } {
 
}

ExopediaUI::~ExopediaUI(){

    debug("~ExopediaUI() Destructor");

    if (nullptr != m_p_user_manager){
        delete m_p_user_manager;
        m_p_user_manager = nullptr;
    }

}

void ExopediaUI::run(){
    message("Welcome to Exopedia UI application...");
}
