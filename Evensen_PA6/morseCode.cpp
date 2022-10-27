#include "MorseCode.hpp"

/*******************************************************************************
 * Programmer: Drew Evensen		                                               *
 * Class: CptS 122; Lab Section 7                                              *
 * Programming Assignment: 6	                                               *
 * Date: 10/28/22                                                              *
 *                                                                             *
 * Description: This program converts a given text file to morse code		   *
 *				using a Binary Search Tree									   *
 ******************************************************************************/

// Default Constructor
MorseCode::MorseCode()
{
	letter = '\0';
	morse = "\0";
}

// Copy Constructor
MorseCode::MorseCode(const MorseCode& rhs)
{
	letter = rhs.letter;
	morse = rhs.morse;
}

// Overloaded stream operators
std::istream& operator>> (std::istream& lhs, MorseCode& rhs)
{
	// Catches data from the stream
	char letTemp;
	std::string morTemp;

	// Obtain the character and the corresponding morse code translation
	lhs >> letTemp;
	lhs.ignore();
	std::getline(lhs, morTemp);

	// Set the appropriate fields
	rhs.setLetter(letTemp);
	rhs.setMorse(morTemp);

	return lhs;
}
std::ostream& operator<< (std::ostream& lhs, const MorseCode& rhs)
{
	lhs << rhs.getLetter() << " : " << rhs.getMorse();
	return lhs;
}

// Overloaded comparison operators
bool operator> (const MorseCode& lhs, const MorseCode& rhs)
{
	// Compare the char values
	return lhs.getLetter() > rhs.getLetter();
}
bool operator< (const MorseCode& lhs, const MorseCode& rhs)
{
	// Compare the char values
	return lhs.getLetter() < rhs.getLetter();
}

bool operator> (const MorseCode& lhs, const char& rhs)
{
	// Compare the char value
	return lhs.getLetter() > rhs;
}
bool operator< (const MorseCode& lhs, const char& rhs)
{
	// Compare the char value
	return lhs.getLetter() < rhs;
}
bool operator== (const MorseCode& lhs, const char& rhs)
{
	// Compare the char value
	return lhs.getLetter() == rhs;
}