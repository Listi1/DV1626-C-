/**
 * Only the following includes are allowed in this file.
 * 
 * Other includes may be used during development, but are expected to be
 * removed (not commented out) when the file is turned in to CodeGrade.
 */ 
#include "Reservation.hpp"
#include <stdexcept>

// Add your defintions for all member functions of the class 'Reservation' here:
Reservation::Reservation(const std::string& referenceID, const Date& start, const Date& end) {

	this->referenceID = referenceID;
	this->startDate = start;
	this->endDate = end;
}

bool Reservation::Overlaps(const Reservation& other) const { //bokning x med referens Z är bokad samma tid som bokning y med referens Z, isåfall ge error.  Kolla om start datum före slut datum?
}

const std::string& Reservation::GetReferenceID() const {
	return this->referenceID;
}
const Date& GetStartDate() {
	return this->start; // Date hur funkar?
}
const Date& GetEndDate() {
	return this->end; // Date hur funkar?

}