#include "load_balancer.h"
#include <iostream>
#include <cstdlib> // for rand()

using namespace std;

LoadBalancer::LoadBalancer(int num_servers) {
    servers.resize(num_servers);
}

void LoadBalancer::addServer() {
    servers.push_back(WebServer());
}

void LoadBalancer::removeServer() {
    if (!servers.empty()) {
        servers.pop_back();
    }
}

void LoadBalancer::balanceLoad(int cycle_time) {
    for (auto &server : servers) {
        server.update(cycle_time);
        if (!server.isBusy() && !request_queue.isEmpty()) {
            server.processRequest(request_queue.getNextRequest());
        }
    }
}

void LoadBalancer::addRequest(const Request& request) {
    request_queue.addRequest(request);
}

void LoadBalancer::run(int total_time) {
    for (int time = 0; time < total_time; ++time) {
        // Simulate adding new requests
        if (rand() % 10 < 5) { // 50% chance to add a new request
            Request new_request{"192.168.0.1", "192.168.0.2", rand() % 10 + 1};
            cout << "Adding request: " << new_request.IP_in << " -> " << new_request.IP_out << " with time " << new_request.time << endl;
            addRequest(new_request);
        }
        balanceLoad(1); // Simulate one cycle
    }
}

int LoadBalancer::getQueueSize() const {
    return request_queue.size();
}
