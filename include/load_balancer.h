/**
 * @file load_balancer.h
 * @brief Header file for the LoadBalancer class.
 */

#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H

#include "web_server.h"
#include "request_queue.h"
#include <vector>

/**
 * @brief Class to represent a Load Balancer.
 */
class LoadBalancer {
public:
    /**
     * @brief Constructor for LoadBalancer.
     * @param num_servers Number of servers in the load balancer.
     */
    LoadBalancer(int num_servers);

    /**
     * @brief Method to add a server to the load balancer.
     */
    void addServer();

    /**
     * @brief Method to remove a server from the load balancer.
     */
    void removeServer();

    /**
     * @brief Method to balance the load across servers.
     * @param cycle_time Time for each balance cycle.
     */
    void balanceLoad(int cycle_time);

    /**
     * @brief Method to add a request to the request queue.
     * @param request The request to be added.
     */
    void addRequest(const Request& request);

    /**
     * @brief Method to run the load balancer simulation.
     * @param total_time Total time for the simulation.
     */
    void run(int total_time);

    /**
     * @brief Method to get the current size of the request queue.
     * @return int The size of the request queue.
     */
    int getQueueSize() const;

private:
    std::vector<WebServer> servers; ///< Vector of servers.
    RequestQueue request_queue; ///< Request queue.
};

#endif // LOAD_BALANCER_H
