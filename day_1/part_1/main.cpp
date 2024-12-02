#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::vector<unsigned long> location_ids1 = {}; 
    std::vector<unsigned long> location_ids2 = {}; 

    std::string line;
    std::ifstream file("input.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            std::string input_line = line;

            std::istringstream ss(input_line);
                
            // Declare two integer variables
            unsigned long num1, num2;
            
            // Extract two integers from the stringstream
            ss >> num1 >> num2;
            location_ids1.push_back(num1);
            location_ids2.push_back(num2);
        }
        file.close();
    }

    std::sort(location_ids1.begin(), location_ids1.end());
    std::sort(location_ids2.begin(), location_ids2.end());

    int total_diff = 0;
    for (unsigned long i = 0; i < location_ids1.size(); i++) {
        unsigned long diff = std::llabs(location_ids1[i] - location_ids2[i]);
        total_diff += diff;
    }

    std::cout << "total difference: " << total_diff << "\n";
    return 0;
}
