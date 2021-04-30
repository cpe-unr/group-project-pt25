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
string getFileName()
{
    string ODP; //Name of the file without the .wav extension
    std::cout << "Enter File Name (without .wav file extension)" << std::endl;
    std::cin >> ODP;
    ODP = ODP + ".wav"
    return ODP;
}

int main() {
    string choiceOne; //Initial user choice to continue using program or to exit program
    std::cout << "Enter Yes to continue or enter No to exit" << std:endl
    std::cin >> choiceOne
    if(choiceOne == "yes" || "Yes")
    {
        string fileName = getFileName();
        switch()
    }
    return 0;
}
