// header files
#include "request.h"
#include "web_server.h"
#include "request_queue.h"
#include "load_balancer.h"


#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib> // for rand()

using namespace std;


int main() {
    int num_servers, total_time;
    cout << "Enter number of servers: ";
    cin >> num_servers;
    cout << "Enter total simulation time: ";
    cin >> total_time;

    LoadBalancer lb(num_servers);
    lb.run(total_time);

    return 0;
}
