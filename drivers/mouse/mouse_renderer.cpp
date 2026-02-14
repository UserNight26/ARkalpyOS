/* * ARkalpyOS - Mouse Scaler
 * Permite redimensionar o cursor dinamicamente
 */

void draw_mouse_scaled(int x, int y, int scale) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            char pixel = classic_cursor[i][j];
            
            if (pixel != ' ') { // Se não for transparente
                uint8_t color = (pixel == 'X') ? 0x00 : 0x0F;
                
                // Desenha um bloco maior baseado na escala
                draw_fill_rect(x + (j * scale), 
                               y + (i * scale), 
                               x + (j * scale) + scale, 
                               y + (i * scale) + scale, 
                               color);
            }
        }
    }
}
