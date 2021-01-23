//
// Created by mate on 23.01.2021.
//

#include "headers/server.h"

shared_ptr<Asio::TCPSession> Server::CreateSession(const shared_ptr<Asio::TCPServer> &server) {
    return make_shared<WebSocketHandler>(dynamic_pointer_cast<WS::WSServer>(server));
}

void Server::onError(int error, const string &category, const string &message) {
    cout << "Chat WebSocket server caught an error with code " << error << " and category '" << category << "': " << message << endl;
}
