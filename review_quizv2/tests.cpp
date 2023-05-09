//
// Created by Dave R. Smith on 1/31/23.
//

#include "tests.h"

void driver()
{
    char answer;
    std::string data = getFileContent("key.txt");
    std::vector<std::vector<std::string>> index = generateIndex(data);
    do
    {
        std::cout << "Enter a letter: ";
        char c;
        std::cin >> c;
        std::vector<std::string> v = getIndex(c, index);
        //print(v);

        std::cout << "Do you want to test another letter? y/n: ";
        std::cin >> answer;
    }
    while(tolower(answer == 'y'));
}