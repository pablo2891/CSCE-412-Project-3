/*! \file */

/*! \brief Include request.h for Request class definition. */
#include "request.h"
/*! \brief Include web_server.h for WebServer class definition. */
#include "web_server.h"
/*! \brief Include request_queue.h for RequestQueue class definition. */
#include "request_queue.h"
/*! \brief Include load_balancer.h for LoadBalancer class definition. */
#include "load_balancer.h"

#include <queue>    //!< Include queue for std::queue container.

using namespace std; //!< Use the standard namespace.

/*! \class RequestQueue
    \brief Represents a queue for holding requests.

    This class manages a queue of Request objects and provides methods
    to add requests, retrieve the next request, and check if the queue
    is empty.
*/
class RequestQueue {
public:
    /*! \brief Add a request to the queue.
        \param request The Request object to add.
    */
    void addRequest(const Request& request);

    /*! \brief Get the next request from the queue.
        \return The next Request object in the queue.
    */
    Request getNextRequest();

    /*! \brief Check if the queue is empty.
        \return true if the queue is empty, false otherwise.
    */
    bool isEmpty() const;

private:
    queue<Request> q; //!< The underlying queue to hold Request objects.
};
