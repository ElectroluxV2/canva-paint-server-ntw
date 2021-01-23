//
// Created by mate on 23.01.2021.
//

#ifndef SERVER_H
#define SERVER_H

#include "server/ws/ws_server.h"
#include "webSocketHandler.h"

using namespace CppServer;
using namespace std;

class Server : public WS::WSServer {
public:
    using WS::WSServer::WSServer;

protected:
    shared_ptr<Asio::TCPSession> CreateSession(const shared_ptr<Asio::TCPServer>& server) override;

protected:
    void onError(int error, const string& category, const string& message) override;
};

#endif