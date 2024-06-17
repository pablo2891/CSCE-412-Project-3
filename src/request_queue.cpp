/**
 * @file request_queue.cpp
 * @brief Implementation file for the RequestQueue class.
 */

#include "request_queue.h"
#include "request.h"
#include <queue>

using namespace std;

/**
 * @brief Method to add a request to the queue.
 * @param request The request to be added.
 */
void RequestQueue::addRequest(const Request& request) {
    q.push(request);
}

/**
 * @brief Method to get the next request from the queue.
 * @return The next request from the queue.
 */
Request RequestQueue::getNextRequest() {
    if (!q.empty()) {
        Request req = q.front();
        q.pop();
        return req;
    }
    return {"", "", 0}; // Return an empty request if the queue is empty
}

/**
 * @brief Method to check if the queue is empty.
 * @return True if the queue is empty, otherwise false.
 */
bool RequestQueue::isEmpty() const {
    return q.empty();
}

/**
 * @brief Method to get the size of the queue.
 * @return The size of the queue.
 */
int RequestQueue::size() const {
    return q.size();
}

