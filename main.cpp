/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

/** @file */
#include <iostream>

/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
void fn(){

}
std::string getFileName()
{
    std::string fileName; //Name of the file without the .wav extension
    std::cout << "Enter the file name (without .wav extension)" << std::endl;
    std::cin >> fileName;
    fileName = fileName + ".wav";
    return fileName;
}

std::string setNewFileName(std::string fileName)
{
	std::string newFileName;
	do
	{
		std::cout << "Enter a new file name (different from original and without .wav extension)" << std::endl;;
		std::cin >> newFileName;
		newFileName = newFileName + ".wav";
		newFileName = setNewFileName(fileName);
	}
	while(newFileName == fileName);
	return newFileName;
}

int getAmount()
{
	int amount = 0;
	std::cout << "How many modifications would you like to make?" << std::endl;
	std::cin >> amount;
	return amount;
}

int getMenuChoice()
{
	int choice = 0;
	std::cout << "AUDIO MENU\n 1. Read File\n2. Modify Metadata\n3. Process File\n4. Display File Information\n0. End Program\n";
	std::cin >> choice;
	return choice;
}

int getProcessorChoice()
{
	int choice = 0;
	std::cout << "PROCESSORS\n 1. Echo\n 2. Noise Gate\n 3. Normalize\n 4. Stop Modifying\n 0. End Program\n";
	std::cin >> choice;
	return choice;
}

void processorMenu()
{
	int amount = getAmount();
	int processorChoice = 0;
	for(int i = 0; i < amount; i++)
	{
		processorChoice = getProcessorChoice();
		switch(processorChoice) {
  			case 1:
				std::cout << "Echo" << std::endl;
    			break;
  			case 2:
				std::cout << "Noise Gate" << std::endl;
    			break;
			case 3:
				std::cout << "Normalizer" << std::endl;
    			break;
			case 4:
				std::cout << "Stopped" << std::endl;
				i = amount;
				break;
			case 0:
				exit;
  			default:
			  	std::cout << "Please enter a valid option!" << std::endl;
				i--;
			  	break;
			}
	}
}

int main() {
	std::string fileName = getFileName();
	std::string newFileName = setNewFileName(fileName);
	int menuChoice = 0;
	do
	{
		menuChoice = getMenuChoice();
		switch(menuChoice) {
  			case 1:
				std::cout << "Read File" << std::endl;
    			break;
  			case 2:
				std::cout << "Modify Metadata" << std::endl;
    			break;
			case 3:
				std::cout << "Process File" << std::endl;
				processorMenu();
    			break;
			case 4:
				std::cout << "Display File Information" << std::endl;
				break;
			case 0:
				return 0;
  			default:
			  	std::cout << "Please enter a valid option!" << std::endl;
			  	break;
			}
	} while (menuChoice != 0);
    return 0;
}
