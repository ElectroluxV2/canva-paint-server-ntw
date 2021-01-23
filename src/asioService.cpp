//
// Created by mate on 23.01.2021.
//

#include "headers/asioService.h"

void AsioService::onError(int error, const string &category, const string &message) {
    cout << "Asio service caught an error with code " << error << " and category '" << category << "': " << message << endl;
}
