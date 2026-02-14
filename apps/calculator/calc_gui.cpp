/* ************************************************************
 * ARkalpyOS - Graphical Calculator App
 * Language: C++ (Mosaic Interface)
 * ************************************************************
 */

#include "mosaic_kernel.h"

int calc_x = 0, calc_y = 0; // Coordenadas dos botões (grade 4x4)
char display[16] = "0";

void draw_calculator() {
    // 1. Moldura da Calculadora
    draw_fill_rect(25, 5, 55, 20, 0x07); // Cinza
    draw_rect(25, 5, 55, 20, 0x00);      // Borda Preta

    // 2. Tela do Display
    draw_fill_rect(27, 6, 53, 8, 0x0F);  // Fundo Branco
    draw_text(50 - str_len(display), 7, display, 0x00); // Alinhado à direita

    // 3. Grade de Botões
    const char* buttons[4][4] = {
        {"7", "8", "9", "/"},
        {"4", "5", "6", "*"},
        {"1", "2", "3", "-"},
        {"C", "0", "=", "+"}
    };

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int bx = 28 + (j * 6);
            int by = 10 + (i * 2);
            uint8_t color = (calc_x == j && calc_y == i) ? 0x0B : 0x08; // Azul se focado
            
            draw_fill_rect(bx, by, bx+4, by+1, color);
            draw_text(bx+2, by, buttons[i][j], 0x0F);
        }
    }

    draw_text(27, 19, "Setas: Mover | Enter: OK", 0x08);
}

void handle_calc_input(uint8_t key) {
    if (key == KEY_UP && calc_y > 0) calc_y--;
    if (key == KEY_DOWN && calc_y < 3) calc_y++;
    if (key == KEY_LEFT && calc_x > 0) calc_x--;
    if (key == KEY_RIGHT && calc_x < 3) calc_x++;
    
    if (key == KEY_ENTER) {
        // Aqui chamaria a lógica do C# enviando o botão selecionado
        process_button(calc_x, calc_y);
    }
}
