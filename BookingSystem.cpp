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

void BookingSystem::Expand() { //expandera array n�r den �r full

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

bool BookingSystem::Reserve(const std::string& referenceID, const Date& start, const Date& end) {  //g�ra bokningen, h�mtar fr�n Reservation klassen.
	//if funktion f�r att kolla om testerna klarats -> l�gg till i array
	Reservation** bookings_array = new Reservation * [this->capacity];
	Reservation gob(referenceID, start, end);
	Reservation* ptr;
	ptr = &gob;

	bookings_array[this->reservationCount] = ptr;  //f�r samma adress hela tiden?
	this->reservationCount++;



	if (this->reservationCount == this->capacity) {   //om full k�r expand
		Expand();
	}
}


/*
Inneh�ll i bookingsystem: int capacity, int reservationCount

gr�nssnitt f�r att g�ra bokningar
lagrar tidigare bokningar
F�rs�ka g�ra bokning och f� resultat om det var m�jligt eller inte

Dynamisk array med reservationsPEKARE, ta bort och g�ra st�rre varje g�ng det kommer en ny bokning.

n�r giltig bokning sker s� ska den lagras p� heapen och dess ADRESS lagras p� n�sta lediga plats i ARRAYEN

*/

// Add your defintions for all member functions of the class 'BookingSystem' here: