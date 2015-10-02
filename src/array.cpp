#include "array.hpp"
#include <sstream>
#include <ios>
#include <iomanip>
#include <iostream>

using namespace std;

namespace array {

        std::ostream& operator<<(std::ostream &os, const array &a) {
        std::ios::fmtflags f(os.flags()); // save formating flags
        os << "array #" << a.length << " [";
        os << std::hex << std::uppercase; // change flags
        for(unsigned int i=0; i  <a.length - 1; i++ ) {
            os.width(2);
            os.fill('0');
            os << ((int)(a.data)[i]) << " ";
        }
        os.width(2);
        os.fill('0');
        os << ((int)(a.data)[a.length - 1]) << "]";
        os.flags(f); // restore flags
        return os;
    }
        array* create(const size_t &capacity) {
        array *m = new array();
        m->data = new byte[capacity];
        m->length = capacity;
        m->_tag = 2;
        memset(m->data, 0, m->length);
        return m;
    }
        array* create(const size_t &capacity, byte *data) {
        array* m = create(capacity);
        memcpy(m->data, data, capacity);
        m->_tag = 2;
        return m;
    }
        array* wrap(const size_t &capacity, byte *data) {
        array *m = new array();
        m->length = capacity;
        m->data = data;
        m->_tag = 1;
        return m;
    }
    void destroy(array *a) {
        if(a->_tag == 2) {
            delete[] a->data;
        }
        delete a;
    }
        array* copy(const array *a) {
        array* b = create(a->length);
        b->_tag = a->_tag;

        if(b->_tag == 2) {
            memcpy(b->data, a->data, a->length);
        }
        else {
            b->data = a->data;
        }
        return b;
    }
    void print_array(array *array) {
        for (size_t i = 0; i < array->length; i++) {
            /* code */
            printf("%X ", array->data[i]);
        }
        printf("\n");
    }
    void write_array(FILE *fp, array *array) {
        fwrite(array->data, 1, array->length, fp);
    }

}
