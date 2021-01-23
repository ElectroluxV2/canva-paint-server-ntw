//
// Created by mate on 23.01.2021.
//

#ifndef ASIO_SERVICE_H
#define ASIO_SERVICE_H

#include "server/asio/service.h"

using namespace CppServer;
using namespace std;

class AsioService : public Asio::Service {
public:
    using Asio::Service::Service;

protected:
    void onError(int error, const string& category, const string& message) override;
};

#endif