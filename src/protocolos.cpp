#include "protocolos.hpp"
#include "network.hpp"

Protocolos::Protocolos() {
    this->registeredId = 0;
    this->authenticationToken = 0;
    this->sessionToken = 0;
    this->obj = 0;
}
void Protocolos::registerProtocol() {
    network::requestRegistration(this->fd);
    this->registeredId = network::registerId(this->fd);
}
void Protocolos::authenticationProtocol() {
    this->authenticationToken = network::requestAuthentication(this->fd);
    sessionToken = network::requestChallenge(this->fd, this->authenticationToken, this->registeredId);
}
void Protocolos::requestProtocol() {
    this->obj = network::requestObject(fd, sessionToken, registeredId);
}
array::array *Protocolos::getObject() {
    return this->obj;
}
void Protocolos::connect() {
    cout << "Conectando......... " << endl;
    if ((this->fd = network::connect("45.55.185.4", 3000)) < 0) {
        cout << "Falhou" << endl;
    } else {
        cout << "Conectado " << this->fd << endl;
    }
}
void Protocolos::endConnection() {
    network::close_socket(this->fd);
}
