#ifndef INCLUDE_CUSTOMER_VIEW_H_
#define INCLUDE_CUSTOMER_VIEW_H_

#include <iostream>
#include "utils.hpp"
#include "customermanager.hpp"
#include "customer.hpp"
#include "reservation.hpp"

using namespace std;

class FlightRequest{};
class HotelRequest{};
class Flight{};
class HotelRoom{};


class CustomerView {

    private:
        CustomerManager &customer_manager;
        const Customer& customer;
        ItineraryReservation current_itinerary;
        void read_flight_request(FlightRequest &request) const;
        void read_hotel_request(HotelRequest &request) const;
        int choose_flight(const vector<Flight> &flights) const;
        int choose_room(const vector<HotelRoom> &rooms) const;
        void add_flight();
        void add_hotel();
        void pay_itinerary();

    public:
        CustomerView(CustomerManager &customer_manager);
        void display();
        void view_profile() const;
        void make_itinerary();
        void list_itineraries() const;
};


#endif 

