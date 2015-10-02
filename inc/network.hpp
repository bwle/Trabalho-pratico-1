#ifndef _NETWORK_HPP
#define _NETWORK_HPP

#include "array.hpp"

#include <string>

#define RECV_BUFFER_SIZE 1024 * 1024
namespace network {

/*
	Conecta-se a um host remoto e retorna um descritor de arquivo que representa
    socket. Um valor negativo significa que a conexão falhou.
 */
int connect(const std::string& host, const int& port);

/*
   Fecha o socket.
 */
void close(int fd);

/*
   Escreve os dados no array _content no socket dado
 */
void write(int fd, const array::array* content);

/*
   Lê os dados do socket especificado no _fd_ e retorna um array contendo
    estes dados.
 */
array::array* read(int fd);

/*
	Lê len bytes de dados do soquete especificado no _fd_ e retorna um
    		matriz contendo estes dados.
 */
array::array* read(int fd, size_t len);

}
#endif
