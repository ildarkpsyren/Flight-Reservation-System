#include "Flight.h"
#include <fstream>

void Flight::bookTicket(Passenger passenger) {
    if (seatAvailability[passenger.seatNumber - 1] == 0) {
        passengers.push_back(passenger);
        seatAvailability[passenger.seatNumber - 1] = 1;
        cout << "Ticket booked successfully. Reservation number: " << passenger.reservationNumber << endl;
        saveTicketToFile(passenger);
    } else {
        cout << "Seat already booked. Please choose another seat." << endl;
    }
}

void Flight::cancelTicket(int reservationNumber) {
    for (auto it = passengers.begin(); it != passengers.end(); ++it) {
        if (it->reservationNumber == reservationNumber) {
            seatAvailability[it->seatNumber - 1] = 0;
            passengers.erase(it);
            cout << "Ticket cancelled successfully." << endl;
            return;
        }
    }
    cout << "Reservation number not found." << endl;
}

void Flight::changeReservation(int reservationNumber, int newSeatNumber) {
    for (auto& passenger : passengers) {
        if (passenger.reservationNumber == reservationNumber) {
            if (seatAvailability[newSeatNumber - 1] == 0) {
                seatAvailability[passenger.seatNumber - 1] = 0;
                passenger.seatNumber = newSeatNumber;
                seatAvailability[newSeatNumber - 1] = 1;
                cout << "Reservation changed successfully." << endl;
            } else {
                cout << "New seat is already booked. Please choose another seat." << endl;
            }
            return;
        }
    }
    cout << "Reservation number not found." << endl;
}

void Flight::showPassengerDetails(int reservationNumber) {
    for (const auto& passenger : passengers) {
        if (passenger.reservationNumber == reservationNumber) {
            cout << "Reservation Number: " << passenger.reservationNumber << endl;
            cout << "First Name: " << passenger.firstName << endl;
            cout << "Last Name: " << passenger.lastName << endl;
            cout << "ID: " << passenger.id << endl;
            cout << "Phone Number: " << passenger.phoneNumber << endl;
            cout << "Seat Number: " << passenger.seatNumber << endl;
            cout << "Food Preference: " << passenger.foodPreference << endl;
            return;
        }
    }
    cout << "Reservation number not found." << endl;
}

void Flight::showBookingDetails() {
    cout << "Booking Details:" << endl;
    for (const auto& passenger : passengers) {
        cout << "Reservation Number: " << passenger.reservationNumber << ", Seat Number: " << passenger.seatNumber << endl;
    }
}

void Flight::saveTicketToFile(const Passenger& passenger) {
    ofstream file("ticket_" + to_string(passenger.reservationNumber) + ".txt");
    if (file.is_open()) {
        file << "Reservation Number: " << passenger.reservationNumber << endl;
        file << "First Name: " << passenger.firstName << endl;
        file << "Last Name: " << passenger.lastName << endl;
        file << "ID: " << passenger.id << endl;
        file << "Phone Number: " << passenger.phoneNumber << endl;
        file << "Seat Number: " << passenger.seatNumber << endl;
        file << "Food Preference: " << passenger.foodPreference << endl;
        file.close();
    } else {
        cout << "Unable to open file to save ticket." << endl;
    }
}