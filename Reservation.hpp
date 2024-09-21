/**
 * Do not make any changes in this file.
 */

#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <string>
#include "Date.hpp"

class Reservation
{
    std::string referenceID;   
    Date startDate;            
    Date endDate;             
     
public:
    
    Reservation(const std::string& referenceID, const Date& start, const Date& end);




    Reservation(const Reservation& other);


    Reservation& operator=(const Reservation& other);

    bool operator==(const Reservation& other) const;
    bool operator!=(const Reservation& other) const;
    
    bool Overlaps(const Reservation& other) const;   // avgöra om bokningen overlappar med någon annan !

    const std::string& GetReferenceID() const; //? !
    const Date& GetStartDate() const;  //?
    const Date& GetEndDate() const;  //?
};

#endif // RESERVATION_HPP