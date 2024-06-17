/**
 * @file web_server.h
 * @file request.h
 * @file load_balancer.h
 * @file request_queue.h
 */

#include "web_server.h"
#include "request.h"
#include "load_balancer.h"
#include "request_queue.h"

#include <chrono>   // for high_resolution_clock

using namespace std;

/**
 * @brief Constructor to initialize a WebServer.
 */
WebServer::WebServer() : is_busy(false) {}

/**
 * @brief Method to process a new request.
 * @param request The request to be processed.
 */
void WebServer::processRequest(const Request& request) {
    current_request = request;
    is_busy = true;
}

/**
 * @brief Method to check if the server is busy.
 * @return True if the server is busy, otherwise false.
 */
bool WebServer::isBusy() const {
    return is_busy;
}

/**
 * @brief Method to update the server's state.
 * @param cycle_time The time cycle for updating the state.
 */
void WebServer::update(int cycle_time) {
    if (is_busy) {
        current_request.time -= cycle_time;
        if (current_request.time <= 0) {
            is_busy = false;
        }
    }
}
