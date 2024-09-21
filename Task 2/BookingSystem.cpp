/**
 * Only the following includes are allowed in this file.
 * 
 * Other includes may be used during development, but are expected to be
 * removed (not commented out) when the file is turned in to CodeGrade.
 */ 
#include "BookingSystem.hpp"

BookingSystem::BookingSystem(int capacity) { //konstruktor
	this->capacity = capacity;
	this->reservationCount = 0;
}

BookingSystem::~BookingSystem() { //destruktor
}

void BookingSystem::Expand() { //expandera array när den är full

	int* temp_array = new int[this->reservationCount];

	for (int i = 0; i < this->capacity; i++) {
		temp_array[i] = bookings_array[i];
	}
	delete[] bookings_array;
	this->capacity = this->reservationCount;
	int* bookings_array = new int[this->capacity];

	for (int i = 0; i this->capacity; i++) {
		bookings_array[i] = temp_array[i];
	}
	delete[] temp_array;

}

BookingSystem::BookingSystem(const BookingSystem& other) { //copy konstruktor?

}

bool BookingSystem::Reserve(const std::string& referenceID, const Date& start, const Date& end) {  //göra bokningen, hämtar från Reservation klassen.
	//if funktion för att kolla om testerna klarats -> lägg till i array
	Reservation** bookings_array = new Reservation * [this->capacity];
	Reservation gob(referenceID, start, end);
	Reservation* ptr;
	ptr = &gob;

	bookings_array[this->reservationCount] = ptr;  //får samma adress hela tiden?
	this->reservationCount++;



	if (this->reservationCount == this->capacity) {   //om full kör expand
		Expand();
	}
}


/*
Innehåll i bookingsystem: int capacity, int reservationCount

gränssnitt för att göra bokningar
lagrar tidigare bokningar
Försöka göra bokning och få resultat om det var möjligt eller inte

Dynamisk array med reservationsPEKARE, ta bort och göra större varje gång det kommer en ny bokning.

när giltig bokning sker så ska den lagras på heapen och dess ADRESS lagras på nästa lediga plats i ARRAYEN

*/

// Add your defintions for all member functions of the class 'BookingSystem' here: