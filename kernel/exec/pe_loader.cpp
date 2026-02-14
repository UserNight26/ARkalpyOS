/* **************************************************************************
 * ARkalpyOS - Portable Executable (PE) Loader
 * Permite que o sistema reconheça e inicie ficheiros .exe
 * Language: C++ (System Architecture)
 * **************************************************************************
 */

#include "memory_manager.h"
#include "vfs_core.h"

// Estruturas do Cabeçalho do Windows PE
struct PE_Header {
    uint32_t signature;
    uint16_t machine;
    uint16_t num_sections;
    uint32_t timedate_stamp;
    uint32_t pointer_to_symbol_table;
    uint32_t num_symbols;
    uint16_t optional_header_size;
    uint16_t characteristics;
};

struct Section_Header {
    char name[8];
    uint32_t virtual_size;
    uint32_t virtual_address;
    uint32_t size_of_raw_data;
    uint32_t pointer_to_raw_data;
    uint32_t characteristics;
};

class ExecutableManager {
public:
    bool launch_exe(const char* path) {
        FileHandle* file = vfs_open(path);
        if (!file) return false;

        // 1. Verificar a Assinatura MZ (DOS Header)
        char mz_sig[2];
        vfs_read(file, mz_sig, 2);
        if (mz_sig[0] != 'M' || mz_sig[1] != 'Z') return false;

        // 2. Saltar para o cabeçalho PE
        vfs_seek(file, 0x3C);
        uint32_t pe_offset;
        vfs_read(file, &pe_offset, 4);
        vfs_seek(file, pe_offset);

        PE_Header header;
        vfs_read(file, &header, sizeof(PE_Header));

        // 3. Alocar memória para o processo
        void* process_mem = kmalloc(0x100000); // Aloca 1MB para o app
        
        // 4. Carregar Secções (.text, .data, .rsrc)
        for (int i = 0; i < header.num_sections; i++) {
            Section_Header section;
            vfs_read(file, &section, sizeof(Section_Header));
            
            // Mapeia os dados do disco para a memória RAM
            vfs_seek(file, section.pointer_to_raw_data);
            vfs_read(file, (void*)((uint32_t)process_mem + section.virtual_address), section.size_of_raw_data);
        }

        // 5. Saltar para o Entry Point e executar
        typedef void (*EntryPoint)();
        EntryPoint start = (EntryPoint)((uint32_t)process_mem + 0x1000); // Endereço base comum
        
        create_popup("SYSTEM", "A iniciar aplicacao .EXE...", 0x0B);
        start(); 

        return true;
    }
};
