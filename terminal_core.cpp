/* * ARkalpyOS - Terminal de Comandos Avançado

Lógica de processamento de comandos: help, Pop---, e --files--
*/

// Função para desenhar o Pop-up na tela
void draw_popup(const char* mensagem) {
// Desenha uma caixa centralizada no meio da tela
draw_box(20, 8, 60, 16, 0x04, 0x0F, '*'); // Vermelho com bordas de estrela
draw_text(22, 10, "[ MENSAGEM DO SISTEMA ]", 0x0E);
draw_text(22, 12, mensagem, 0x0F);
draw_text(22, 14, "Pressione ESC para fechar", 0x07);
}

// Função para o Explorador de Arquivos (--files--)
void show_file_explorer() {
draw_box(10, 5, 70, 20, 0x01, 0x0F, '='); // Azul clássico
draw_text(12, 6, "ARkalpy File Explorer v1.0", 0x0B);
draw_text(12, 8, "-> boot/", 0x0F);
draw_text(12, 9, "-> kernel/", 0x0F);
draw_text(12, 10, "-> drivers/", 0x0F);
draw_text(12, 11, "-> apps/", 0x0F);
draw_text(12, 13, "[TOTAL: 7 DIRETORIOS ENCONTRADOS]", 0x0A);
}

// PROCESSADOR DE COMANDOS DO TERMINAL
void execute_terminal_command(char* input) {

// 1. Comando: help
if (compare_strings(input, "help")) {
    print_to_terminal("COMANDOS DISPONIVEIS:");
    print_to_terminal("help            - Mostra esta lista");
    print_to_terminal("Pop---[texto]   - Abre um alerta com seu texto");
    print_to_terminal("--files--       - Abre o explorador de arquivos");
    print_to_terminal("clear           - Limpa o terminal");
}

// 2. Comando: Pop--- (Lógica de detecção de prefixo)
if (starts_with(input, "Pop---")) {
    char* mensagem = input + 6; // Pega o texto logo após o Pop---
    draw_popup(mensagem);
}

// 3. Comando: --files--
if (compare_strings(input, "--files--")) {
    show_file_explorer();
}
}
