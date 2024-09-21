/**
 * Do not make any changes in this file.
 */

#ifndef BOOKING_SYSTEM_HPP
#define BOOKING_SYSTEM_HPP

#include "Reservation.hpp"

class BookingSystem
{
    int capacity;
    int reservationCount;
    Reservation** reservations;

    void Expand();

public:

    BookingSystem(int capacity); //konstruktor

    ~BookingSystem();  //destruktor

    BookingSystem(const BookingSystem& other);   //?
    BookingSystem& operator=(const BookingSystem& other);   // ?

    bool Reserve(const std::string& referenceID, const Date& start, const Date& end); // Ta bort personCount      //?








    // Only needed for tests(!)
    int GetReservationCount() const;
    int GetReservationCapacity() const;
    Reservation** GetReservations() const;
};

#endif // BOOKING_SYSTEM_HPP