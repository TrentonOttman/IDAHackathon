#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <iomanip> // for std::setprecision

int main() {
    // File name (you can modify it to the actual CSV file)
    std::string fileName = "production_data.csv";

    // Open the CSV file
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << fileName << std::endl;
        return 1;
    }

    // Skip the first line (header line)
    std::string header;
    std::getline(file, header);  // Read and discard the first line

    // Define a map to hold counts for CA1-CA8, CB1-CB3, CC1-CC7, CD1-CD6, CE1-CE9
    std::unordered_map<std::string, int> countMap;

    // Adding CA1 to CA8
    for (int i = 1; i <= 8; ++i) {
        countMap["CA" + std::to_string(i)] = 0;
    }

    // Adding CB1 to CB3
    for (int i = 1; i <= 3; ++i) {
        countMap["CB" + std::to_string(i)] = 0;
    }

    // Adding CC1 to CC7
    for (int i = 1; i <= 7; ++i) {
        countMap["CC" + std::to_string(i)] = 0;
    }

    // Adding CD1 to CD6
    for (int i = 1; i <= 6; ++i) {
        countMap["CD" + std::to_string(i)] = 0;
    }

    // Adding CE1 to CE9
    for (int i = 1; i <= 9; ++i) {
        countMap["CE" + std::to_string(i)] = 0;
    }

    int totalCA = 0, totalCB = 0, totalCC = 0, totalCD = 0, totalCE = 0;  // To hold total counts for each group
    std::string line, cell;

    // Read file line by line
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);

        // Read each cell (comma-separated value) in the line
        while (std::getline(lineStream, cell, ',')) {
            // Check for CAx
            if (cell.rfind("CA", 0) == 0) {
                totalCA++;  // Increment total "CA" count
                if (countMap.find(cell) != countMap.end()) {
                    countMap[cell]++;
                }
            }
            // Check for CBx
            else if (cell.rfind("CB", 0) == 0) {
                totalCB++;  // Increment total "CB" count
                if (countMap.find(cell) != countMap.end()) {
                    countMap[cell]++;
                }
            }
            // Check for CCx
            else if (cell.rfind("CC", 0) == 0) {
                totalCC++;  // Increment total "CC" count
                if (countMap.find(cell) != countMap.end()) {
                    countMap[cell]++;
                }
            }
            // Check for CDx
            else if (cell.rfind("CD", 0) == 0) {
                totalCD++;  // Increment total "CD" count
                if (countMap.find(cell) != countMap.end()) {
                    countMap[cell]++;
                }
            }
            // Check for CEx
            else if (cell.rfind("CE", 0) == 0) {
                totalCE++;  // Increment total "CE" count
                if (countMap.find(cell) != countMap.end()) {
                    countMap[cell]++;
                }
            }
        }
    }

    // Close the file
    file.close();

    // Output the results for CA1 to CA8
    std::cout << "The string 'CA' occurs " << totalCA << " times in total." << std::endl;
    for (int i = 1; i <= 8; ++i) {
        std::string key = "CA" + std::to_string(i);
        double percentage = (totalCA > 0) ? (static_cast<double>(countMap[key]) / totalCA) * 100 : 0.0;
        std::cout << key << " occurs " << countMap[key] << " times (" 
                  << std::setprecision(2) << std::fixed << percentage << "% of total CA occurrences)." << std::endl;
    }

    // Output the results for CB1 to CB3
    std::cout << "The string 'CB' occurs " << totalCB << " times in total." << std::endl;
    for (int i = 1; i <= 3; ++i) {
        std::string key = "CB" + std::to_string(i);
        double percentage = (totalCB > 0) ? (static_cast<double>(countMap[key]) / totalCB) * 100 : 0.0;
        std::cout << key << " occurs " << countMap[key] << " times (" 
                  << std::setprecision(2) << std::fixed << percentage << "% of total CB occurrences)." << std::endl;
    }

    // Output the results for CC1 to CC7
    std::cout << "The string 'CC' occurs " << totalCC << " times in total." << std::endl;
    for (int i = 1; i <= 7; ++i) {
        std::string key = "CC" + std::to_string(i);
        double percentage = (totalCC > 0) ? (static_cast<double>(countMap[key]) / totalCC) * 100 : 0.0;
        std::cout << key << " occurs " << countMap[key] << " times (" 
                  << std::setprecision(2) << std::fixed << percentage << "% of total CC occurrences)." << std::endl;
    }

    // Output the results for CD1 to CD6
    std::cout << "The string 'CD' occurs " << totalCD << " times in total." << std::endl;
    for (int i = 1; i <= 6; ++i) {
        std::string key = "CD" + std::to_string(i);
        double percentage = (totalCD > 0) ? (static_cast<double>(countMap[key]) / totalCD) * 100 : 0.0;
        std::cout << key << " occurs " << countMap[key] << " times (" 
                  << std::setprecision(2) << std::fixed << percentage << "% of total CD occurrences)." << std::endl;
    }

    // Output the results for CE1 to CE9
    std::cout << "The string 'CE' occurs " << totalCE << " times in total." << std::endl;
    for (int i = 1; i <= 9; ++i) {
        std::string key = "CE" + std::to_string(i);
        double percentage = (totalCE > 0) ? (static_cast<double>(countMap[key]) / totalCE) * 100 : 0.0;
        std::cout << key << " occurs " << countMap[key] << " times (" 
                  << std::setprecision(2) << std::fixed << percentage << "% of total CE occurrences)." << std::endl;
    }

    return 0;
}
