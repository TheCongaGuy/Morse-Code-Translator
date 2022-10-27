#include "BST.hpp"
#include "MorseCode.hpp"	

int main(int argc, char argv[])
{
	// Instantiate a BST from the MorseTable.txt file
	const BST<MorseCode> MorseBST("MorseTable.txt");

	// Print the tree
	MorseBST.printTree();

	// Extract each character from the file
	std::ifstream file("Convert.txt");

	while (!file.eof())
	{
		// Catches the line of text from the convert file
		char letter, cStr[100];

		file.getline(cStr, 100);

		// Translate each letter to morse code in the line
		for (int i = 0; i < 100 && cStr[i] != '\0'; i++)
		{
			letter = toupper(cStr[i]);
			if (letter == ' ')
				std::cout << "  ";

			else
				std::cout << MorseBST.search(letter)->getData().getMorse() << " ";
		}

		// Add a new line before the start of the next
		std::cout << std::endl;
	}

	// Close the file when done
	file.close();

	return 0;
}