#include "load_balancer.h"
#include <iostream>
#include <cstdlib> // for rand()

using namespace std;

/**
 * @brief Constructor to initialize a LoadBalancer.
 * @param num_servers The initial number of servers.
 */
LoadBalancer::LoadBalancer(int num_servers) {
    servers.resize(num_servers);
}

/**
 * @brief Method to add a server.
 */
void LoadBalancer::addServer() {
    servers.push_back(WebServer());
}

/**
 * @brief Method to remove a server.
 */
void LoadBalancer::removeServer() {
    if (!servers.empty()) {
        servers.pop_back();
    }
}

/**
 * @brief Method to balance the load across servers.
 * @param cycle_time The time cycle for balancing the load.
 */
void LoadBalancer::balanceLoad(int cycle_time) {
    for (auto &server : servers) {
        server.update(cycle_time);
        if (!server.isBusy() && !request_queue.isEmpty()) {
            server.processRequest(request_queue.getNextRequest());
        }
    }
}

/**
 * @brief Method to add a request to the queue.
 * @param request The request to be added.
 */
void LoadBalancer::addRequest(const Request& request) {
    request_queue.addRequest(request);
}

/**
 * @brief Method to run the load balancer simulation.
 * @param total_time The total simulation time.
 */
void LoadBalancer::run(int total_time) {
    // Initially populate the queue based on the number of servers
    int initial_requests = servers.size() * 100;
    for (int i = 0; i < initial_requests; ++i) {
        Request new_request{"192.168.0.1", "192.168.0.2", rand() % 10 + 1};
        addRequest(new_request);
    }

    for (int time = 0; time < total_time; ++time) {
        // Simulate adding new requests
        if (rand() % 10 < 7) { // 70% chance to add a new request
            Request new_request{"192.168.0.1", "192.168.0.2", rand() % 10 + 1};
            cout << "Adding request: " << new_request.IP_in << " -> " << new_request.IP_out << " with time " << new_request.time << endl;
            addRequest(new_request);
        }
        balanceLoad(1); // Simulate one cycle
    }
}

/**
 * @brief Method to get the size of the request queue.
 * @return The size of the request queue.
 */
int LoadBalancer::getQueueSize() const {
    return request_queue.size();
}
