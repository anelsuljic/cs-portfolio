#include <string>
#include "eda-error.hh"

#include "eda-mem.hh"
using std::string;




// Encapsula las constantes relativas a la gestión de errores.
namespace eda_mem {
    const string nom_mod = "eda_mem";
    const int falta_mem_din = 100;
    const string msg_falta_mem_din = "Falta memoria dinamica";
}
using namespace eda_mem;


void *operator new(size_t size) noexcept(false)
{     
    void *ptr = malloc(size);
    if (ptr == nullptr) {
        throw error(nom_mod, falta_mem_din, msg_falta_mem_din);
    }
    
    return ptr;
}


void *operator new[](size_t size) noexcept(false)
{
    void *ptr = malloc(size);
    if (ptr == nullptr) {
        throw error(nom_mod, falta_mem_din, msg_falta_mem_din);
    }
    
    return ptr;
}


void operator delete(void *ptr) noexcept
{
    free(ptr);
}


void operator delete[](void *ptr) noexcept
{
    free(ptr);
}