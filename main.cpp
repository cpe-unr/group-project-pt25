/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

/** @file */
#include <iostream>

#include "Wav.h"

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
void fn()
{

}

std::string getFileName()
{
    std::string file_name; //Name of the file without the .wav extension
    std::cout << "Enter the file name (with .wav extension)" << std::endl;
    std::cin >> file_name;
    return file_name;
}

std::string setNewFileName(const std::string &file_name)
{
	std::string new_file_name;
	do
	{
		std::cout << "Enter a new file name (different from original and with .wav extension)" << std::endl;;
		std::cin >> new_file_name;
	}
	while(new_file_name == file_name);
	return new_file_name;
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
	std::cout << "AUDIO MENU\n 1. Read File\n 2. Modify Metadata\n 3. Process File\n 4. Display File Information\n 0. End Program\n";
	std::cin >> choice;
	return choice;
}

int getProcessorChoice()
{
	int choice = 0;
	std::cout << "SELECT A PROCESSOR\n 1. Echo\n 2. Noise Gate\n 3. Normalize\n 4. Stop Modifying\n 0. End Program\n";
	std::cin >> choice;
	return choice;
}

void fileProcessing(Wav &wav)
{
	int amount = getAmount();
	int processorChoice = 0;
	auto format_data = wav.formatData();
	auto buffer_data = wav.bufferData();
	for(int i = 0; i < amount; i++)
	{
		processorChoice = getProcessorChoice();
		switch(processorChoice) {
  			case 1:
				std::cout << "Echo" << std::endl;
				//Processor *processor = new Limiter();
        		//processor->processBuffer(format_data, buffer_data.buffer, buffer_data.size);
        		//wav.writeFile("limit.wav");
        		//delete processor;
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
	try
	{
		std::string file_name = getFileName();
		//std::vector<Wav> waves;
		Wav wav;
		//std::string new_file_name = setNewFileName(file_name);
		int menuChoice = 0;
		do
		{
			menuChoice = getMenuChoice();
			switch(menuChoice) {
				case 1:
					{
						std::cout << "Read File" << std::endl;
						//waves.push_back(Wav{file_name});
						wav.readFile (file_name);
					}
					break;
				case 2:
					std::cout << "Modify Metadata" << std::endl;
					break;
				case 3:
					std::cout << "Process File" << std::endl;
					//fileProcessing(waves.at(0));
					fileProcessing(wav);
					break;
				case 4:
					std::cout << "Display File Information" << std::endl;
					wav.print();
					break;
				case 0:
					return 0;
				default:
					std::cout << "Please enter a valid option!" << std::endl;
					break;
				}
		} while (menuChoice != 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}