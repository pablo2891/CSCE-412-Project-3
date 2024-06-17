/**
 * @file web_server.h
 * @file request.h
 * @file request_queue.h
 * @file load_balancer.h
 */

#include "web_server.h"
#include "request.h"
#include "request_queue.h"
#include "load_balancer.h"

#include <string>   // for string class
#include <time.h>   // for time related functions
#include <chrono>   // for high_resolution_clock

#include <cstdlib>  // for rand()

using namespace std;

/**
 * @brief Constructor definition for Request class.
 *
 * @param IP_in     Incoming IP address as string.
 * @param IP_out    Outgoing IP address as string.
 * @param time      Time of request in seconds.
 */
Request::Request(const string& IP_in, const string& IP_out, int time)
    : IP_in(IP_in), IP_out(IP_out), time(time) {}
