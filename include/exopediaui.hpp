#ifndef INCLUDE_EXOPEDIAUI_H
#define INCLUDE_EXOPEDIAUI_H

#include <iostream>
#include "utils.hpp"
#include "usermanager.hpp"
#include "customermanager.hpp"
#include "customerview.hpp"

using namespace std;

class ExopediaUI {
    public:
        ExopediaUI();
        ~ExopediaUI();
        ExopediaUI(const ExopediaUI& rhs) = delete;
        void operator=(const ExopediaUI& rhs) = delete;
        void run();

    private:
        UserManager* m_p_user_manager = nullptr;
        ExpediaManager*  m_p_expedia_manager = nullptr;
        CustomerManager* m_p_customer_manager = nullptr;
        int load_database();


};

#endif