/**
 * @file request_queue.cpp
 * @brief Implementation file for the RequestQueue class.
 */

#include "request_queue.h"
#include "request.h"
#include <queue>

using namespace std;

// Constructor
RequestQueue::RequestQueue() {}

// Method to add a request to the queue
void RequestQueue::addRequest(const Request& request) {
    q.push(request);
}

// Method to get the next request from the queue
Request RequestQueue::getNextRequest() {
    if (!q.empty()) {
        Request req = q.front();
        q.pop();
        return req;
    }
    return {"", "", 0}; // Return an empty request if the queue is empty
}

// Method to check if the queue is empty
bool RequestQueue::isEmpty() const {
    return q.empty();
}

// Method to get the current size of the queue
int RequestQueue::getQueueSize() const {
    return q.size();
}
