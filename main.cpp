/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

/** @file */

#include <iostream>
#include "Echo.h"
#include "Noisegate.h"
#include "Normalization.h"
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

/**
 * Prompts the user for the name of the file the user wishes to read.
 * @return
 */

std::string getFileName()
{
    std::string file_name; //Name of the file without the .wav extension
    std::cout << "Enter the file name (with .wav extension)" << std::endl;
    std::cin >> file_name;
    return file_name;
}

/**
 * Prompts the user for number of times the user wishes to process the file they selected
 * @param amount
 * @return
 */

int getAmount()
{
	int amount = 0;
	std::cout << "How many modifications would you like to make?" << std::endl;
	std::cin >> amount;
	return amount;
}

/**
 * Prompts the user the action they would like to perform on the file and prints the available actions to the screen
 * @param choice
 * @return
 */

int getMenuChoice()
{
	int choice = 0;
	std::cout << "\nAUDIO MENU\n 1. Modify Metadata\n 2. Process File\n 3. Display File Information\n 4. Export CSV File\n 5. Save As\n 0. End Program\n\n";
	std::cin >> choice;
	return choice;
}

/**
 * Prompts the user which process they would like to perform on their selected audio file
 * @param choice
 * @return
 */

int getProcessorChoice()
{
	int choice = 0;
	std::cout << "\nSELECT A PROCESSOR\n 1. Echo\n 2. Noise Gate\n 3. Normalize\n 0. Stop Modifying\n\n";
	std::cin >> choice;
	return choice;
}

/**
 * Prompts the user for the name of the new file they are saving and stores it as a string
 * @param result
 * @return
 */

std::string promptForString(const std::string &prompt_text)
{
	std::string result;
	do
	{
		std::cout << prompt_text << std::endl;
		std::cin >> result;	
	} while (result.empty());
	return result;
}

/**
 * Handles the calling of each processor based on user input
 * @param amount
 * @param processorChoice
 * @param format_data
 * @param buffer_data
 * @return
 */

void fileProcessing(Wav &wav, const std::string &file_name)
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
  				{
					Processor *processor = new Echo(20000);
					if(format_data.bit_depth == 8)
					{
						processor->processBufferEight(format_data, buffer_data.buffer, buffer_data.size);
					}
	        		else if (format_data.bit_depth == 16)
					{
						//Treat byte buffer as 16-bit data instead of 8-bit data, the length becomes half
						processor->processBufferSixteen(format_data, reinterpret_cast<unsigned short*>(buffer_data.buffer), buffer_data.size / 2);
					}
					else
					{
						throw std::runtime_error ("Unsupported Bit Depth");
					}
	        		delete processor;
        		}
    			break;
  			case 2:
  				{
					Processor *processor = new NoiseGate(3.0);
					if(format_data.bit_depth == 8)
					{
						processor->processBufferEight(format_data, buffer_data.buffer, buffer_data.size);
					}
	        		else if (format_data.bit_depth == 16)
					{
						//Treat byte buffer as 16-bit data instead of 8-bit data, the length becomes half
						processor->processBufferSixteen(format_data, reinterpret_cast<unsigned short*>(buffer_data.buffer), buffer_data.size / 2);
					}
					else
					{
						throw std::runtime_error ("Unsupported Bit Depth");
					}
	        		delete processor;
        		}
    			break;
			case 3:
				{
					Processor *processor = new Normalizer(0.5);
					if(format_data.bit_depth == 8)
					{
						processor->processBufferEight(format_data, buffer_data.buffer, buffer_data.size);
					}
	        		else if (format_data.bit_depth == 16)
					{
						//Treat byte buffer as 16-bit data instead of 8-bit data, the length becomes half
						processor->processBufferSixteen(format_data, reinterpret_cast<unsigned short*>(buffer_data.buffer), buffer_data.size / 2);
					}
					else
					{
						throw std::runtime_error ("Unsupported Bit Depth");
					}
	        		delete processor;
        		}
    			break;
			case 0:
				i = amount;
				break;
  			default:
			  	std::cout << "Please enter a valid option!" << std::endl;
				i--;
			  	break;
			}
	}
}

/**
 * Main entry point of the program. Handles calls of functions for user interaction, file processing, and file generation
 * @param menuChoice
 * @return
 */

int main() {
	try
	{
		std::string file_name = getFileName();
		Wav wav {file_name};
		std::cout << std::endl;
		wav.print();
		int menuChoice = 0;
		do
		{
			menuChoice = getMenuChoice();
			switch(menuChoice) {
				case 1:
					wav.setTitle(promptForString("Enter title"));
					wav.setArtist(promptForString("Enter artist"));
					break;
				case 2:
					fileProcessing(wav, file_name);
					break;
				case 3:
					std::cout << std::endl;
					wav.print();
					std::cout << std::endl;
					break;
				case 4:
					wav.appendCSV(promptForString("Enter CSV file to append to (with .csv extension)"));
					break;
				case 5:
					{
						auto new_file_name = promptForString("Enter a new file name (different from original and with .wav extension)");
						if(new_file_name != wav.fileName())
						{
							wav.saveAs(new_file_name);
						}
						else
						{
							std::cout << "Please save to a different file name\n";
						}
					}
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
