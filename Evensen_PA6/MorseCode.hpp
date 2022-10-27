#pragma once

#include <iostream>
#include <string>

class MorseCode
{
public:
	// Default Constructor
	MorseCode();

	// Copy Constructor
	MorseCode(const MorseCode& rhs);

	// Setters
	void setLetter(const char nLetter) { letter = nLetter; }
	void setMorse(const std::string nMorse) { morse = nMorse; }

	// Getters
	char getLetter() const { return letter; }
	std::string getMorse() const { return morse; }
private:
	// Data Members
	char letter;
	std::string morse;
};

// Overloaded stream operators
std::istream& operator>> (std::istream& lhs, MorseCode& rhs);
std::ostream& operator<< (std::ostream& lhs, const MorseCode& rhs);

// Overloaded comparison operators
bool operator> (const MorseCode& lhs, const MorseCode& rhs);
bool operator< (const MorseCode& lhs, const MorseCode& rhs);

bool operator> (const MorseCode& lhs, const char& rhs);
bool operator< (const MorseCode& lhs, const char& rhs);
bool operator== (const MorseCode& lhs, const char& rhs);