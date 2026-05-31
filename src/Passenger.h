#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
private:
    std::string passengerId;
    std::string passengerName;
    std::string email;
    std::string phone;

public:
    Passenger();
    Passenger(const std::string& id, const std::string& name,
              const std::string& email, const std::string& phone);

    std::string getPassengerId() const;
    std::string getPassengerName() const;
    std::string getEmail() const;
    std::string getPhone() const;

    void setPassengerId(const std::string& id);
    void setPassengerName(const std::string& name);
    void setEmail(const std::string& email);
    void setPhone(const std::string& phone);

    void display() const;
    std::string toFileFormat() const;
    static Passenger fromFileFormat(const std::string& line);
};

#endif
