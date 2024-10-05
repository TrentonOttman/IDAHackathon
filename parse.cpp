#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
#include <algorithm>

struct CodeSeries {
    std::string prefix;
    int start;
    int end;
    CodeSeries(std::string p, int s, int e) : prefix(p), start(s), end(e) {}
};

int main() {
    std::ifstream file("production_data.csv");
    std::map<std::string, int> counts;
    std::map<std::string, int> prefixOnlyCounts;
    
    // Define all code series
    std::vector<CodeSeries> series = {
        CodeSeries("CA", 1, 8),
        CodeSeries("CB", 1, 3),
        CodeSeries("CC", 1, 7),
        CodeSeries("CD", 1, 6),
        CodeSeries("CE", 1, 9)
    };
    
    // Initialize counts for all codes
    for (const auto& s : series) {
        for (int i = s.start; i <= s.end; i++) {
            counts[s.prefix + std::to_string(i)] = 0;
        }
        prefixOnlyCounts[s.prefix] = 0;
    }
    
    std::string line;
    // Skip the first line (header)
    std::getline(file, line);
    
    // Read remaining lines
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        
        while (std::getline(ss, cell, ',')) {
            // Remove whitespace
            cell.erase(remove_if(cell.begin(), cell.end(), isspace), cell.end());
            
            // Check for prefix-only matches (e.g., "CA", "CB", etc.)
            for (const auto& s : series) {
                if (cell == s.prefix) {
                    prefixOnlyCounts[s.prefix]++;
                    goto next_cell;
                }
            }
            
            // Check for specific codes (e.g., "CA1", "CB2", etc.)
            for (const auto& s : series) {
                for (int i = s.start; i <= s.end; i++) {
                    std::string code = s.prefix + std::to_string(i);
                    if (cell == code) {
                        counts[code]++;
                        goto next_cell;
                    }
                }
            }
            
            next_cell:
            continue;
        }
    }
    
    file.close();
    
    // Output results for each series
    for (const auto& s : series) {
        int seriesTotal = 0;
        for (int i = s.start; i <= s.end; i++) {
            std::string code = s.prefix + std::to_string(i);
            seriesTotal += counts[code];
        }
        
        std::cout << "\nResults for " << s.prefix << " Series:\n";
        std::cout << "----------------------------------------\n";
        std::cout << "Code    Count    % of Series Total\n";
        std::cout << "----------------------------------------\n";
        
        std::cout << std::fixed << std::setprecision(2);
        
        for (int i = s.start; i <= s.end; i++) {
            std::string code = s.prefix + std::to_string(i);
            double percentage = seriesTotal > 0 ? 
                (counts[code] * 100.0) / seriesTotal : 0.0;
            
            std::cout << std::left << std::setw(8) << code 
                      << std::setw(9) << counts[code] 
                      << std::right << std::setw(9) << percentage << "%" 
                      << std::endl;
        }
        
        std::cout << "----------------------------------------\n";
        std::cout << std::left << std::setw(8) << "Total" 
                  << std::setw(9) << seriesTotal 
                  << std::right << std::setw(9) << "100.00%" 
                  << std::endl;
        
        // Print prefix-only count
        std::cout << "\nPlain '" << s.prefix << "' occurrences: " 
                  << prefixOnlyCounts[s.prefix] << std::endl;
        std::cout << "Series total (including plain '" << s.prefix << "'): " 
                  << (seriesTotal + prefixOnlyCounts[s.prefix]) << std::endl;
        std::cout << "\n";
    }
    
    // Calculate and display grand total
    int grandTotal = 0;
    int grandTotalWithPrefixes = 0;
    
    for (const auto& pair : counts) {
        grandTotal += pair.second;
    }
    for (const auto& pair : prefixOnlyCounts) {
        grandTotalWithPrefixes += pair.second;
    }
    grandTotalWithPrefixes += grandTotal;
    
    std::cout << "\nOverall Statistics:\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Total code occurrences: " << grandTotal << std::endl;
    std::cout << "Total including prefixes only: " << grandTotalWithPrefixes << std::endl;
    
    return 0;
}