// [LANGUAGE: RUST]
// [FILE: safety_manager.rs]
// [PROJECT: ARkalpyOS]
// ---------------------------------------------------------
#![no_std]

pub struct SystemSettings {
    pub language: i32,
    pub video_mode: i32,
    pub security_level: i32,
}

impl SystemSettings {
    pub fn new() -> Self {
        SystemSettings {
            language: 1, // 1 = PT-BR
            video_mode: 0x13, 
            security_level: 10,
        }
    }

    pub fn update_option(&mut self, id: i32, val: i32) {
        match id {
            101 => self.language = val,
            102 => self.video_mode = val,
            666 => self.wipe_request(), // Chama o limpador de disco
            _ => {},
        }
    }

    fn wipe_request(&self) {
        // Lógica para sinalizar ao Kernel o apagamento total
    }
}

#[no_mangle]
pub extern "C" fn process_settings(id: i32, val: i32) {
    let mut settings = SystemSettings::new();
    settings.update_option(id, val);
}
