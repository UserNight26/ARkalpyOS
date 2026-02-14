/* **************************************************************************
 * ARkalpyOS - Google Crome Download Support Hook
 * Gerencia a entrada de pacotes de dados vindos do navegador
 * Language: Rust (Safety & Networking)
 * **************************************************************************
 */

use crate::storage::VFS;

pub enum DownloadType { Document, Executable, Media }

pub struct ChromeDownloadHook {
    pub url_source: String,
    pub bytes_received: u64,
    pub file_type: DownloadType,
}

impl ChromeDownloadHook {
    pub fn init_stream(url: &str) -> Self {
        let dtype = if url.contains(".exe") {
            DownloadType::Executable
        } else if url.contains(".mp4") || url.contains(".wav") {
            DownloadType::Media
        } else {
            DownloadType::Document
        };

        ChromeDownloadHook {
            url_source: String::from(url),
            bytes_received: 0,
            file_type: dtype,
        }
    }

    /// Recebe chunks de dados do driver de rede e envia para o disco
    pub fn process_packet(&mut self, data: &[u8]) -> bool {
        // Validação de Segurança Rust: Impede pacotes maliciosos de corromper o Kernel
        if data.len() > 1500 { // Limite padrão MTU
            return false;
        }

        self.bytes_received += data.len() as u64;

        // Define a pasta de destino baseada no tipo de ficheiro
        let path = match self.file_type {
            DownloadType::Executable => "/bin/downloads/",
            DownloadType::Media => "/home/user/videos/",
            DownloadType::Document => "/home/user/docs/",
        };

        // Grava no disco usando o driver ATA em C
        unsafe {
            let filename = "downloaded_file";
            VFS::write_to_disk(path, filename, data);
        }

        true
    }

    pub fn get_progress(&self) -> u8 {
        // Simulação de cálculo de percentagem
        ((self.bytes_received % 100) as u8)
    }
}

#[no_mangle]
pub extern "C" fn chrome_api_download_start(url_ptr: *const u8) {
    // Função chamada pelo C++ do navegador Crome
    println!("Crome solicitou download do ficheiro...");
}
