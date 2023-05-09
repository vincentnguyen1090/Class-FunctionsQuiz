//
// Created by Dave Smith on 1/28/23.
//

#include "functions.h"

//auto automatically makes the variable or data structure convert to that type

std::vector<std::string> split(std::string key, const std::string& delimiter)
{
    std::vector<std::string> v;
    while(key.size() > 0)
    {
        //stores position of deliminter in index variable
        int index = key.find(delimiter);
        //true if index not equal to npos
        if(index != std::string::npos)
        {
            v.push_back(key.substr(0, index));
            //new value of key = key - last substring
            key = key.substr(index+1);
        }
        else
            //if no deliminter is found
            break;
    }
    if(!key.empty())
    {
        //stores the last word
        v.push_back(key);
    }
    return v;
}

std::vector<std::vector<std::string>> generateIndex(const std::string& data)
{
    //store the split strings into vector "strings"
    std::vector<std::string> strings = split(data, " ");

    //construct a vector called "index" with size 26 for letters, and store it in vector of strings
    std::vector<std::vector<std::string>> index(26, std::vector<std::string>());

    for(const std::string& s : strings)
    {
        //store each word into 't'
        //each work is modified to removePunctuation and tolower
        std::string t = removePunctuation(tolower(s));
        if(!contains(index[charToIndex(s[0])], t))
            //pushback a new letter if not already in file
            index[charToIndex(s[0])].push_back(t);
    }
    for(std::vector<std::string>& s : index)
        sort(s);
    return index;
}
int charToIndex(char c)
{
    return toupper(c) - 'A';
}
bool openFile(std::ifstream& fin, const std::string& filename)
{
    fin.open(filename);
    return !fin.fail();
}
std::vector<std::string> getIndex(char c, const std::vector<std::vector<std::string>>& index)
{
    return index[charToIndex(c)];
}
void print(const std::vector<std::vector<std::string>>& index)
{
    for(int i=0; i < index.size(); i++)
    {
        std::cout << static_cast<char>(i + 'A') << ": ";
        for(const std::string& s : index[i])
            std::cout << s << " ";
        std::cout << std::endl;
    }
}

bool contains(const std::vector<std::string>& vector, const std::string& string)
{
    for(const std::string& s : vector)
        if(tolower(s) == tolower(string))
            return true;
    return false;
}
std::string tolower(const std::string& string)
{
    std::string s;
    for(char c : string)
        s.push_back(tolower(c));
    return s;
}
void sort(std::vector<std::string>& vector)
{
    std::sort(vector.begin(), vector.end());
}

std::string removePunctuation(const std::string& string)
{
    int i = string.size() -1;
    if(!isalpha(string[i]))
        return string.substr(0, i);
    else
        return string;
}


std::string getFileContent(const std::string &filename)
{
    std::ifstream fin;
    std::string s, next;
    if(!openFile(fin, filename))
        exit(28);
    while(getline(fin, next))
        s += next + " ";
    fin.close();
    return s;
}
