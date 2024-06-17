/**
 * @file main.cpp
 * @brief Main file to run the Load Balancer simulation.
 */

#include "request.h"
#include "web_server.h"
#include "request_queue.h"
#include "load_balancer.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Main function to run the Load Balancer simulation.
 * @return int Exit status of the program.
 */
int main() {
    int num_servers, total_time;
    cout << "Enter number of servers: ";
    cin >> num_servers;
    cout << "Enter total simulation time: ";
    cin >> total_time;

    LoadBalancer lb(num_servers);
    
    // Log the starting queue size
    cout << "Starting queue size: " << lb.getQueueSize() << endl;
    
    // Define the range for task times
    int min_task_time = 1;  // minimum task time
    int max_task_time = 10; // maximum task time
    cout << "Task times range: " << min_task_time << " - " << max_task_time << " seconds" << endl;
    
    // Run the load balancer simulation
    lb.run(total_time);
    
    // Log the ending queue size
    cout << "Ending queue size: " << lb.getQueueSize() << endl;

    return 0;
}
