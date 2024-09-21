#include "BookingSystem.hpp"
#include "Reservation.hpp"
#include "Date.hpp"

#include <iostream>

/**
 * This file is provided for you to test your own code. :)
 */

int main()
{
	// All member functions has to be defined before this can run!
    BookingSystem bookingSystem(10);



	bookingSystem.Reserve("Bastuflotta", Date(15, 12, 2022), Date(17, 12, 2022));
	bookingSystem.Reserve("Bastustuga", Date(15, 12, 2022), Date(17, 12, 2022));   //går det att göra bokning True, False
	


	//overlap test
	Reservation foo("Bastuflotta", Date(1, 1, 2022), Date(5, 1, 2022));    //gör bokning, kolla om de True eller false från Reserve
	Reservation bar("Bastuflotta", Date(3, 1, 2022), Date(8, 1, 2022));

	foo.Overlaps(bar); // returns true

	//fungerande test
	Reservation food("Bastuflotta", Date(1, 1, 2022), Date(5, 1, 2022));
	Reservation bard("Badtunna", Date(3, 1, 2022), Date(8, 1, 2022));

	food.Overlaps(bar); // returns false
	*/


	std::cout << "Let's code!" << std::endl;
	return 0;
}