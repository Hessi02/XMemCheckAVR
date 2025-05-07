#ifndef __XMEM_HPP__
#define __XMEM_HPP__

namespace XMEM
{
    __attribute__((naked, section(".init3")))
    void init(void);

    bool checkAddressLines(void);
    
    bool checkBits(void);
}

#endif //__XMEM_HPP__
