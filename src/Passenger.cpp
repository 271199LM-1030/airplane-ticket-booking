#include "Passenger.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Passenger::Passenger() : passengerId(""), passengerName(""), email(""), phone("") {}

Passenger::Passenger(const std::string& id, const std::string& name,
                     const std::string& email, const std::string& phone)
    : passengerId(id), passengerName(name), email(email), phone(phone) {}

std::string Passenger::getPassengerId() const { return passengerId; }
std::string Passenger::getPassengerName() const { return passengerName; }
std::string Passenger::getEmail() const { return email; }
std::string Passenger::getPhone() const { return phone; }

void Passenger::setPassengerId(const std::string& id) { passengerId = id; }
void Passenger::setPassengerName(const std::string& name) { passengerName = name; }
void Passenger::setEmail(const std::string& email) { this->email = email; }
void Passenger::setPhone(const std::string& phone) { this->phone = phone; }

void Passenger::display() const {
    std::cout << std::left << std::setw(20) << "Passenger ID:" << passengerId << std::endl;
    std::cout << std::left << std::setw(20) << "Name:" << passengerName << std::endl;
    std::cout << std::left << std::setw(20) << "Email:" << email << std::endl;
    std::cout << std::left << std::setw(20) << "Phone:" << phone << std::endl;
}

std::string Passenger::toFileFormat() const {
    std::stringstream ss;
    ss << passengerId << "|" << passengerName << "|" << email << "|" << phone;
    return ss.str();
}

Passenger Passenger::fromFileFormat(const std::string& line) {
    std::stringstream ss(line);
    std::string token;

    std::getline(ss, token, '|'); std::string id = token;
    std::getline(ss, token, '|'); std::string name = token;
    std::getline(ss, token, '|'); std::string email = token;
    std::getline(ss, token, '|'); std::string phone = token;

    return Passenger(id, name, email, phone);
}
