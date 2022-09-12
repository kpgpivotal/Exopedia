#include "adminview.hpp"

AdminView::AdminView(User *theadmin, UserManager* p_user_manager): admin{theadmin},
						m_p_user_manager {p_user_manager}{}

//AdminView::AdminView(){}

void AdminView::display(){
cout << "\n\nAdmin View\n";

		vector<string> menu;
		menu.push_back("Profile");
		menu.push_back("List users");
		menu.push_back("Logout");

		while (true) {
			int choice = show_read_menu_choice(menu);
			if (choice == 1)
				view_profile();
			else if (choice == 2)
				list_users();

			else
				break;
		}
}

void AdminView::view_profile() const {
		cout << "\n" << admin->to_string() << "\n";
	}

void AdminView::list_users() const{
    m_p_user_manager->list_users() ;
}