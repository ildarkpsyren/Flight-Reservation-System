#include "Flight.h"
#include <fstream>

bool Flight::bookTicket(const Passenger& passenger) {
    if (seatAvailability[passenger.seatNumber - 1] == 0) {
        passengers.push_back(passenger);
        seatAvailability[passenger.seatNumber - 1] = 1;
        saveTicketToFile(passenger);
        return true;
    } else {
        return false;
    }
}

void Flight::saveTicketToFile(const Passenger& passenger) {
    std::ofstream outFile("ticket_" + std::to_string(passenger.reservationNumber) + ".txt");
    outFile << "Reservation Number: " << passenger.reservationNumber << "\n";
    outFile << "First Name: " << passenger.firstName << "\n";
    outFile << "Last Name: " << passenger.lastName << "\n";
    outFile << "SSN: " << passenger.ssn << "\n";
    outFile << "Phone Number: " << passenger.phoneNumber << "\n";
    outFile << "Food Preference: " << passenger.foodPreference << "\n";
    outFile << "Seat Number: " << passenger.seatNumber << "\n";
    outFile << "Flight Number: " << flightNumber << "\n";
    outFile << "Origin: " << origin << "\n";
    outFile << "Destination: " << destination << "\n";
    outFile << "Flight Date: " << flightDate << "\n";
    outFile.close();
}