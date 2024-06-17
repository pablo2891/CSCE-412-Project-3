#include "request.h"
#include "web_server.h"
#include "request_queue.h"
#include "load_balancer.h"


#include <iostream>
#include <vector>

using namespace std;

// Constructor
LoadBalancer::LoadBalancer(int num_servers) {
    servers.resize(num_servers);
}

// Method to add a server
void LoadBalancer::addServer() {
    servers.push_back(WebServer());
}

// Method to remove a server
void LoadBalancer::removeServer() {
    if (!servers.empty()) {
        servers.pop_back();
    }
}

// Method to balance load across servers
void LoadBalancer::balanceLoad(int cycle_time) {
    for (auto &server : servers) {
        server.update(cycle_time);
        if (!server.isBusy() && !request_queue.isEmpty()) {
            server.processRequest(request_queue.getNextRequest());
        }
    }
}

// Method to add a request to the queue
void LoadBalancer::addRequest(const Request& request) {
    request_queue.addRequest(request);
}

// Method to run the load balancer simulation
void LoadBalancer::run(int total_time) {
    for (int time = 0; time < total_time; ++time) {
        // Simulate adding new requests
        if (rand() % 10 < 3) { // 30% chance to add a new request
            addRequest({"192.168.0.1", "192.168.0.2", rand() % 10 + 1});
        }
        balanceLoad(1); // Simulate one cycle
    }
}