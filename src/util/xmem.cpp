#include "xmem.hpp"

#include <avr/io.h>

#define XMEM_START (unsigned short*)0x1100
#define XMEM_END   (unsigned short*)0x30ff

void XMEM::init(void) {
    XMCRA = (1 << SRE);
}
    
bool XMEM::checkAddressLines(void) {
    for(unsigned short* ptr = XMEM_START; ptr < XMEM_END; ptr++)
        *ptr = (unsigned short)ptr;

    for(unsigned short* ptr = XMEM_START; ptr < XMEM_END; ptr++)
        if (*ptr != (unsigned short)ptr) return false;

    return true;
}
    
bool XMEM::checkBits(void) {
    unsigned short masks[] = {0x0000, 0xffff};

    for (unsigned short num : masks) {
    	for (unsigned short* ptr = XMEM_START; ptr < XMEM_END; ptr++)
    		*ptr = num;

    	for (unsigned short* ptr = XMEM_START; ptr < XMEM_END; ptr++)
    		if (*ptr != num) return false;
    }

    return true;
}
