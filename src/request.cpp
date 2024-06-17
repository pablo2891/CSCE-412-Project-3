#include "web_server.h"
#include "request.h"
#include "request_queue.h"
#include "load_balancer.h"

#include <string>
#include <time.h>
#include <chrono>

#include <cstdlib> // for rand()

using namespace std;

// Constructor definition
Request::Request(const string& IP_in, const string& IP_out, int time)
    : IP_in(IP_in), IP_out(IP_out), time(time) {}