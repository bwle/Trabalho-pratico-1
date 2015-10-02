#ifndef _CRYPTO_H
#define _CRYPTO_H

#include "array.hpp"

#include <string>
#include <openssl/rsa.h>

namespace crypto {

/*
   Calcula a hash SHA1 de dados.
 */
array::array* sha1(const array::array* data);

/*
   Gera bytes aleatórios de comprimento.
 */
array::array* nonce(size_t length);

/*   
  Leia chave pública RSA de um arquivo PEM.
 */
RSA* rsa_read_public_key_from_PEM(const std::string& path);

/*
   Leia chave privada RSA de um arquivo PEM.
 */
RSA* rsa_read_private_key_from_PEM(const std::string& path);

/*
   Libera chave RSA da memória.
*/
void rsa_destroy_key(RSA* key);

/*
   Criptografa dados usando chave pública RSA.
 */
array::array* rsa_encrypt(const array::array* data, RSA* rsa);

/*
   Decifra dados usando chave privada RSA.
 */
array::array* rsa_decrypt(const array::array* data, RSA* rsa);

/*
   Criptografa dados usando chave AES.
 */
array::array* aes_encrypt(const array::array* data, const array::array* iv, const array::array* key);

/*
   Decifra dados usando chave AES.
 */
array::array* aes_decrypt(array::array* data, array::array* iv, array::array* key);

}

#endif
