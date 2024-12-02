#include <fstream>
#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <string>

std::vector<std::vector<int>> get_input() {
    std::vector<std::vector<int>> input;

    std::ifstream file("input.txt");
    std::string line;
    int line_nr = 0;

    while (getline(file, line)) {
        input.push_back({});
        std::stringstream stream(line);
        int number;
        while(stream >> number){
            input[line_nr].push_back(number);
        }

        line_nr++;
    }

    return input;
}


// returns -1 on correct report
// if not -1 return value is index of faulty number
bool check_report(std::vector<int> report) {
    int last_number = 0;
    bool direction = report[0] > report[1]; // als omlaag gaat dan true else false

    int j;

    for (j = 0; j < report.size(); j++) { 
        int number = report[j];
        int diff = std::abs(number - last_number);

        bool diff_allowed = diff >= 1 && diff <= 3; // "Any two adjacent levels differ by at least one and at most three."
        bool dir_allowed = last_number > number == direction; // "The levels are either all increasing or all decreasing."
        if (j == 0) {dir_allowed = true; diff_allowed = true;}

        if (!diff_allowed || !dir_allowed) {
            return false;
            break;
        }

        last_number = number;
    }

    return true;
}


int main() {
    std::vector<std::vector<int>> input = get_input();

    int total_reports = 0;
    int safe_reports = 0;
     for (int i = 0; i < input.size(); i++) {
        total_reports++;

        bool valid = false;
        std::vector<int> report = input[i];
        std::vector<int> report_tolerate = report;

        // probeer alle mogelijkheden
        for (int j = 0; j < report.size(); j++) {
            report_tolerate = report;
            report_tolerate.erase(report_tolerate.begin() + j);
            bool result = check_report(report_tolerate);
            if (result) {valid = true;};
        }

        if (valid) safe_reports++;
    }

    std::cout << "Total reports: " << total_reports << std::endl;
    std::cout << "Total safe reports: " << safe_reports << std::endl;
    return 0;
}


// https://cplusplus.com/reference/vector/vector/size/
// https://stackoverflow.com/questions/17724925/parse-string-containing-numbers-into-integer-array
// https://stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index