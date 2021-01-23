//
// Created by mate on 23.01.2021.
//

#include "headers/webSocketHandler.h"

void WebSocketHandler::onWSConnected(const HTTP::HTTPRequest &request) {
    cout << "Chat WebSocket session with Id " << id() << " connected!" << endl;

    // Send invite message
    string message("Hello from WebSocket chat! Please send a message or '!' to disconnect the client!");
    SendTextAsync(message);
}

void WebSocketHandler::onWSDisconnected() {
    cout << "Chat WebSocket session with Id " << id() << " disconnected!" << endl;
}

void WebSocketHandler::onWSReceived(const void *buffer, size_t size) {
    string message((const char*)buffer, size);
    cout << "Incoming: " << message << endl;

    // Multicast message to all connected sessions
    dynamic_pointer_cast<WS::WSServer>(server())->MulticastText(message);

    // If the buffer starts with '!' the disconnect the current session
    if (message == "!")
        Close(1000);
}

void WebSocketHandler::onError(int error, const string &category, const string &message) {
    cout << "Chat WebSocket session caught an error with code " << error << " and category '" << category << "': " << message << endl;
}
