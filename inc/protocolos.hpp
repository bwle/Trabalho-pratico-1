#ifndef PROTOCOLOS_H
#define PROTOCOLOS_H
#include "array.hpp"

class Protocolos {

    private:
        int fd;
        array::array *registeredId;
        array::array *authenticationToken;
        array::array *sessionToken;
        array::array *obj;

    public:
        Protocolos();
        void connect();
        void registerProtocol();
        void authenticationProtocol();
        void requestProtocol();
        array::array *getObject();
        void endConnection();
};

#endif
