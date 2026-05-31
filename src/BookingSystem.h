#ifndef BOOKING_SYSTEM_H
#define BOOKING_SYSTEM_H

#include <vector>
#include <string>
#include "Flight.h"
#include "Booking.h"
#include "Passenger.h"

class BookingSystem {
private:
    std::vector<Flight> flights;
    std::vector<Booking> bookings;
    std::string flightsFile;
    std::string bookingsFile;
    int orderCounter;

    std::string generateOrderNumber();
    Flight* findFlightByNumber(const std::string& flightNumber);
    Booking* findBookingByOrderNumber(const std::string& orderNumber);
    std::vector<Flight> findAlternativeFlights(const std::string& departCity, const std::string& arrivalCity);
    void loadFlights();
    void loadBookings();
    void saveFlights();
    void saveBookings();
    std::string getCurrentDate();

public:
    BookingSystem();

    void addFlight(const Flight& flight);
    void removeFlight(const std::string& flightNumber);
    void modifyFlightFare(const std::string& flightNumber, double newFare);
    void modifyFlightDiscount(const std::string& flightNumber, double newDiscount);
    void modifyFlightTime(const std::string& flightNumber, const std::string& newDepTime, const std::string& newArrTime);

    void displayFlightByNumber(const std::string& flightNumber) const;
    void displayFlightsByRoute(const std::string& departCity, const std::string& arrivalCity) const;
    void displayAllFlights() const;

    bool bookFlight(const Passenger& passenger, const std::string& flightNumber, int numberOfTickets);
    void refundTicket(const std::string& orderNumber);
    void displayBooking(const std::string& orderNumber) const;
    void displayAllBookings() const;
    void displayPassengerBookings(const std::string& passengerId) const;

    void loadData();
    void saveData();
    void displayMenu() const;
};

#endif
