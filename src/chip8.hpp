#pragma once

#include <cstdint>

class Chip8
{

private:
    
public:
    // ATRIBUTOS
    // 16 registradores 8bits
    uint8_t registers[16]{};
    // 4096k de memoria (8bits cada)
    uint8_t memory[4096]{};
    // Endereço onde o programa pode começar
    // a ser carregado
    const unsigned int START_ADDRESS = 0x200;
    // Tamanho do fontset
    const unsigned int FONTSET_SIZE = 80;
    // Endereço onde começa o fontset
    const unsigned int FONTSET_START_ADDRESS = 0x50;
    // Fontset
    uint8_t fontset[80] = {
		0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
		0x20, 0x60, 0x20, 0x20, 0x70, // 1
		0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
		0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
		0x90, 0x90, 0xF0, 0x10, 0x10, // 4
		0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
		0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
		0xF0, 0x10, 0x20, 0x40, 0x40, // 7
		0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
		0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
		0xF0, 0x90, 0xF0, 0x90, 0x90, // A
		0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
		0xF0, 0x80, 0x80, 0x80, 0xF0, // C
		0xE0, 0x90, 0x90, 0x90, 0xE0, // D
		0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
		0xF0, 0x80, 0xF0, 0x80, 0x80  // F
	};
    // Registrador especial para guardar endereços]
    // utilizados em diferentes operações
    uint16_t index{};
    // Registrador program counter
    uint16_t pc{};
    // Stack com 16 posições
    // Cada posição com 16bits ou 2bytes
    uint16_t stack[16]{};
    // Ponteiro/ registrador da stack
    uint16_t sp{};
    // Timers da arquitetura do chip8
    uint8_t delayTimer{};
    uint8_t soundTimer{};
    // Teclado/ input do console
    uint8_t keypad[16]{};
    // Vetor que representa a matriz de video
    // A resolução é 64x32
    // uint32_t para facilitar a comunicação com SDL
    uint32_t video[64 * 32]{};
    // Responsável por guardar o opcode atual
    uint16_t opcode{};

    // MÉTODOS
    Chip8();
    void LoadROM(char const* filename);
};

