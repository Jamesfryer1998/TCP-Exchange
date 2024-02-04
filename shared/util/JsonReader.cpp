#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#include "JsonReader.h"

JSONHandler::JSONHandler(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        // Handle the error as needed (throw exception, return error code, etc.)
    }

    // Read the entire file into a string
    std::stringstream buffer;
    buffer << file.rdbuf();
    jsonString = buffer.str();
}

bool JSONHandler::parse(std::map<std::string, double>& data) {
    try {
        size_t pos = 0;
        while ((pos = jsonString.find(':')) != std::string::npos) {
            size_t keyStart = jsonString.rfind('"', pos) + 1;
            size_t keyEnd = jsonString.find('"', keyStart);
            size_t valueStart = jsonString.find('"', pos) + 1;
            size_t valueEnd = jsonString.find('"', valueStart);

            std::string key = jsonString.substr(keyStart, keyEnd - keyStart);
            double value = std::stod(jsonString.substr(valueStart, valueEnd - valueStart));

            data[key] = value;

            // Remove the processed part from the string
            jsonString.erase(0, valueEnd + 1);
        }
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        return false;
    }
}

bool JSONHandler::saveToJson(const std::map<std::string, double>& currencies) {
    try {
        std::ofstream outFile(fileName);
        if (!outFile.is_open()) {
            std::cerr << "Error opening file for writing: " << fileName << std::endl;
            return false;
        }

        // Start the JSON object
        outFile << "{";

        // Iterate over each currency entry and append it to the JSON file
        for (auto it = currencies.begin(); it != currencies.end(); ++it) {
            outFile << "\"" << it->first << "\":" << it->second;
            if (std::next(it) != currencies.end()) {
                outFile << ",";
            }
        }

        // Close the JSON object
        outFile << "}";

        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error saving to JSON: " << e.what() << std::endl;
        return false;
    }
}