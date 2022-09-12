#ifndef INCLUDE_RESERVATION_H_
#define INCLUDE_RESERVATION_H_

#include <iostream>
#include "utils.hpp"

using namespace std;

class Reservation {
public:
	virtual Reservation* clone() const = 0;

	virtual double total_cost() const = 0;

	virtual string to_string() const = 0;

	virtual ~Reservation() {
	}
};



class ItineraryReservation: public Reservation {


    public:
        ItineraryReservation();
        ItineraryReservation(const ItineraryReservation& another_reservation);
        void add_reservation(const Reservation& reservation);
        virtual double total_cost() const;
        ~ItineraryReservation();
        const vector<Reservation*>& get_reservations() const;
        void clear();
        virtual string to_string() const override;
        Reservation* clone() const;

    protected:
	    vector<Reservation*> reservations;	
};

class ReservationsSet: public ItineraryReservation {
public:
	using ItineraryReservation::ItineraryReservation;	// use its copy constructor

	virtual Reservation* clone() const;
};

#endif