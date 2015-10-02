#ifndef _ARRAY_H
#define _ARRAY_H

#include <cstring>
#include <string>
#include <ostream>

#define WRAPPED_ARRAY 1
#define NORMAL_ARRAY 2

typedef unsigned char byte;

namespace array {

typedef struct _array {
	byte *data ;
	size_t length;
	byte _tag;
} array;

std::ostream& operator<<(std::ostream &os, const array& a);
/*
   Cria um novo array com a capacidade dada
*/
array* create(const size_t& capacity);

/*
   Cria um novo array com a capacidade dada e copia os bytes de dados para o novo array criado
 */
array* create(const size_t& capacity, byte* data);

/*
   Cria um novo array com a capacidade dada e aponta os dados para o ponteiro recebido
 */
array* wrap(const size_t& capacity, byte* data);


/*
	Destruir um array. Se esta é uma matriz envolvido não irá libertar os seus dados.
 */
void destroy(array* a);

/*
	Copia uma matriz. Se a matriz é envolvido, não irá copiar todos os bytes
		a partir de seus dados, mas em vez disso ele vai apenas apontar para ele.
 */
array* copy(const array* a);

}
#endif
