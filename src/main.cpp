#include <cstring>
#include <iostream>
#include "array.hpp"
#include "crypto.hpp"
#include "network.hpp"
#include "packet.hpp"
#include "protocolos.hpp"

using namespace std;

int main() {

	Protocolos *nh = new Protocolos();
	nh->connect();    
	nh->registerProtocol();
        nh->authenticationProtocol();
        nh->requestProtocol();
        FILE *fp = fopen("object.png", "wb");
        array::write_array(fp, nh->getObject());
        fclose(fp);
	return 0;
}
