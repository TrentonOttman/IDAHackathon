#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <iomanip> // for std::setprecision

// Function to trim leading and trailing spaces
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

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

    // Initialize counts for each category
    for (int i = 1; i <= 8; ++i) {
        countMap["CA" + std::to_string(i)] = 0;
    }
    for (int i = 1; i <= 3; ++i) {
        countMap["CB" + std::to_string(i)] = 0;
    }
    for (int i = 1; i <= 7; ++i) {
        countMap["CC" + std::to_string(i)] = 0;
    }
    for (int i = 1; i <= 6; ++i) {
        countMap["CD" + std::to_string(i)] = 0;
    }
    for (int i = 1; i <= 9; ++i) {
        countMap["CE" + std::to_string(i)] = 0;
    }

    int totalCA = 0, totalCB = 0, totalCC = 0, totalCD = 0, totalCE = 0;  // To hold total counts for each group
    std::string line;

    // Read file line by line
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        int cellIndex = 0; // To track which cell we are currently processing

        // Read each cell (comma-separated value) in the line
        while (std::getline(lineStream, cell, ',')) {
            // Trim spaces from the cell
            cell = trim(cell);
            cellIndex++; // Increment cell index
            
            // Check for CAx
            if (cell.rfind("CA", 0) == 0) {
                totalCA++;  // Increment total "CA" count
                countMap[cell]++;
            }
            // Check for CBx
            else if (cell.rfind("CB", 0) == 0) {
                totalCB++;  // Increment total "CB" count
                countMap[cell]++;
            }
            // Check for CCx
            else if (cell.rfind("CC", 0) == 0) {
                totalCC++;  // Increment total "CC" count
                countMap[cell]++;
            }
            // Check for CDx
            else if (cell.rfind("CD", 0) == 0) {
                totalCD++;  // Increment total "CD" count
                countMap[cell]++;
            }
            // Check for CEx
            else if (cell.rfind("CE", 0) == 0) {
                totalCE++;  // Increment total "CE" count
                countMap[cell]++;
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

    std::cout << std::endl;

    // Output the results for CB1 to CB3
    std::cout << "The string 'CB' occurs " << totalCB << " times in total." << std::endl;
    for (int i = 1; i <= 3; ++i) {
        std::string key = "CB" + std::to_string(i);
        double percentage = (totalCB > 0) ? (static_cast<double>(countMap[key]) / totalCB) * 100 : 0.0;
        std::cout << key << " occurs " << countMap[key] << " times (" 
                  << std::setprecision(2) << std::fixed << percentage << "% of total CB occurrences)." << std::endl;
    }

    std::cout << std::endl;

    // Output the results for CC1 to CC7
    std::cout << "The string 'CC' occurs " << totalCC << " times in total." << std::endl;
    for (int i = 1; i <= 7; ++i) {
        std::string key = "CC" + std::to_string(i);
        double percentage = (totalCC > 0) ? (static_cast<double>(countMap[key]) / totalCC) * 100 : 0.0;
        std::cout << key << " occurs " << countMap[key] << " times (" 
                  << std::setprecision(2) << std::fixed << percentage << "% of total CC occurrences)." << std::endl;
    }

    std::cout << std::endl;

    // Output the results for CD1 to CD6
    std::cout << "The string 'CD' occurs " << totalCD << " times in total." << std::endl;
    for (int i = 1; i <= 6; ++i) {
        std::string key = "CD" + std::to_string(i);
        double percentage = (totalCD > 0) ? (static_cast<double>(countMap[key]) / totalCD) * 100 : 0.0;
        std::cout << key << " occurs " << countMap[key] << " times (" 
                  << std::setprecision(2) << std::fixed << percentage << "% of total CD occurrences)." << std::endl;
    }

    std::cout << std::endl;

    // Output the results for CE1 to CE9
    std::cout << "The string 'CE' occurs " << totalCE << " times in total." << std::endl;
    for (int i = 1; i <= 9; ++i) {
        std::string key = "CE" + std::to_string(i);
        double percentage = (totalCE > 0) ? (static_cast<double>(countMap[key]) / totalCE) * 100 : 0.0;
        std::cout << key << " occurs " << countMap[key] << " times (" 
                  << std::setprecision(2) << std::fixed << percentage << "% of total CE occurrences)." << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
