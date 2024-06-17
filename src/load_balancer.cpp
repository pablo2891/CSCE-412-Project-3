#include "request.h"       //!< Include request.h for Request class definition.
#include "web_server.h"    //!< Include web_server.h for WebServer class definition.
#include "request_queue.h" //!< Include request_queue.h for RequestQueue class definition.
#include "load_balancer.h" //!< Include load_balancer.h for LoadBalancer class definition.

#include <iostream> //!< Include iostream for input and output operations.
#include <vector>   //!< Include vector for std::vector container.

using namespace std; //!< Use the standard namespace.

/**
 * @brief Constructor for LoadBalancer class.
 * 
 * @param num_servers Number of servers to initialize in the load balancer.
 */
LoadBalancer::LoadBalancer(int num_servers) {
    servers.resize(num_servers); //!< Resize servers vector to num_servers.
}

/**
 * @brief Method to add a server to the load balancer.
 */
void LoadBalancer::addServer() {
    servers.push_back(WebServer()); //!< Add a new WebServer instance to servers vector.
}

/**
 * @brief Method to remove a server from the load balancer.
 * 
 * Removes the last server if the servers vector is not empty.
 */
void LoadBalancer::removeServer() {
    if (!servers.empty()) {
        servers.pop_back(); //!< Remove the last server from servers vector.
    }
}

/**
 * @brief Method to balance load across servers.
 * 
 * @param cycle_time Time duration for each cycle.
 * 
 * This method updates each server's status and processes requests from the queue
 * if a server is available and there are pending requests.
 */
void LoadBalancer::balanceLoad(int cycle_time) {
    for (auto &server : servers) {
        server.update(cycle_time); //!< Update the server with cycle_time.
        if (!server.isBusy() && !request_queue.isEmpty()) {
            server.processRequest(request_queue.getNextRequest()); //!< Process next request from request_queue.
        }
    }
}

/**
 * @brief Method to add a request to the request queue.
 * 
 * @param request Reference to the Request object to add.
 * 
 * Adds a request to the request_queue.
 */
void LoadBalancer::addRequest(const Request& request) {
    request_queue.addRequest(request); //!< Add request to request_queue.
}

/**
 * @brief Method to run the load balancer simulation.
 * 
 * @param total_time Total simulation time.
 * 
 * Simulates the load balancing process for the specified total_time.
 * It randomly adds requests and balances load in each cycle.
 */
void LoadBalancer::run(int total_time) {
    for (int time = 0; time < total_time; ++time) {
        // Simulate adding new requests
        if (rand() % 10 < 3) { // 30% chance to add a new request
            addRequest({"192.168.0.1", "192.168.0.2", rand() % 10 + 1}); //!< Add a new request with random parameters.
        }
        balanceLoad(1); // Simulate one cycle
    }
}
