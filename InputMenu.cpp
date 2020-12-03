#include "InputMenu.h"

/**
 * @author PengJu Chang, Yu Fan Chen , Logan Gunn , Everett Scott Melanson , William Zhen Yu Ngo
 * @class InputMenu
 * @brief static class to provide application with simple methods to get validate userInput and return it.
 */

/**
 * @brif yesOrNoMenuChoice - prompts user for yes or no
 * @details displays param menuText to the screen and prompts user for yes or no (y or n)
 * @param menuText - text to display to the screen
 * @return bool - true or false depending on user input
 */
bool InputMenu::yesOrNoMenuChoice(std::string menuText) {
    return optionalMenuChoice(menuText, {'y','n'}) == 'y';
}

/**
 * @brief intMenuChoice - prompts user to enter an int
 * @details - displays param menuText to the screen and prompts user for an int
 * @param menuText - text to be displayed to the screen
 * @return int - the user inputted
 */
int InputMenu::intMenuChoice(std::string menuText) {
    int choice;
    std::cout << menuText << std::endl;
    std::cin >> choice;
    while (choice <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a valid number! " << std::endl;
        std::cin >> choice;
    }
    return choice;
}

/**
 * @brief standardCallChoice - prompts user for hit, stand, advanced call, or clue
 * @details displays text prompting user to choose from hit, stand, advanced, or clue and returns char chosen
 * @return char - chosen
 */
char InputMenu::standardCallChoice() {
    return optionalMenuChoice("Hit (h), Stand (s), Advanced Call (a), or Clue (c)? ", {'h','s','a','c'});
}

/**
 * @brief advancedCallChoice - prompts user for double down, or surrender,
 * @details displays text prompting user to choose from double down, stand, advanced, or clue and returns char chosen
 * @return char - chosen
 */
char InputMenu::advancedCallChoice() {
    return optionalMenuChoice("Double Down (d), or Surrender(s)? ", {'d','s'});
}


/**
 * @brief optionalMenuChoice - prompts user with menuText and waits for correct input from options
 * @param menuText - text displayed on screen
 * @param options - list of options user is allowed to choose
 * @return char - one of the chars in options that the user inputs
 */
char InputMenu::optionalMenuChoice(std::string menuText, std::vector<char> options) {
    std::cout << menuText << std::endl;
    char choice;
    bool choiceMatchesOptions = false;


    while (!choiceMatchesOptions) {
        std::cout << "Please enter one of the options: " <<  std::endl;
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (auto option: options) {
            if (choice == option) {
                choiceMatchesOptions = true;
                break;
            }
        }
    }
    return choice;
}
