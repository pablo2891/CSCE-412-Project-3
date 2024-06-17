#ifndef REQUEST_QUEUE_H
#define REQUEST_QUEUE_H

#include <queue>
#include "request.h"

using namespace std;

class RequestQueue {
private:
    queue<Request> queue;

public:
    // Method to add a request to the queue
    void addRequest(const Request& request);

    // Method to get the next request from the queue
    Request getNextRequest();

    // Method to check if the queue is empty
    bool isEmpty() const;
};

#endif // REQUEST_QUEUE_H