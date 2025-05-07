#include "com/usart.hpp"
#include "util/xmem.hpp"

int main(void) {
    USART::write("Checking external memory...\n");

    USART::write((XMEM::checkAddressLines() ? 
                    "Address lines are okay!\n" : 
                    "Address lines aren't working properly.\n"));   

    USART::write((XMEM::checkBits() ? 
                    "SRAM's bits are okay!\n" :
                    "Bits aren't fully accessible.\n"));
    
    return 0;
}
