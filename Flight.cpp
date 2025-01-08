#include "Flight.h"
#include <fstream>
#include <filesystem>
#include <iostream>

void Flight::bookTicket(Passenger passenger) {
    if (seatAvailability[passenger.seatNumber - 1] == 0) {
        passengers.push_back(passenger);
        seatAvailability[passenger.seatNumber - 1] = 1;
        std::cout << "Ticket booked successfully. Reservation number: " << passenger.reservationNumber << std::endl;
        saveTicketToFile(passenger);
    } else {
        std::cout << "Seat already booked. Please choose another seat." << std::endl;
    }
}

void Flight::cancelTicket(int reservationNumber) {
    for (auto it = passengers.begin(); it != passengers.end(); ++it) {
        if (it->reservationNumber == reservationNumber) {
            seatAvailability[it->seatNumber - 1] = 0;
            passengers.erase(it);
            std::cout << "Ticket cancelled successfully." << std::endl;
            return;
        }
    }
    std::cout << "Reservation number not found." << std::endl;
}

void Flight::changeReservation(int reservationNumber, int newSeatNumber) {
    for (auto& passenger : passengers) {
        if (passenger.reservationNumber == reservationNumber) {
            if (seatAvailability[newSeatNumber - 1] == 0) {
                seatAvailability[passenger.seatNumber - 1] = 0;
                passenger.seatNumber = newSeatNumber;
                seatAvailability[newSeatNumber - 1] = 1;
                std::cout << "Reservation changed successfully." << std::endl;
            } else {
                std::cout << "New seat is already booked. Please choose another seat." << std::endl;
            }
            return;
        }
    }
    std::cout << "Reservation number not found." << std::endl;
}

void Flight::showPassengerDetails(int reservationNumber) {
    for (const auto& passenger : passengers) {
        if (passenger.reservationNumber == reservationNumber) {
            std::cout << "Reservation Number: " << passenger.reservationNumber << std::endl;
            std::cout << "First Name: " << passenger.firstName << std::endl;
            std::cout << "Last Name: " << passenger.lastName << std::endl;
            std::cout << "ID: " << passenger.id << std::endl;
            std::cout << "Phone Number: " << passenger.phoneNumber << std::endl;
            std::cout << "Seat Number: " << passenger.seatNumber << std::endl;
            std::cout << "Food Preference: " << passenger.foodPreference << std::endl;
            return;
        }
    }
    std::cout << "Reservation number not found." << std::endl;
}

void Flight::showBookingDetails() {
    std::cout << "Booking Details:" << std::endl;
    for (const auto& passenger : passengers) {
        std::cout << "Reservation Number: " << passenger.reservationNumber << ", Seat Number: " << passenger.seatNumber << std::endl;
    }
}

void Flight::saveTicketToFile(const Passenger& passenger) {
    std::cout << "Attempting to save ticket to file..." << std::endl;
    std::filesystem::create_directory("tickets");
    std::ofstream file("tickets/ticket_" + std::to_string(passenger.reservationNumber) + ".txt");
    if (file.is_open()) {
        file << "Reservation Number: " << passenger.reservationNumber << std::endl;
        file << "First Name: " << passenger.firstName << std::endl;
        file << "Last Name: " << passenger.lastName << std::endl;
        file << "ID: " << passenger.id << std::endl;
        file << "Phone Number: " << passenger.phoneNumber << std::endl;
        file << "Seat Number: " << passenger.seatNumber << std::endl;
        file << "Food Preference: " << passenger.foodPreference << std::endl;
        file.close();
        std::cout << "Ticket saved successfully in tickets folder." << std::endl;
    } else {
        std::cout << "Unable to open file to save ticket." << std::endl;
    }
}