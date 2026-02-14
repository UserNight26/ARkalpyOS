/*
 * Validação de acesso a portas de áudio e rede
 */

#[no_mangle]
pub extern "C" fn validate_io_request(port: u16) -> bool {
    match port {
        0x60..=0x64 => true,  // Portas de Teclado/Bateria permitidas
        0x1F0..=0x1F7 => true, // Portas de Disco (Wipe Tool) permitidas
        _ => false,            // Bloqueia acessos desconhecidos
    }
}
