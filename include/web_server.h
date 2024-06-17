#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include "request.h"

/**
 * @brief Class representing a web server.
 */
class WebServer {
private:
    bool is_busy; /**< Indicates if the server is busy */
    Request current_request; /**< The current request being processed */

public:
    /**
     * @brief Constructor to initialize a WebServer.
     */
    WebServer();

    /**
     * @brief Method to process a new request.
     * @param request The request to be processed.
     */
    void processRequest(const Request& request);

    /**
     * @brief Method to check if the server is busy.
     * @return True if the server is busy, otherwise false.
     */
    bool isBusy() const;

    /**
     * @brief Method to update the server's state.
     * @param cycle_time The time cycle for updating the state.
     */
    void update(int cycle_time);
};

#endif // WEB_SERVER_H
