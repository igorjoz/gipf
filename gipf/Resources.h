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


//namespace std {
//    template <> struct hash<Hex> {
//        size_t operator()(const Hex& h) const {
//            hash<int> int_hash;
//            size_t hq = int_hash(h.q);
//            size_t hr = int_hash(h.r);
//            return hq ^ (hr + 0x9e3779b9 + (hq << 6) + (hq >> 2));
//        }
//    };
//}




namespace std {
    template<>
    struct hash<Hex> {
        std::size_t operator()(const Hex& h) const {
            std::size_t hq = std::hash<int>{}(h.q);
            std::size_t hr = std::hash<int>{}(h.r);
            std::size_t hs = std::hash<int>{}(h.s);
            return hq ^ (hr << 1) ^ (hs << 2);
        }
    };
}


