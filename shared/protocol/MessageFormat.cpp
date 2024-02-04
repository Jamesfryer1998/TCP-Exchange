#include "MessageFormat.h"
#include <cstring>

// Serialize a SimpleMessage into a binary format
std::vector<char> serialize(const SimpleMessage& message) {
    std::vector<char> data;

    // Allocate enough space for the entire message
    data.resize(sizeof(message.id) + sizeof(message.value));

    // Copy the ID into the buffer
    std::memcpy(data.data(), &message.id, sizeof(message.id));

    // Copy the value into the buffer
    std::memcpy(data.data() + sizeof(message.id), &message.value, sizeof(message.value));

    return data;
}

// Deserialize a binary data buffer into a SimpleMessage
SimpleMessage deserialize(const std::vector<char>& data) {
    SimpleMessage message;

    // Check that the data size is correct
    if (data.size() != sizeof(SimpleMessage)) {
        // Handle error - the data is not the correct size
        throw std::runtime_error("Invalid data size for deserialization");
    }

    // Extract the ID from the buffer
    std::memcpy(&message.id, data.data(), sizeof(message.id));

    // Extract the value from the buffer
    std::memcpy(&message.value, data.data() + sizeof(message.id), sizeof(message.value));

    return message;
}