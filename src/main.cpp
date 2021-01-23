#include <iostream>
#include "headers/asioService.h"
#include "headers/server.h"

using namespace std;

int main(int argc, char** argv) {
    // WebSocket server port
    int port = 3000;
    if (argc > 1)
        port = stoi(argv[1]);
    // WebSocket server content path
    string www = "www";
    if (argc > 2)
        www = argv[2];

    cout << "WebSocket server port: " << port << endl;
    cout << "WebSocket server static content path: " << www << endl;
    cout << "WebSocket server website: " << "http://localhost:" << port << "/tester.html" << endl;
    cout << endl;

    // Create a new Asio service
    auto service = make_shared<AsioService>();

    // Start the Asio service
    cout << "Asio service starting...";
    service->Start();
    cout << "Done!" << endl;

    // Create a new WebSocket chat server
    auto server = make_shared<Server>(service, port);
    server->AddStaticContent(www);

    // Start the server
    cout << "WebSocketHandler starting...";
    server->Start();
    cout << "Done!" << endl;

    cout << "Press Enter to stop the server or '!' to restart the server..." << endl;

    // Perform text input
    string line;
    while (getline(cin, line)) {
        if (line.empty())
            break;

        // Restart the server
        if (line == "!") {
            cout << "WebSocketHandler restarting...";
            server->Restart();
            cout << "Done!" << endl;
            continue;
        }

        // Multicast server message to all sessions
        line = "(server) " + line;
        server->MulticastText(line);
    }

    // Stop the server
    cout << "WebSocketHandler stopping...";
    server->Stop();
    cout << "Done!" << endl;

    // Stop the Asio service
    cout << "Asio service stopping...";
    service->Stop();
    cout << "Done!" << endl;

    return 0;
}
