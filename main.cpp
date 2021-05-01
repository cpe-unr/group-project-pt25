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

std::string setNewFileName()
{
	std::string newFileName;
	std::cout << "Enter a new file name (different from original and without .wav extension)" << std::endl;;
	std::cin >> newFileName;
	newFileName = newFileName + ".wav";
	return newFileName;
}

int getAmount()
{
	int amount = 0;
	std::cout << "How many modifications would you like to make?" << std::endl;
	std::cin >> amount;
	return amount;
}

int getChoice()
{
	int choice = 0;
	std::cout << "PROCESSORS\n 1. Echo\n 2. Noise Gate\n 3. Normalize\n 4. Stop Modifying\n 0. End Program\n Enter your choice: " << std::endl;
	std::cin >> choice;
	return choice;
}

int main() {
	std::string fileName = getFileName();
	std::string newFileName;
	int amount = getAmount();
	int choice = 0;
	for(int i = 0; i < amount; i++)
	{
		choice = getChoice();
		switch(choice) {
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
				return 0;
  			default:
			  	std::cout << "Please enter a valid option!" << std::endl;
				i--;
			  	break;
			}
	}
	do
	{
		newFileName = setNewFileName();
	}
	while(newFileName == fileName);

    return 0;
}
