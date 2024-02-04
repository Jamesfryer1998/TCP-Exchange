#pragma once
#include <string>

class JSONHandler {
public:
    explicit JSONHandler(const std::string& fileName);

    // Parse JSON and update a map
    bool parse(std::map<std::string, double>& data);

    bool saveToJson(const std::map<std::string, double>& currencies);

private:
    std::string jsonString;
    std::string fileName;
    
};