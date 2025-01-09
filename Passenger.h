#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
public:
    std::string firstName;
    std::string lastName;
    std::string ssn;
    std::string phoneNumber;
    std::string foodPreference;
    int seatNumber;
    int reservationNumber;

    Passenger(const std::string& fName, const std::string& lName, const std::string& ssn, const std::string& phone, const std::string& food, int seat, int resNum)
        : firstName(fName), lastName(lName), ssn(ssn), phoneNumber(phone), foodPreference(food), seatNumber(seat), reservationNumber(resNum) {}
};

#endif // PASSENGER_H