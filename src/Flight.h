#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>

class Flight {
private:
    std::string flightNumber;
    std::string departureCity;
    std::string arrivalCity;
    std::string departureTime;
    std::string arrivalTime;
    double fare;
    double discount;
    int totalSeats;
    int availableSeats;

public:
    // Constructor
    Flight();
    Flight(const std::string& flightNum, const std::string& depCity,
           const std::string& arrCity, const std::string& depTime,
           const std::string& arrTime, double fare, double discount, int seats);

    // Getters
    std::string getFlightNumber() const;
    std::string getDepartureCity() const;
    std::string getArrivalCity() const;
    std::string getDepartureTime() const;
    std::string getArrivalTime() const;
    double getFare() const;
    double getDiscount() const;
    int getAvailableSeats() const;
    int getTotalSeats() const;
    bool isSoldOut() const;
    double getFinalPrice() const;

    // Setters
    void setFare(double newFare);
    void setDiscount(double newDiscount);
    void setDepartureTime(const std::string& newTime);
    void setArrivalTime(const std::string& newTime);
    void setAvailableSeats(int seats);

    // Seat management
    bool bookSeats(int numberOfSeats);
    bool cancelSeats(int numberOfSeats);

    // Display
    void display() const;
    std::string toFileFormat() const;
    static Flight fromFileFormat(const std::string& line);
};

#endif
