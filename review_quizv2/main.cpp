#include <iostream>
#include "functions.h"
#include "tests.h"
int main()
{
    std::string data = getFileContent("key.txt");
    std::vector<std::vector<std::string>> index = generateIndex(data);
    print(index);
    return 0;

    //driver();
}
