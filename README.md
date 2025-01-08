# Flight-Reservation-System
### Flight Management System Documentation

#### Overview
The Flight Management System is designed to manage airline flights, including booking tickets, canceling tickets, changing reservations, and displaying passenger and booking details. Additionally, it includes a route management system using graphs to represent routes between cities and implements Dijkstra's algorithm for route optimization.

#### Classes

##### `Passenger`
Represents a passenger with the following attributes:
- `firstName`: First name of the passenger.
- `lastName`: Last name of the passenger.
- `id`: Identification number of the passenger.
- `phoneNumber`: Phone number of the passenger.
- `foodPreference`: Food preference of the passenger (Veg, Non-Veg, No Food).
- `seatNumber`: Seat number assigned to the passenger.
- `reservationNumber`: Unique reservation number for the passenger.

##### `Flight`
Represents a flight with the following attributes and methods:
- `flightNumber`: Unique identifier for the flight.
- `origin`: Origin city of the flight.
- `destination`: Destination city of the flight.
- `passengers`: List of passengers on the flight.
- `totalSeats`: Total number of seats available on the flight.
- `seatAvailability`: Vector indicating seat availability (0 for available, 1 for booked).

Methods:
- `bookTicket(Passenger passenger)`: Books a ticket for a passenger.
- `cancelTicket(int reservationNumber)`: Cancels a ticket using the reservation number.
- `changeReservation(int reservationNumber, int newSeatNumber)`: Changes the seat reservation for a passenger.
- `showPassengerDetails(int reservationNumber)`: Displays details of a passenger using the reservation number.
- `showBookingDetails()`: Displays details of all bookings on the flight.

##### `Ticket`
Represents a ticket with the following attributes:
- `reservationNumber`: Unique reservation number for the ticket.
- `flightNumber`: Flight number associated with the ticket.
- `seatNumber`: Seat number assigned to the ticket.

##### `RouteGraph`
Represents a graph of routes between cities with the following attributes and methods:
- `adjList`: Adjacency list representing the graph, where each city is connected to other cities with a distance.

Methods:
- `addRoute(const string& from, const string& to, int distance)`: Adds a route between two cities with a specified distance.
- `findShortestPath(const string& start, const string& end)`: Finds the shortest path between two cities using Dijkstra's algorithm.

#### Usage

##### Booking a Ticket
To book a ticket, create a `Passenger` object and call the `bookTicket` method of the `Flight` class.
```cpp
Passenger passenger1("John", "Doe", "ID123", "1234567890", "Veg", 1, 1001);
flight.bookTicket(passenger1);
```

##### Canceling a Ticket
To cancel a ticket, call the `cancelTicket` method of the `Flight` class with the reservation number.
```cpp
flight.cancelTicket(1001);
```

##### Changing a Reservation
To change a reservation, call the `changeReservation` method of the `Flight` class with the reservation number and the new seat number.
```cpp
flight.changeReservation(1001, 2);
```

##### Displaying Passenger Details
To display passenger details, call the `showPassengerDetails` method of the `Flight` class with the reservation number.
```cpp
flight.showPassengerDetails(1001);
```

##### Displaying Booking Details
To display all booking details, call the `showBookingDetails` method of the `Flight` class.
```cpp
flight.showBookingDetails();
```

##### Adding a Route
To add a route between two cities, call the `addRoute` method of the `RouteGraph` class.
```cpp
graph.addRoute("New York", "Los Angeles", 3000);
```

##### Finding the Shortest Path
To find the shortest path between two cities, call the `findShortestPath` method of the `RouteGraph` class.
```cpp
vector<string> path = graph.findShortestPath("New York", "Los Angeles");
```

This documentation provides an overview of the Flight Management System, including class descriptions, methods, and usage examples.
