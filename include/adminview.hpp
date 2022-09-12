#ifndef INCLUDE_ADMIN_VIEW_H_
#define INCLUDE_ADMIN_VIEW_H_

#include <iostream>
#include "utils.hpp"
#include "usermanager.hpp"
#include "user.hpp"


using namespace std;


class AdminView {

    public:
        AdminView( User* admin, UserManager* p_user_manager);
        //AdminView();
        void display();
        void list_users() const;

    private:
        const User* admin;
        UserManager* m_p_user_manager;
        void view_profile() const;
        
};


#endif 

