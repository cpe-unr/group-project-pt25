/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

/* @file */

#include <iostream>
#include "Echo.h"
#include "Wav.h"

/*
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

std::string getFileName()
{
    std::string file_name; //Name of the file without the .wav extension
    std::cout << "Enter the file name (with .wav extension)" << std::endl;
    std::cin >> file_name;
    return file_name;
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
	std::cout << "\nAUDIO MENU\n 1. Modify Metadata\n 2. Process File\n 3. Display File Information\n 4. Export CSV File\n 5. Save As\n 0. End Program\n\n";
	std::cin >> choice;
	return choice;
}

int getProcessorChoice()
{
	int choice = 0;
	std::cout << "\nSELECT A PROCESSOR\n 1. Echo\n 2. Noise Gate\n 3. Normalize\n 0. Stop Modifying\n\n";
	std::cin >> choice;
	return choice;
}

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
	        		processor->processBufferEight(format_data, buffer_data.buffer, buffer_data.size);
	        		delete processor;
        		}
    			break;
  			case 2:
    			break;
			case 3:
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