#include "gen/addressbook.pb.h"
#include <string>
#include <iostream>

int main(int argc, char **argv) {
	tutorial::AddressBook address_book;
	tutorial::Person *person = address_book.add_person();
	
	person->set_id(1);
	person->set_email("l_gustafson@fanshaweonline.ca");
	person->set_name("Lukas Gustafson");

	tutorial::Person::PhoneNumber *phoneNumber = person->add_phone();
	phoneNumber->set_number("519 444 5555");
	phoneNumber->set_type(tutorial::Person::MOBILE);

	std::string serializedString;
	address_book.SerializeToString(&serializedString);
	
	std::cout << serializedString << std::endl;
	for (int idxString = 0; idxString < serializedString.length(); idxString++) {
		printf("%02X ", serializedString[idxString]);
	}
	printf("\n");

	tutorial::AddressBook deserialized_address_book;
	bool success = deserialized_address_book.ParseFromString(serializedString);
	if (! success) {
		std::cout << "Failed to parse address book" << std::endl;
	}
	std::cout << "Parsing successful" << std::endl;
	const tutorial::Person& deserialized_person = deserialized_address_book.person(0); // get person at index 0
	std::cout << "E-mail: " << deserialized_person.email() << std::endl;
	std::cout << "Name: " << deserialized_person.name() << std::endl;
	
}

