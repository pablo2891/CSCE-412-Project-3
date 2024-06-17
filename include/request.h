#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @brief Class representing a request.
 */
class Request {
public:
    std::string IP_in; /**< IP address of the requester */
    std::string IP_out; /**< IP address of the responder */
    int time; /**< Processing time for the request */

    /**
     * @brief Default constructor to initialize a Request with empty strings and zero time.
     */
    Request() : IP_in(""), IP_out(""), time(0) {}

    /**
     * @brief Constructor to initialize a Request.
     * @param IP_in IP address of the requester.
     * @param IP_out IP address of the responder.
     * @param time Processing time for the request.
     */
    Request(const std::string& IP_in, const std::string& IP_out, int time);
};

#endif // REQUEST_H
