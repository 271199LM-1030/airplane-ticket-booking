#include "Booking.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Booking::Booking() : orderNumber(""), passenger(), flightNumber(""),
                     numberOfTickets(0), bookingDate(""), totalCost(0.0), isActive(true) {}

Booking::Booking(const std::string& orderNum, const Passenger& pass,
                 const std::string& flightNum, int numTickets,
                 const std::string& date, double cost)
    : orderNumber(orderNum), passenger(pass), flightNumber(flightNum),
      numberOfTickets(numTickets), bookingDate(date), totalCost(cost), isActive(true) {}

std::string Booking::getOrderNumber() const { return orderNumber; }
Passenger Booking::getPassenger() const { return passenger; }
std::string Booking::getFlightNumber() const { return flightNumber; }
int Booking::getNumberOfTickets() const { return numberOfTickets; }
std::string Booking::getBookingDate() const { return bookingDate; }
double Booking::getTotalCost() const { return totalCost; }
bool Booking::getIsActive() const { return isActive; }

void Booking::setOrderNumber(const std::string& orderNum) { orderNumber = orderNum; }
void Booking::setFlightNumber(const std::string& flightNum) { flightNumber = flightNum; }
void Booking::setNumberOfTickets(int numTickets) { if (numTickets > 0) numberOfTickets = numTickets; }
void Booking::setBookingDate(const std::string& date) { bookingDate = date; }
void Booking::setTotalCost(double cost) { if (cost >= 0) totalCost = cost; }
void Booking::setIsActive(bool active) { isActive = active; }

void Booking::display() const {
    std::cout << "\n" << std::string(80, '-') << std::endl;
    std::cout << std::left << std::setw(25) << "Order Number:" << orderNumber << std::endl;
    std::cout << std::left << std::setw(25) << "Passenger Name:" << passenger.getPassengerName() << std::endl;
    std::cout << std::left << std::setw(25) << "Passenger ID:" << passenger.getPassengerId() << std::endl;
    std::cout << std::left << std::setw(25) << "Flight Number:" << flightNumber << std::endl;
    std::cout << std::left << std::setw(25) << "Number of Tickets:" << numberOfTickets << std::endl;
    std::cout << std::left << std::setw(25) << "Booking Date:" << bookingDate << std::endl;
    std::cout << std::left << std::setw(25) << "Total Cost:" << "$" << std::fixed << std::setprecision(2) << totalCost << std::endl;
    std::cout << std::left << std::setw(25) << "Status:" << (isActive ? "ACTIVE" : "CANCELLED") << std::endl;
    std::cout << std::string(80, '-') << std::endl;
}

std::string Booking::toFileFormat() const {
    std::stringstream ss;
    ss << orderNumber << "|" << passenger.getPassengerId() << "|"
       << passenger.getPassengerName() << "|" << flightNumber << "|"
       << numberOfTickets << "|" << bookingDate << "|" << totalCost << "|"
       << (isActive ? "1" : "0");
    return ss.str();
}

Booking Booking::fromFileFormat(const std::string& line) {
    std::stringstream ss(line);
    std::string token;

    std::getline(ss, token, '|'); std::string orderNumber = token;
    std::getline(ss, token, '|'); std::string passengerId = token;
    std::getline(ss, token, '|'); std::string passengerName = token;
    std::getline(ss, token, '|'); std::string flightNumber = token;
    std::getline(ss, token, '|'); int numberOfTickets = std::stoi(token);
    std::getline(ss, token, '|'); std::string bookingDate = token;
    std::getline(ss, token, '|'); double totalCost = std::stod(token);
    std::getline(ss, token, '|'); bool isActive = (token == "1");

    Passenger passenger(passengerId, passengerName, "", "");
    Booking booking(orderNumber, passenger, flightNumber, numberOfTickets, bookingDate, totalCost);
    booking.setIsActive(isActive);
    return booking;
}
