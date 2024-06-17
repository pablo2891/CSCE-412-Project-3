#include "web_server.h"
#include "request.h"
#include "load_balancer.h"
#include "request_queue.h"

#include <chrono>

using namespace std;


// Constructor
WebServer::WebServer() : is_busy(false) {}

// Method to process a new request
void WebServer::processRequest(const Request& request) {
    current_request = request;
    is_busy = true;
}

// Method to check if the server is busy
bool WebServer::isBusy() const {
    return is_busy;
}

// Method to update the server's state
void WebServer::update(int cycle_time) {
    if (is_busy) {
        current_request.time -= cycle_time;
        if (current_request.time <= 0) {
            is_busy = false;
        }
    }
}