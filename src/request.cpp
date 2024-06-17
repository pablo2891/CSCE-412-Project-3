/**
 * @file request.cpp
 * @brief Implementation file for the Request class.
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
 * @brief Constructor to initialize a Request.
 * @param IP_in IP address of the requester.
 * @param IP_out IP address of the responder.
 * @param time Processing time for the request.
 */
Request::Request(const std::string& IP_in, const std::string& IP_out, int time)
    : IP_in(IP_in), IP_out(IP_out), time(time) {}

