#include <fstream>
#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

int main() {
    std::ifstream file("input.txt");

    int safe_reports = 0;
    int total_reports = 0;

    std::string line;
    while (getline(file, line)) {
        total_reports++;

        std::stringstream stream(line);

        int lastNumber; stream >> lastNumber;
        int number;

        bool safe = true;
        int direction = 0;

        while(stream >> number){
            int diff = std::abs(number - lastNumber);

            int current_direction = (-1*(lastNumber-number));
            if (current_direction != 0) current_direction = current_direction/abs(current_direction);
            if (direction == 0) direction = current_direction;

            // "Any two adjacent levels differ by at least one and at most three."
            bool diff_allowed = diff >= 1 && diff <= 3;
            // "The levels are either all increasing or all decreasing."
            bool dir_allowed = current_direction == direction;
            if (!diff_allowed || !dir_allowed) {
                safe = false;
                break;
            }

            lastNumber = number;
        }

        if (safe) safe_reports++;
    }

    file.close();

    std::cout << "Total reports: " << total_reports << std::endl;
    std::cout << "Total safe reports: " << safe_reports << std::endl;
    return 0;
}


// https://www.geeksforgeeks.org/how-to-read-file-into-string-in-cpp/
// https://stackoverflow.com/questions/17724925/parse-string-containing-numbers-into-integer-array
// https://stackoverflow.com/questions/4745617/how-to-make-negative-numbers-into-positive
