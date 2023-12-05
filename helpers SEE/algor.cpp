#include <algorithm>
#include <string>

std::string removeSpaces(std::string input)
{
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    return input;
}

int main()
{
    std::string str = "Hello World";
    str = removeSpaces(str);
    std::cout << str; // Outputs: HelloWorld
    return 0;
}
