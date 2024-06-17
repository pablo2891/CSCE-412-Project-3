/*! \file */

/*! \brief Include request.h for Request class definition. */
#include "request.h"
/*! \brief Include web_server.h for WebServer class definition. */
#include "web_server.h"
/*! \brief Include request_queue.h for RequestQueue class definition. */
#include "request_queue.h"
/*! \brief Include load_balancer.h for LoadBalancer class definition. */
#include "load_balancer.h"

#include <iostream> //!< Include iostream for input and output operations.
#include <vector>   //!< Include vector for std::vector container.
#include <queue>    //!< Include queue for std::queue container.
#include <cstdlib>  //!< Include cstdlib for rand() function.

using namespace std; //!< Use the standard namespace.

/*! \brief Main function where the program starts execution. */
int main() {
    int num_servers, total_time;
    cout << "Enter number of servers: "; //!< Prompt user to enter number of servers.
    cin >> num_servers; //!< Read number of servers from user input.
    cout << "Enter total simulation time: "; //!< Prompt user to enter total simulation time.
    cin >> total_time; //!< Read total simulation time from user input.

    LoadBalancer lb(num_servers); //!< Create an instance of LoadBalancer with num_servers.
    lb.run(total_time); //!< Run the load balancer simulation for total_time.

    return 0; //!< Indicate successful completion of program.
}
