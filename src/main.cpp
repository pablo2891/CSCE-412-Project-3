// header files
#include "request.h"
#include "web_server.h"
#include "request_queue.h"


#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib> // for rand()

using namespace std;


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
