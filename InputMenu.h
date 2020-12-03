#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <limits>


class InputMenu {
    public:
        static bool yesOrNoMenuChoice(std::string menuText);
        static int intMenuChoice(std::string menuText);
        static char standardCallChoice();
        static char advancedCallChoice();
        static char optionalMenuChoice(std::string menuText, std::vector<char> options);
};
