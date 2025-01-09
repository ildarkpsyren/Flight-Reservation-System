#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <vector>
#include <string>
#include "Passenger.h"

class Flight {
public:
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::string flightDate;
    int totalSeats;
    std::vector<int> seatAvailability;
    std::vector<Passenger> passengers;
    int nextReservationNumber;

    Flight(const std::string& fNumber, const std::string& orig, const std::string& dest, const std::string& date, int seats)
        : flightNumber(fNumber), origin(orig), destination(dest), flightDate(date), totalSeats(seats), seatAvailability(seats, 0), nextReservationNumber(1) {}

    bool bookTicket(const Passenger& passenger);
    void saveTicketToFile(const Passenger& passenger);
};

#endif // FLIGHT_H