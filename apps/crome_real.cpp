/*
 * ARkalpyOS - Crome Browser (Real Engine)
 */

void crome_request_url(const char* ip_address) {
    // Cria um pacote HTTP Real
    const char* get_request = "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n";

    // O C++ chama a pilha Rust, que chama o Driver C
    network_stack_send(ip_address, 80, get_request);
    
    // Espera a resposta da placa de rede
    char* response = wait_for_network_response();
    
    // Renderiza o HTML bruto recebido no Mosaico
    render_raw_html(response);
}
