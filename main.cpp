#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib> // for rand()

/**
 * @struct Request
 * @brief Represents a web request.
 *
 * Contains the IP addresses for the request and the time required to process it.
 */
struct Request {
    std::string ip_in;  /**< Incoming IP address */
    std::string ip_out; /**< Outgoing IP address */
    int time;           /**< Processing time in clock cycles */
};


/* The WebServer class manages incoming requests, processes them, and updates its status based on the
cycle time. */
class WebServer {
private:
    bool is_busy;
    Request current_request;

public:
    WebServer() : is_busy(false) {}

    void processRequest(Request request) {
        current_request = request;
        is_busy = true;
    }

    bool isBusy() {
        return is_busy;
    }

    void update(int cycle_time) {
        if (is_busy) {
            current_request.time -= cycle_time;
            if (current_request.time <= 0) {
                is_busy = false;
            }
        }
    }
};

// Class for RequestQueue
class RequestQueue {
private:
    std::queue<Request> queue;

public:
    void addRequest(Request request) {
        queue.push(request);
    }

    Request getNextRequest() {
        if (!queue.empty()) {
            Request req = queue.front();
            queue.pop();
            return req;
        }
        return {"", "", 0}; // Return an empty request if queue is empty
    }

    bool isEmpty() {
        return queue.empty();
    }
};

// Class for LoadBalancer
class LoadBalancer {
private:
    std::vector<WebServer> servers;
    RequestQueue request_queue;

public:
    LoadBalancer(int num_servers) {
        servers.resize(num_servers);
    }

    void addServer() {
        servers.push_back(WebServer());
    }

    void removeServer() {
        if (!servers.empty()) {
            servers.pop_back();
        }
    }

    void balanceLoad(int cycle_time) {
        for (auto &server : servers) {
            server.update(cycle_time);
            if (!server.isBusy() && !request_queue.isEmpty()) {
                server.processRequest(request_queue.getNextRequest());
            }
        }
    }

    void addRequest(Request request) {
        request_queue.addRequest(request);
    }

    void run(int total_time) {
        for (int time = 0; time < total_time; ++time) {
            // Simulate adding new requests
            if (rand() % 10 < 3) { // 30% chance to add a new request
                addRequest({"192.168.0.1", "192.168.0.2", rand() % 10 + 1});
            }
            balanceLoad(1); // Simulate one cycle
        }
    }
};

int main() {
    int num_servers, total_time;
    std::cout << "Enter number of servers: ";
    std::cin >> num_servers;
    std::cout << "Enter total simulation time: ";
    std::cin >> total_time;

    LoadBalancer lb(num_servers);
    lb.run(total_time);

    return 0;
}
