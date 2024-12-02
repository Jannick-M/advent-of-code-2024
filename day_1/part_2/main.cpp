#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::vector<unsigned long> location_ids_l = {}; 
    std::vector<unsigned long> location_ids_r = {}; 

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
            location_ids_l.push_back(num1);
            location_ids_r.push_back(num2);
        }
        file.close();
    }


    unsigned long long similarity_score = 0;
    for (int i = 0; i < location_ids_l.size(); i++) {
        unsigned long num = location_ids_l[i];
        int times_found = 0;

        for (int j = 0; j < location_ids_r.size(); j++) {
            if (num == location_ids_r[j]) times_found++;
        }
        similarity_score += num * times_found;
    }

    std::cout << "Similarity score: " << similarity_score << "\n";
}
