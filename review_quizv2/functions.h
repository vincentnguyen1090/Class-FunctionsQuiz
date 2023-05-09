//
// Created by Dave Smith on 1/28/23.
//

#ifndef CS3A_SPRING23_QUIZ1_FUNCTIONS_H
#define CS3A_SPRING23_QUIZ1_FUNCTIONS_H
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include <algorithm>
//// Why are things so red in here?

/// Function definition is missing
std::vector<std::string> split(std::string key, const std::string& delimiter);

/// Function is broken, it should remove punctuation from each word.
/// Function also needs to sort each list of words alphabetically
std::vector<std::vector<std::string>> generateIndex(const std::string& filename);

///Function is broken ?????
bool openFile(std::ifstream& fin, const std::string& filename);

///Need a driver for this function
std::vector<std::string> getIndex(char c, const std::vector<std::vector<std::string>>& index);


/// These function are working as they should!!
void print(const std::vector<std::vector<std::string>>& index);
bool contains(const std::vector<std::string>& vector, const std::string& string);
std::string tolower(const std::string& string);
void sort(std::vector<std::string>& vector);
std::string removePunctuation(const std::string& string);
std::string getFileContent(const std::string& filename);
int charToIndex(char c);

#endif //CS3A_SPRING23_QUIZ1_FUNCTIONS_H
