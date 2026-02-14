/* * ARkalpyOS - FPU Safety Guard
 * Garante que a calculadora use o coprocessador matemático com segurança
 */

#[no_mangle]
pub extern "C" fn enable_fpu() {
    unsafe {
        // Habilita bits CR0 e CR4 no processador x86 para cálculos reais
        let mut cr0: u32;
        core::arch::asm!("mov {}, cr0", out(reg) cr0);
        cr0 &= !(1 << 2); // Limpa bit EM (Emulação)
        cr0 |= 1 << 1;    // Seta bit MP (Monitorar Coprocessador)
        core::arch::asm!("mov cr0, {}", in(reg) cr0);
    }
}

#[no_mangle]
pub extern "C" fn check_math_overflow(val: f64) -> bool {
    // Verifica se o resultado é Infinito ou NaN (Not a Number)
    val.is_infinite() || val.is_nan()
}
