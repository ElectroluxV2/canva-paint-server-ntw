//
// Created by mate on 23.01.2021.
//

#ifndef WEB_SOCKET_HANDLER_H
#define WEB_SOCKET_HANDLER_H
#include "server/ws/ws_server.h"

using namespace CppServer;
using namespace std;

class WebSocketHandler : public WS::WSSession {
public:
    using WS::WSSession::WSSession;

protected:
    void onWSConnected(const HTTP::HTTPRequest& request) override;

    void onWSDisconnected() override;

    void onWSReceived(const void* buffer, size_t size) override;

    void onError(int error, const string& category, const string& message) override;
};

#endif