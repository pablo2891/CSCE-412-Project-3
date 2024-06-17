#ifndef REQUEST_QUEUE_H
#define REQUEST_QUEUE_H

#include "request.h"
#include <queue>

/**
 * @brief Class representing a queue of requests.
 */
class RequestQueue {
private:
    std::queue<Request> q; /**< Queue to store requests */

public:
    /**
     * @brief Method to add a request to the queue.
     * @param request The request to be added.
     */
    void addRequest(const Request& request);

    /**
     * @brief Method to get the next request from the queue.
     * @return The next request from the queue.
     */
    Request getNextRequest();

    /**
     * @brief Method to check if the queue is empty.
     * @return True if the queue is empty, otherwise false.
     */
    bool isEmpty() const;

    /**
     * @brief Method to get the size of the queue.
     * @return The size of the queue.
     */
    int size() const;
};

#endif // REQUEST_QUEUE_H
