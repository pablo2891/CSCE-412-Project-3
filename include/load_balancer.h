#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H

#include "web_server.h"
#include "request_queue.h"
#include <vector>

/**
 * @brief Class representing a load balancer.
 */
class LoadBalancer {
private:
    std::vector<WebServer> servers; /**< Vector of web servers */
    RequestQueue request_queue; /**< Queue of requests */

public:
    /**
     * @brief Constructor to initialize a LoadBalancer.
     * @param num_servers The initial number of servers.
     */
    LoadBalancer(int num_servers);

    /**
     * @brief Method to add a server.
     */
    void addServer();

    /**
     * @brief Method to remove a server.
     */
    void removeServer();

    /**
     * @brief Method to balance the load across servers.
     * @param cycle_time The time cycle for balancing the load.
     */
    void balanceLoad(int cycle_time);

    /**
     * @brief Method to add a request to the queue.
     * @param request The request to be added.
     */
    void addRequest(const Request& request);

    /**
     * @brief Method to run the load balancer simulation.
     * @param total_time The total simulation time.
     */
    void run(int total_time);

    /**
     * @brief Method to get the size of the request queue.
     * @return The size of the request queue.
     */
    int getQueueSize() const;
};

#endif // LOAD_BALANCER_H
