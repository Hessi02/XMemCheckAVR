#include "xmem.hpp"

#include <avr/io.h>

void XMEM::init(void) {
    XMCRA = (1 << SRE);
}
