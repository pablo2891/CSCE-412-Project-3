#ifndef WEB_SERVER_H
#define WEB_SERVER_H


#include <chrono>
#include "request.h"

/* The WebServer class manages incoming requests, processes them, and updates its status based on the
cycle time. */
class WebServer {
private:
    bool is_busy;
    Request current_request;

public:
    // Constructor
    WebServer();

    // Method to process a new request
    void processRequest(const Request& request);

    // Method to check if the server is busy
    bool isBusy() const;

    // Method to update the server's state
    void update(int cycle_time);
};

#endif // WEB_SERVER_H