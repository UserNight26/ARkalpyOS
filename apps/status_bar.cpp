/* * ARkalpyOS - System Tray & Quick Settings
 */

void draw_status_icons() {
    // 1. FUNDO DO BOTÃO (Canto superior direito)
    draw_fill_rect(65, 0, 80, 1, 0x08); // Barra cinza escuro

    // 2. ÍCONE DE BATERIA
    BatteryStatus bat = get_hardware_battery();
    if (bat.percentage > 20) 
        draw_text(66, 0, "[||||]", 0x0A); // Verde se cheia
    else 
        draw_text(66, 0, "[!   ]", 0x0C); // Vermelho se baixa

    // 3. ÍCONES DE STATUS (Símbolos ASCII)
    draw_text(72, 0, "WIFI", 0x0B);  // Wi-Fi Ativo (Ciano)
    draw_text(77, 0, "BT", 0x09);    // Bluetooth (Azul)
    draw_text(79, 0, "V", 0x0F);     // Volume
}

void open_quick_settings() {
    // Quando o usuário clica ou usa o atalho no canto
    draw_box(55, 2, 79, 10, 0x07, 0x00, '#');
    draw_text(57, 3, "--- SETTINGS ---", 0x0E);
    draw_text(57, 5, "WIFI: CONNECTED", 0x0A);
    draw_text(57, 6, "BLUE: SEARCHING", 0x08);
    draw_text(57, 7, "VOL : [#######-]", 0x0F);
    draw_text(57, 9, "BAT : 85% (AC)", 0x0B);
}
