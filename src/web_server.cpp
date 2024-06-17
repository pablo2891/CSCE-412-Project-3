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
 * @brief Constructor for WebServer class.
 * Initializes the server as not busy.
 */
WebServer::WebServer() : is_busy(false) {}

/**
 * @brief Process a new request.
 *
 * @param request The request to be processed.
 */
void WebServer::processRequest(const Request& request) {
    current_request = request;
    is_busy = true;
}

/**
 * @brief Check if the server is currently busy.
 *
 * @return true if the server is busy, false otherwise.
 */
bool WebServer::isBusy() const {
    return is_busy;
}

/**
 * @brief Update the server's state based on elapsed time.
 *
 * If the server is busy, reduce the remaining time of the current request by cycle_time.
 * If the remaining time of the current request becomes zero or less, mark the server as not busy.
 *
 * @param cycle_time The elapsed time to update the server's state.
 */
void WebServer::update(int cycle_time) {
    if (is_busy) {
        current_request.time -= cycle_time;
        if (current_request.time <= 0) {
            is_busy = false;
        }
    }
}
