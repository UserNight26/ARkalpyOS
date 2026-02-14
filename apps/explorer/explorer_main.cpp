/* **************************************************************************
 * ARkalpyOS - Advanced Virtual File System (VFS) & Explorer Interface
 * Language: C++ (Core Logic & GUI)
 * **************************************************************************
 */

#include "mosaic_kernel.h"
#include "drivers/disk_ata.h"

struct FileEntry {
    char name[32];
    char ext[5];
    uint32_t size;
    uint8_t type; // 0: Folder, 1: Doc, 2: Video, 3: Sound
    bool is_selected;
};

class ARkalpyExplorer {
private:
    FileEntry directory_cache[64];
    int total_files;
    int scroll_pos;

public:
    void init_explorer() {
        total_files = 0;
        scroll_pos = 0;
        load_mock_files(); // Em um SO real, aqui leríamos a tabela FAT32
    }

    void load_mock_files() {
        // Simulando a estrutura que você pediu
        add_entry("Documentos", "DIR", 0, 0);
        add_entry("Videos", "DIR", 0, 0);
        add_entry("Sons", "DIR", 0, 0);
        add_entry("projeto_x", "DOC", 45, 1);
        add_entry("kernel_v1", "ISO", 2048, 1);
        add_entry("intro_video", "MP4", 5120, 2);
        add_entry("startup_snd", "WAV", 128, 3);
    }

    void add_entry(const char* n, const char* e, uint32_t s, uint8_t t) {
        copy_string(directory_cache[total_files].name, n);
        copy_string(directory_cache[total_files].ext, e);
        directory_cache[total_files].size = s;
        directory_cache[total_files].type = t;
        directory_cache[total_files].is_selected = false;
        total_files++;
    }

    void render_ui() {
        draw_fill_rect(2, 2, 78, 22, 0x0F); // Fundo Branco
        draw_rect(2, 2, 78, 22, 0x01);      // Borda Azul Crome
        
        // Cabeçalho do Explorador
        draw_fill_rect(2, 2, 78, 4, 0x01);
        draw_text(4, 3, "ARKALPY FILE EXPLORER v1.0 | Disco: HD0 (Active)", 0x0F);

        // Renderização dos Arquivos
        for (int i = 0; i < total_files; i++) {
            int y = 6 + (i * 2);
            uint8_t color = (i == scroll_pos) ? 0x0B : 0x00; // Destaque para seleção

            // Desenha Ícones baseado no tipo
            if (directory_cache[i].type == 0) draw_text(4, y, "[DIR]", 0x0E); // Amarelo
            else if (directory_cache[i].type == 2) draw_text(4, y, "[VID]", 0x0C); // Vermelho
            else if (directory_cache[i].type == 3) draw_text(4, y, "[SND]", 0x0A); // Verde
            else draw_text(4, y, "[FIL]", 0x08); // Cinza

            draw_text(12, y, directory_cache[i].name, color);
            draw_text(45, y, directory_cache[i].ext, 0x08);
            
            if (directory_cache[i].size > 0) {
                char size_str[16];
                int_to_string(directory_cache[i].size, size_str);
                draw_text(60, y, size_str, 0x07);
                draw_text(68, y, "KB", 0x07);
            }
        }

        // Rodapé de Comandos
        draw_fill_rect(2, 21, 78, 22, 0x07);
        draw_text(4, 21, "[ENTER] Abrir | [DEL] Apagar | [D] Download Sim | [ESC] Sair", 0x00);
    }

    void handle_input(uint8_t key) {
        if (key == 0x48 && scroll_pos > 0) scroll_pos--; // Seta Cima
        if (key == 0x50 && scroll_pos < total_files - 1) scroll_pos++; // Seta Baixo
        if (key == 'D' || key == 'd') trigger_download_protocol();
    }
};
