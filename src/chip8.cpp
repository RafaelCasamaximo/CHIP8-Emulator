#include "chip8.hpp"
#include <chrono>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <random>

void Chip8::LoadROM(char const* filename)
{
    // Abre o arquivo no modo binario e no final do arquivo
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if(file.is_open())
    {
        /**
        * Cria um buffer com o tamanho da ROM
        * Salva todo o conteúdo da ROM nesse buffer
        * Fecha o arquivo
        */
        std::streampos size = file.tellg();
        char* buffer = new char[size];
        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();

        // Adiciona todo o conteúdo da ROM na RAM
        for(long i = 0; i < size; i++)
        {
            memory[START_ADDRESS + i] = buffer[i]; 
        }

        delete[] buffer;
    }


}

Chip8::Chip8()
{
    pc = START_ADDRESS;

    // Carrega a fonte na memoria
    for(unsigned int i = 0; i < FONTSET_SIZE; i++)
    {
        memory[FONTSET_START_ADDRESS + i] = fontset[i];
    }
}