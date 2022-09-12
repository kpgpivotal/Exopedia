#include "reservation.hpp"

ItineraryReservation::ItineraryReservation() {
	}

ItineraryReservation::ItineraryReservation(const ItineraryReservation& another_reservation) {	// copy constructor
    for (const Reservation* reservation : another_reservation.get_reservations())
        add_reservation(*reservation);
}

void ItineraryReservation::add_reservation(const Reservation& reservation) {
    reservations.push_back(reservation.clone());
}

double ItineraryReservation::total_cost() const {
    double cost = 0;

    for (const Reservation* reservation : reservations)
        cost += reservation->total_cost();

    return cost;
}

ItineraryReservation::~ItineraryReservation() {
    clear();
}

const vector<Reservation*>& ItineraryReservation::get_reservations() const {
    return reservations;
}

void ItineraryReservation::clear() {
    for (const Reservation* reservation : reservations)
        delete reservation;
    reservations.clear();
}


string ItineraryReservation::to_string() const  {
    ostringstream oss;

    oss <<"**********************************************\n";
    oss << "Itinerary of " << reservations.size() << " sub-reservations\n";

    for (const Reservation* reservation : reservations)
        oss << reservation->to_string() << "\n";

    oss << "Total Itinerary cost: " << total_cost() << "\n";
    oss <<"**********************************************\n";
    return oss.str();
}

Reservation* ItineraryReservation::clone() const {
    return new ItineraryReservation(*this);
}

Reservation* ReservationsSet::clone() const {
    return new ItineraryReservation(*this);
}