#pragma once

#include <chrono>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <random>

class Chip8
{

private:
    void OP_00E0();
    void OP_00EE();
    void OP_1nnn();
    void OP_2nnn();
    void OP_3xkk();
    void OP_4xkk();
    void OP_5xy0();
    void OP_6xkk();
    void OP_7xkk();
    void OP_8xy0();
    void OP_8xy1();
    void OP_8xy2();
    void OP_8xy3();
    void OP_8xy4();
    void OP_8xy5();
    void OP_8xy6();
    void OP_8xy7();
    void OP_8xyE();
    void OP_9xy0();
    void OP_Annn();
    void OP_Bnnn();
    void OP_Cxkk();
    void OP_Dxyn();
    void OP_Ex9E();
    void OP_ExA1();
    void OP_Fx07();
    void OP_Fx0A();
    void OP_Fx15();
    void OP_Fx18();
    void OP_Fx1E();
    void OP_Fx29();
    void OP_Fx33();
    void OP_Fx55();
    void OP_Fx65();
    void OP_NULL();

    typedef void (Chip8::*Chip8Func)();
	Chip8Func table[0xF + 1]{&Chip8::OP_NULL};
	Chip8Func table0[0xE + 1]{&Chip8::OP_NULL};
	Chip8Func table8[0xE + 1]{&Chip8::OP_NULL};
	Chip8Func tableE[0xE + 1]{&Chip8::OP_NULL};
	Chip8Func tableF[0x65 + 1]{&Chip8::OP_NULL};

    void Table0();
    void Table8();
    void TableE();
    void TableF();


    
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
    const unsigned int VIDEO_WIDTH = 64;
    const unsigned int VIDEO_HEIGHT = 32;
    // Responsável por guardar o opcode atual
    uint16_t opcode{};
    // Responsável pelos números random
    std::default_random_engine randGen;
    std::uniform_int_distribution<uint8_t> randByte;

    // MÉTODOS
    Chip8();
    void LoadROM(char const* filename);
    void Cycle();
    
};

