#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H

#include "request.h"
#include "web_server.h"
#include "request_queue.h"

#include <vector>
using namespace std;

// Class for LoadBalancer
class LoadBalancer {
private:
    vector<WebServer> servers;
    RequestQueue request_queue;

public:
    // Constructor
    LoadBalancer(int num_servers);

    // Method to add a server
    void addServer();

    // Method to remove a server
    void removeServer();

    // Method to balance load across servers
    void balanceLoad(int cycle_time);

    // Method to add a request to the queue
    void addRequest(const Request& request);

    // Method to run the load balancer simulation
    void run(int total_time);
};

#endif // LOAD_BALANCER_H
