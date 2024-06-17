#include "request.h"
#include "web_server.h"
#include "request_queue.h"
#include "load_balancer.h"

#include <iostream>
#include <cstdlib> // for rand()

using namespace std;

/**
 * @brief Main function to run the load balancer simulation.
 * @return 0 if the program exits successfully.
 */
int main() {
    int num_servers, total_time;
    cout << "Enter number of servers: ";
    cin >> num_servers;
    cout << "Enter total simulation time: ";
    cin >> total_time;

    LoadBalancer lb(num_servers);

    cout << "Starting queue size: " << lb.getQueueSize() << endl;
    cout << "Task times range: 1 - 10 seconds" << endl;

    lb.run(total_time);

    cout << "Ending queue size: " << lb.getQueueSize() << endl;

    return 0;
}
