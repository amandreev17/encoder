#include <memory.h>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


void encoder_decoder(const char* in, char* out, int len, int key, bool shifr = true) {
    int len1 = len / 2;
    int len2 = len % 2;
    mt19937 bas(key);
    uniform_int_distribution<uint16_t> gen(0, 0xffff);
    uint16_t rez, gamma;
    if (len2) len1++;
    int size = 2;
    for (int i = 0; i < len1; i++) {
        if (len2)
            if (i == len1 - 1) {
                size = len2;
                rez = 0;
            }
        memcpy(&rez, in + i * 2, size);
        if (!shifr) {
            rez = (rez >> 1) | (rez << (size * 8 - 1));
        }
        gamma = gen(bas);
        if (len2)
            if (i == len1 - 1) {
                uint16_t maska = 0xff;
                for (uint8_t i = 1; i < len2; i++) {
                    maska <<= 8;
                    maska += 0xff;
                }
                gamma &= maska;
            }
        
        rez ^= gamma;
        
        if (shifr) {
            rez = (rez << 1) | (rez >> (size * 8 - 1));
        }
        memcpy(out + i * 2, &rez, size);
    }
};

