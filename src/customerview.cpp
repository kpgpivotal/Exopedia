#include "customerview.hpp"

CustomerView::CustomerView(CustomerManager &customer_manager) :
			customer_manager(customer_manager), customer(*customer_manager.get_customer()) {
	}


void CustomerView::read_flight_request(FlightRequest &request) const{
		string str;
		int val;

		cout << "Enter From: ";
		cin >> str;
/*		request.SetFrom(str);

		cout << "Enter From Date (dd-mm-yy): ";
		cin >> str;
		request.SetDatetimeFrom(str);

		cout << "Enter To: ";
		cin >> str;
		request.SetTo(str);

		cout << "Enter To Date (dd-mm-yy): ";
		cin >> str;
		request.SetDatetimeTo(str);

		cout << "Enter # of adults children (5-16) and infants: ";
		cin >> val;
		request.SetAdults(val);
		cin >> val;
		request.SetChildren(val);
		cin >> val;
		request.SetInfants(val);

 */       
	}

	void CustomerView::read_hotel_request(HotelRequest &request) const{
		string str;
		int val;

		cout << "Enter From Date (dd-mm-yy): ";
		cin >> str;
/*		request.SetFromDate(str);

		cout << "Enter From Date (dd-mm-yy): ";
		cin >> str;
		request.SetToDate(str);

		cout << "Enter Country: ";
		cin >> str;
		request.SetCountry(str);

		cout << "Enter City: ";
		cin >> str;
		request.SetCity(str);

		cout << "Enter # of adults and children: ";
		cin >> val;
		request.SetAdults(val);
		cin >> val;
		request.SetChildren(val);
    */    
	}

	int CustomerView::choose_flight(const vector<Flight> &flights) const {
/*        
		if (flights.size() == 0) {
			cout << "No trips for this request info\n";
			return -1;
		}

		for (const Flight& flight : flights) {
			cout << flight.ToString() << "\n";
		}

		return ReadInt(1, flights.size(), true);
*/

        return 1;
	}

	int CustomerView::choose_room(const vector<HotelRoom> &rooms) const{
    /*    
		if (rooms.size() == 0) {
			cout << "No trips for this request info\n";
			return -1;
		}

		for (const HotelRoom& room : rooms) {
			cout << room.ToString() << "\n";
		}

		return ReadInt(1, rooms.size(), true);
*/
        return 1;        
	}

	void CustomerView::add_flight() {
/*        
		FlightRequest request;
		read_flight_request(request);

		vector<Flight> flights = customer_manager.FindFlights(request);
		int flight_choice = choose_flight(flights);

		if (flight_choice == -1)
			return;

		Flight &flight = flights[flight_choice - 1];

		FlightReservation reservation(request, flight);
		current_itinerary.AddReservation(reservation);
*/
       
	}

	void CustomerView::add_hotel() {

/*        
		HotelRequest request;
		read_hotel_request(request);

		vector<HotelRoom> rooms = customer_manager.FindHotels(request);
		int hotel_choice = choose_room(rooms);

		if (hotel_choice == -1)
			return;

		HotelRoom &room = rooms[hotel_choice - 1];

		HotelReservation reservation(request, room);
		current_itinerary.AddReservation(reservation);
*/        
	}

	void CustomerView::pay_itinerary() {
/*        
		// We can mark it const, but wrong, don't
		vector<string> payment_choices = customer_manager.GetPaymentChoices();
		int payment_chocie = ShowReadMenu(payment_choices, "Select a payment choice");
		PaymentCard* payment_card = customer.GetCards()[payment_chocie - 1];

		bool status = customer_manager.MakeReservation(current_itinerary, *payment_card);

		if (status) {
			cout << "Itinerary reserved\n";
		} else
			cout << "Failed to reserve the Itinerary\n";
*/            
	}

    void CustomerView::display() {
		cout << "\n\nHello " << customer.get_name() << " | User View\n";

		vector<string> menu;
		menu.push_back("View Profile");
		menu.push_back("Make Itinerary");
		menu.push_back("List my itineraries");
		menu.push_back("Logout");

		while (true) {
			int choice = show_read_menu_choice(menu);
			if (choice == 1)
				view_profile();
			else if (choice == 2)
				make_itinerary();
			else if (choice == 3)
				list_itineraries();
			else
				break;
		}
	}

	void CustomerView::view_profile() const {
		cout << "\n" << customer.to_string() << "\n";
	}

	void CustomerView::make_itinerary() {
		vector<string> menu;
		menu.push_back("Add Flight");
		menu.push_back("Add Hotel");
		menu.push_back("Done");
		menu.push_back("Cancel");

		while (true) {
			int choice = show_read_menu_choice(menu);
			if (choice == 1)
				add_flight();
			else if (choice == 2)
				add_hotel();
			else if (choice == 3) {
				pay_itinerary();
//				current_itinerary.Clear();
				break;
			} else {
//				current_itinerary.Clear();
//				break;
			}
		}
	}
	void CustomerView::list_itineraries() const {
        message("ustomerView::list_itineraries()");
/*        
		vector<string> itineraries = customer_manager.GetItineraries();

		if (itineraries.size() == 0) {
			cout << "No itineraries so far!\n";
		}

		for (string& str : itineraries)
			cout << str << "\n";
*/            
	}