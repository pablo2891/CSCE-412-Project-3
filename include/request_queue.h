#ifndef REQUEST_QUEUE_H
#define REQUEST_QUEUE_H

#include <queue>
#include "request.h"

/**
 * @class RequestQueue
 * @brief Class to manage a queue of requests.
 */
class RequestQueue {
public:
    /**
     * @brief Method to add a request to the queue.
     * @param request The request to add.
     */
    void addRequest(const Request& request);

    /**
     * @brief Method to get the next request from the queue.
     * @return The next request.
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

private:
    std::queue<Request> q; ///< Queue to store the requests.
};

#endif // REQUEST_QUEUE_H
