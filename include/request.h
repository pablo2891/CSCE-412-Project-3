#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <queue>

using namespace std;


struct Request {
    string IP_in;  /**< Incoming IP address */
    string IP_out; /**< Outgoing IP address */
    int time;           /**< Processing time in clock cycles */

    // Default Constructor
    Request() : IP_in(""), IP_out(""), time(0) {}
    // Constructor
    Request(const string& IP_in, const string& IP_out, int time);
};

#endif // REQUEST_H