
<p align="center">
  <img src="https://img.shields.io/github/stars/SEU-USUARIO/SEU-REPO?style=for-the-badge&color=gold" />
  <img src="https://img.shields.io/github/forks/SEU-USUARIO/SEU-REPO?style=for-the-badge&color=blue" />
  <img src="https://img.shields.io/badge/Language-7_Polyglot-orange?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Platform-x86_Architecture-red?style=for-the-badge" />
</p>

<p align="center"> 🌌 ARKALPY-OS: THE POLYGLOT BARE-METAL ARCHITECTURE 🌌 ALPHA </p>
<p align="center">
<img src="https://capsule-render.vercel.app/render?type=soft&color=000000&height=300&section=header&text=ARkalpyOS&fontSize=120&animation=fadeIn&fontAlignY=38" width="100%" />
</p>

<p align="center">
<img src="https://img.shields.io/badge/STATUS-GIGANTE-red?style=for-the-badge" />
<img src="https://img.shields.io/badge/INTERFACE-MOSAIC_TILED-green?style=for-the-badge" />
<img src="https://img.shields.io/badge/LICENSE-AUTHOR_CREDIT_REQUIRED-white?style=for-the-badge" />
</p>

📂 Estrutura do Projeto (ARkalpyOS File Tree)
ARkalpyOS/
|
|-- boot/ (Código de Inicialização)
|   |-- boot_entry.asm (Assembly - O despertar do hardware)
|   |-- linker.ld (O mapa de memória do sistema)
|
|-- kernel/ (O Coração do Mosaico)
|   |-- mosaic_kernel.cpp (C++ - Interface e Lógica Central)
|   |-- safety_core.rs (Rust - Proteção de Memória)
|
|-- drivers/ (Interação com Hardware)
|   |-- disk_wipe.c (C - Módulo de limpeza de setores)
|
|-- apps/ (Programas do Sistema)
|   |-- calculator_fpu.cs (C# - Aplicação de Cálculos)
|
|-- tools/ (Scripts de Construção)
|   |-- build_system.pl (Perl - O Orquestrador de Compilação)
|   |-- iso_manager.py (Python - Gerador de Imagem ISO)
|
|-- docs/ (Documentação)
|   |-- architecture.md (Explicação das 7 linguagens)
|

📖 1. A FILOSOFIA SUPREMA
O ARkalpyOS é um sistema operacional purista desenvolvido para controle total do hardware. Ele funde a estética geométrica de mosaicos (Tiled UI) com a robustez de um núcleo focado em terminal. Aqui, não existem abstrações desnecessárias: o usuário domina a máquina através de scripts e comandos diretos.

"O código é uma lei, e este sistema é o tribunal."

🛠️ 2. O ARSENAL TÉCNICO (STACK POLIGLOTA)
Este sistema é uma obra de engenharia complexa que utiliza 7 linguagens diferentes para atingir a performance máxima:

📥 Camada de Núcleo & Hardware
<p align="left">
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" width="60" title="C" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" width="60" title="C++" />
<img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/rust/rust-original.svg" width="60" title="Rust" />
</p>

x86 Assembly: Responsável pelo boot_entry.asm. Gerencia a transição para modo protegido e a "chuva de números" no boot.

C: Implementa a comunicação direta com portas de I/O e a função crítica de limpeza de disco.

C++: O motor da Mosaic Engine, desenhando a interface geométrica pixel por pixel.

Rust: Gestão de memória ultra-segura para evitar falhas críticas de sistema.

💻 Camada de Interface & Automação
<p align="left">
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/csharp/csharp-original.svg" width="60" title="C#" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg" width="60" title="Python" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/perl/perl-original.svg" width="60" title="Perl" />
</p>

C#: Lógica das aplicações de usuário como a Calculadora e Painel de Ajustes.

Python: Gestor de integridade e criador da imagem ISO final.

Perl: O "Cérebro" do Build, orquestrando a compilação de todas as camadas.

🏁 3. BOOT E INSTALAÇÃO (PUREZA ABSOLUTA)
O ARkalpyOS não possui menções a outros sistemas operacionais. Sua identidade é única:

Chuva de Números: Ao ligar, milhares de códigos hexadecimais sobem na tela preta, validando cada setor do hardware.

Limpador de Disco: O sistema possui uma ferramenta integrada de Limpeza Profunda. Ao ser acionada, ela sobrescreve qualquer sistema anterior (Windows, Linux ou outros) com zeros, exibindo o progresso técnico em tempo real.

graph TD
    A[Boot em Assembly] --> B[Kernel em C++]
    B --> C{Mosaic Engine}
    C --> D[App em C#]
    C --> E[Wipe Tool em C]
    F[Rust Safety Layer] -.->|Protege| B
    G[Perl Build System] -->|Orquestra| A
    H[Python ISO Creator] -->|Gera| ISO[arkalpy.iso]

🖥️ 4. INTERFACE MOSAIC (TILED UI)
Inspirada em designs clássicos, mas totalmente original. A tela é dividida em mosaicos fixos:

GOOGLE ENGINE: Busca interna de alta velocidade integrada ao kernel.

CALCULADORA: Operação direta via unidade de ponto flutuante da CPU.

AJUSTES GIGANTE: Menu denso para controle de partições, cores e segurança.

TERMINAL: Um ambiente de shell radicalmente diferente, focado em monitoramento bruto de hardware.

📜 5. LICENÇA E DIREITOS AUTORAIS
ESTE É UM PROJETO DE CÓDIGO ABERTO SOB CONDIÇÕES ESPECÍFICAS.

Liberdade de Uso: Você pode baixar, estudar e alterar o código como desejar.

Atribuição Obrigatória: Qualquer modificação ou distribuição do ARkalpyOS deve, obrigatoriamente, manter os créditos claros e visíveis ao CRIADOR ORIGINAL.

Direito de Autoria: O nome do criador deve permanecer no topo dos arquivos e na tela de inicialização do sistema.

📂 6. ESTRUTURA DO PROJETO
/ARkalpyOS
├── boot_entry.asm      # [Assembly] Inicialização e Chuva de Números
├── mosaic_kernel.cpp   # [C++] Motor Gráfico de Mosaicos
├── hardware_io.c       # [C] Limpeza de Disco e Comunicação Bruta
├── safety_manager.rs   # [Rust] Gestor de Memória
├── app_interface.cs    # [C#] Calculadora e Ajustes
├── build_logic.pl      # [Perl] Mestre de Obras (Compilação)
├── iso_manager.py      # [Python] Gerador de ISO
└── link.ld             # [Linker] Mapa da Memória RAM
<p align="center">
  O ARkalpyOS utiliza uma segmentação de memória rígida para garantir a performance Bare-Metal:

| Endereço Inicial | Tamanho | Função |
| :--- | :--- | :--- |
| `0x00007C00` | 512 B | Bootloader (Assembly Entry) |
| `0x00001000` | 64 KB | Kernel Stack (C++) |
| `0x000B8000` | 4 KB | VGA Text Buffer (Mosaic Display) |
| `0x00100000` | 1 MB+ | Safety Core (Rust Protected Area) |

<b>ARkalpyOS - Criado por [UserNight26]</b>



<i>"A soberania do código sobre o hardware."</i>
</p>
