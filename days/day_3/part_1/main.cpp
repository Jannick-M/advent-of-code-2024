#include <string>
#include <iostream>
#include <regex>
#include <sstream>
#include <streambuf>
#include <fstream>

std::vector<int> split(std::string str, char delimiter)
{
    std::stringstream ss(str);
    std::vector<int> res;
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        res.push_back(stoi(token));
    }
    return res;
}

int main() {
    std::ifstream file("input.txt");
    std::string input((std::istreambuf_iterator<char>(file)),
                             std::istreambuf_iterator<char>());

    std::regex r("mul\\(\\d+,\\d+\\)");

    unsigned int total = 0;
    for(std::sregex_iterator i = std::sregex_iterator(input.begin(), input.end(), r);
                            i != std::sregex_iterator();
                            ++i )
    {
        std::smatch m = *i;
        std::string formula = m.str();
        formula.erase(0, 4);
        formula.erase(formula.end() - 1);

        std::vector<int> nums = split(formula, *",");
        total += nums[0] * nums[1];
    }

    std::cout << "total: " << total << std::endl;
}

// https://regexone.com/
// https://regex101.com/