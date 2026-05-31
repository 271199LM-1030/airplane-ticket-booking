#include "Flight.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Flight::Flight() : flightNumber(""), departureCity(""), arrivalCity(""),
                   departureTime(""), arrivalTime(""), fare(0.0),
                   discount(0.0), totalSeats(0), availableSeats(0) {}

Flight::Flight(const std::string& flightNum, const std::string& depCity,
               const std::string& arrCity, const std::string& depTime,
               const std::string& arrTime, double f, double d, int seats)
    : flightNumber(flightNum), departureCity(depCity), arrivalCity(arrCity),
      departureTime(depTime), arrivalTime(arrTime), fare(f), discount(d),
      totalSeats(seats), availableSeats(seats) {}

std::string Flight::getFlightNumber() const { return flightNumber; }
std::string Flight::getDepartureCity() const { return departureCity; }
std::string Flight::getArrivalCity() const { return arrivalCity; }
std::string Flight::getDepartureTime() const { return departureTime; }
std::string Flight::getArrivalTime() const { return arrivalTime; }
double Flight::getFare() const { return fare; }
double Flight::getDiscount() const { return discount; }
int Flight::getAvailableSeats() const { return availableSeats; }
int Flight::getTotalSeats() const { return totalSeats; }
bool Flight::isSoldOut() const { return availableSeats <= 0; }
double Flight::getFinalPrice() const { return fare * (1.0 - discount); }

void Flight::setFare(double newFare) {
    if (newFare >= 0) fare = newFare;
}

void Flight::setDiscount(double newDiscount) {
    if (newDiscount >= 0 && newDiscount <= 1.0) discount = newDiscount;
}

void Flight::setDepartureTime(const std::string& newTime) {
    departureTime = newTime;
}

void Flight::setArrivalTime(const std::string& newTime) {
    arrivalTime = newTime;
}

void Flight::setAvailableSeats(int seats) {
    if (seats >= 0 && seats <= totalSeats) availableSeats = seats;
}

bool Flight::bookSeats(int numberOfSeats) {
    if (numberOfSeats > 0 && numberOfSeats <= availableSeats) {
        availableSeats -= numberOfSeats;
        return true;
    }
    return false;
}

bool Flight::cancelSeats(int numberOfSeats) {
    if (numberOfSeats > 0 && (availableSeats + numberOfSeats) <= totalSeats) {
        availableSeats += numberOfSeats;
        return true;
    }
    return false;
}

void Flight::display() const {
    std::cout << "\n" << std::string(80, '=') << std::endl;
    std::cout << std::left << std::setw(20) << "Flight Number:" << flightNumber << std::endl;
    std::cout << std::left << std::setw(20) << "Route:" << departureCity << " -> " << arrivalCity << std::endl;
    std::cout << std::left << std::setw(20) << "Departure Time:" << departureTime << std::endl;
    std::cout << std::left << std::setw(20) << "Arrival Time:" << arrivalTime << std::endl;
    std::cout << std::left << std::setw(20) << "Fare:" << "$" << std::fixed << std::setprecision(2) << fare << std::endl;
    std::cout << std::left << std::setw(20) << "Discount:" << (discount * 100) << "%" << std::endl;
    std::cout << std::left << std::setw(20) << "Final Price:" << "$" << std::fixed << std::setprecision(2) << getFinalPrice() << std::endl;
    std::cout << std::left << std::setw(20) << "Available Seats:" << availableSeats << "/" << totalSeats << std::endl;
    std::cout << std::left << std::setw(20) << "Status:" << (isSoldOut() ? "SOLD OUT" : "AVAILABLE") << std::endl;
    std::cout << std::string(80, '=') << std::endl;
}

std::string Flight::toFileFormat() const {
    std::stringstream ss;
    ss << flightNumber << "|" << departureCity << "|" << arrivalCity << "|"
       << departureTime << "|" << arrivalTime << "|" << fare << "|"
       << discount << "|" << availableSeats << "|" << totalSeats;
    return ss.str();
}

Flight Flight::fromFileFormat(const std::string& line) {
    std::stringstream ss(line);
    std::string token;
    Flight flight;

    std::getline(ss, token, '|'); flight.flightNumber = token;
    std::getline(ss, token, '|'); flight.departureCity = token;
    std::getline(ss, token, '|'); flight.arrivalCity = token;
    std::getline(ss, token, '|'); flight.departureTime = token;
    std::getline(ss, token, '|'); flight.arrivalTime = token;
    std::getline(ss, token, '|'); flight.fare = std::stod(token);
    std::getline(ss, token, '|'); flight.discount = std::stod(token);
    std::getline(ss, token, '|'); flight.availableSeats = std::stoi(token);
    std::getline(ss, token, '|'); flight.totalSeats = std::stoi(token);

    return flight;
}
