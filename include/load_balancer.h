#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H

#include <vector>
#include "web_server.h"
#include "request_queue.h"

/**
 * @class LoadBalancer
 * @brief Class to manage and distribute incoming requests to a pool of web servers.
 */
class LoadBalancer {
public:
    /**
     * @brief Constructor to initialize the load balancer with a given number of servers.
     * @param num_servers Number of servers to initialize.
     */
    LoadBalancer(int num_servers);

    /**
     * @brief Method to add a new server to the pool.
     */
    void addServer();

    /**
     * @brief Method to remove a server from the pool.
     */
    void removeServer();

    /**
     * @brief Method to balance the load across all servers.
     * @param cycle_time The time for each cycle in the simulation.
     */
    void balanceLoad(int cycle_time);

    /**
     * @brief Method to add a request to the queue.
     * @param request The request to add.
     */
    void addRequest(const Request& request);

    /**
     * @brief Method to run the load balancer simulation.
     * @param total_time The total simulation time.
     */
    void run(int total_time);

    /**
     * @brief Get the size of the request queue.
     * @return The size of the request queue.
     */
    int getQueueSize() const;

private:
    std::vector<WebServer> servers; ///< Vector to store the pool of web servers.
    RequestQueue request_queue; ///< Queue to store the incoming requests.
};

#endif // LOAD_BALANCER_H
