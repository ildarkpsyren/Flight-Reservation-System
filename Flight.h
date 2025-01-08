#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>
#include <queue>

using namespace std;

class Passenger {
public:
    string firstName;
    string lastName;
    string id;
    string phoneNumber;
    string foodPreference;
    int seatNumber;
    int reservationNumber;

    Passenger(string fName, string lName, string id, string phone, string food, int seat, int resNum)
        : firstName(fName), lastName(lName), id(id), phoneNumber(phone), foodPreference(food), seatNumber(seat), reservationNumber(resNum) {}
};

class Flight {
public:
    string flightNumber;
    string origin;
    string destination;
    vector<Passenger> passengers;
    int totalSeats;
    vector<int> seatAvailability;

    Flight(string fNumber, string orig, string dest, int seats)
        : flightNumber(fNumber), origin(orig), destination(dest), totalSeats(seats), seatAvailability(seats, 0) {}

    void bookTicket(Passenger passenger);
    void cancelTicket(int reservationNumber);
    void changeReservation(int reservationNumber, int newSeatNumber);
    void showPassengerDetails(int reservationNumber);
    void showBookingDetails();
    void saveTicketToFile(const Passenger& passenger);
};

#endif // FLIGHT_H