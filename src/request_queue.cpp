#include "request.h"
#include "web_server.h"
#include "request_queue.h"
#include "load_balancer.h"

using namespace std;

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