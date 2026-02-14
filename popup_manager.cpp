/* ************************************************************
 * ARkalpyOS - Dynamic Pop-up System
 * [LANGUAGE: C++]
 * Author: [UserNight26]
 * ************************************************************
 */

#include "mosaic_kernel.h"

// Buffer para guardar o que estava na tela antes do Pop-up
uint16_t screen_backup[400]; 

void create_popup(const char* title, const char* message, uint8_t color_theme) {
    // 1. SALVAR ÁREA CENTRAL (Para poder fechar depois)
    // Salva uma área de 20x10 caracteres
    save_screen_area(30, 7, 50, 17, screen_backup);

    // 2. DESENHAR SOMBRA (Efeito Visual de Profundidade)
    draw_fill_rect(31, 8, 51, 18, 0x08); // Sombra cinza escura

    // 3. DESENHAR CORPO DO POP-UP
    draw_fill_rect(30, 7, 50, 17, 0x0F); // Fundo Branco
    draw_rect(30, 7, 50, 17, color_theme); // Borda colorida

    // 4. CABEÇALHO
    draw_fill_rect(30, 7, 50, 8, color_theme);
    draw_text(32, 7, title, 0x0F); // Título em branco

    // 5. MENSAGEM
    draw_text(32, 10, message, 0x00);

    // 6. BOTÃO DE CONFIRMAÇÃO
    draw_fill_rect(37, 14, 43, 15, 0x07); // Botão cinza
    draw_text(38, 14, "[ OK ]", 0x00);
}

void close_popup() {
    // RESTAURAR A TELA (Lógica de "Back-Buffer")
    restore_screen_area(30, 7, 50, 17, screen_backup);
}
