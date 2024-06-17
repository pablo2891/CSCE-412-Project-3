/**
 * @file request_queue.h
 * @brief Header file for the RequestQueue class.
 */

#ifndef REQUEST_QUEUE_H
#define REQUEST_QUEUE_H

#include "request.h"
#include <queue>

/**
 * @brief Class to represent a queue of requests.
 */
class RequestQueue {
public:
    /**
     * @brief Constructor for RequestQueue.
     */
    RequestQueue();

    /**
     * @brief Method to add a request to the queue.
     * @param request The request to be added.
     */
    void addRequest(const Request& request);

    /**
     * @brief Method to get the next request from the queue.
     * @return Request The next request in the queue.
     */
    Request getNextRequest();

    /**
     * @brief Method to check if the queue is empty.
     * @return bool True if the queue is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Method to get the current size of the queue.
     * @return int The size of the queue.
     */
    int getQueueSize() const;

private:
    std::queue<Request> q; ///< Queue of requests.
};

#endif // REQUEST_QUEUE_H
