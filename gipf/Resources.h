#pragma once


#include "Hex.h"


enum Command {
    NONE,
    LOAD_GAME_BOARD
};


enum CommandResult {
    BOARD_STATE_OK,
    WRONG_BLACK_PAWNS_NUMBER,
    WRONG_WHITE_PAWNS_NUMBER,
    WRONG_BOARD_ROW_LENGTH
};


namespace std {
    template <> struct hash<Hex> {
        size_t operator()(const Hex& h) const {
            hash<int> int_hash;
            size_t hq = int_hash(h.q);
            size_t hr = int_hash(h.r);
            return hq ^ (hr + 0x9e3779b9 + (hq << 6) + (hq >> 2));
        }
    };
}


