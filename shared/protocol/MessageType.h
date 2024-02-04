#ifndef MESSAGETYPE_H
#define MESSAGETYPE_H

// Enumerate different types of messages
enum class MessageType {
    UNKNOWN,
    ORDER_SUBMISSION,
    ORDER_CANCELLATION,
    ORDER_SUCCESSFUL,
    ORDER_FAILED,
    MARKET_DATA_REQUEST,
    AUTHENTICATION,
    EXECUTION_REPORT,
    HEARTBEAT
    // Add more types as needed
};

#endif // MESSAGETYPE_H