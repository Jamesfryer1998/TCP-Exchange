#ifndef MESSAGEFORMAT_H
#define MESSAGEFORMAT_H

#include <cstdint>
#include <vector>

// Example of a simple message structure
struct SimpleMessage {
    uint32_t id;
    float value;
};

// Serialization and deserialization functions
std::vector<char> serialize(const SimpleMessage& message);
SimpleMessage deserialize(const std::vector<char>& data);

#endif // MESSAGEFORMAT_H