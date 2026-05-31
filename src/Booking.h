#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "Passenger.h"

class Booking {
private:
    std::string orderNumber;
    Passenger passenger;
    std::string flightNumber;
    int numberOfTickets;
    std::string bookingDate;
    double totalCost;
    bool isActive;

public:
    Booking();
    Booking(const std::string& orderNum, const Passenger& pass,
            const std::string& flightNum, int numTickets,
            const std::string& date, double cost);

    std::string getOrderNumber() const;
    Passenger getPassenger() const;
    std::string getFlightNumber() const;
    int getNumberOfTickets() const;
    std::string getBookingDate() const;
    double getTotalCost() const;
    bool getIsActive() const;

    void setOrderNumber(const std::string& orderNum);
    void setFlightNumber(const std::string& flightNum);
    void setNumberOfTickets(int numTickets);
    void setBookingDate(const std::string& date);
    void setTotalCost(double cost);
    void setIsActive(bool active);

    void display() const;
    std::string toFileFormat() const;
    static Booking fromFileFormat(const std::string& line);
};

#endif
