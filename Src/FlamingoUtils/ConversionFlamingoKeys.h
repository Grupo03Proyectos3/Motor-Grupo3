#pragma once
#include <cstdint>
#include <SDL_keycode.h>
#include "FlamingoKeys.h"
namespace Flamingo{  
    SDL_KeyCode ConversorFlamingoKeys(Flamingo::FLM_KeyCode tecla){
        switch (tecla){
            case FLM_UNKNOWN : return SDLK_UNKNOWN;
            case FLM_RETURN : return SDLK_RETURN;
            case FLM_ESCAPE : return SDLK_ESCAPE;
            case FLM_BACKSPACE : return SDLK_BACKSPACE;
            case FLM_TAB : return SDLK_TAB;
            case FLM_SPACE : return SDLK_SPACE;
            case FLM_EXCLAIM : return SDLK_EXCLAIM;
            case FLM_QUOTEDBL : return SDLK_QUOTEDBL;
            case FLM_HASH : return SDLK_HASH;
            case FLM_PERCENT : return SDLK_PERCENT;
            case FLM_DOLLAR : return SDLK_DOLLAR;
            case FLM_AMPERSAND : return SDLK_AMPERSAND;
            case FLM_QUOTE : return SDLK_QUOTE;
            case FLM_LEFTPAREN : return SDLK_LEFTPAREN;
            case FLM_RIGHTPAREN : return SDLK_RIGHTPAREN;
            case FLM_ASTERISK : return SDLK_ASTERISK;
            case FLM_PLUS : return SDLK_PLUS;
            case FLM_COMMA : return SDLK_COMMA;
            case FLM_MINUS : return SDLK_MINUS;
            case FLM_PERIOD : return SDLK_PERIOD;
            case FLM_SLASH : return SDLK_SLASH;
            case FLM_0 : return SDLK_0;
            case FLM_1 : return SDLK_1;
            case FLM_2 : return SDLK_2;
            case FLM_3 : return SDLK_3;
            case FLM_4 : return SDLK_4;
            case FLM_5 : return SDLK_5;
            case FLM_6 : return SDLK_6;
            case FLM_7 : return SDLK_7;
            case FLM_8 : return SDLK_8;
            case FLM_9 : return SDLK_9;
            case FLM_COLON : return SDLK_COLON;
            case FLM_SEMICOLON : return SDLK_SEMICOLON;
            case FLM_LESS : return SDLK_LESS;
            case FLM_EQUALS : return SDLK_EQUALS;
            case FLM_GREATER : return SDLK_GREATER;
            case FLM_QUESTION : return SDLK_QUESTION;
            case FLM_AT : return SDLK_AT;
            case FLM_LEFTBRACKET : return SDLK_LEFTBRACKET;
            case FLM_BACKSLASH : return SDLK_BACKSLASH;
            case FLM_RIGHTBRACKET : return SDLK_RIGHTBRACKET;
            case FLM_CARET : return SDLK_CARET;
            case FLM_UNDERSCORE : return SDLK_UNDERSCORE;
            case FLM_BACKQUOTE : return SDLK_BACKQUOTE;
            case FLM_a : return SDLK_a;
            case FLM_b : return SDLK_b;
            case FLM_c : return SDLK_c;
            case FLM_d : return SDLK_d;
            case FLM_e : return SDLK_e;
            case FLM_f : return SDLK_f;
            case FLM_g: return SDLK_g;
            case FLM_h : return SDLK_h;
            case FLM_i : return SDLK_i;
            case FLM_j : return SDLK_j;
            case FLM_k : return SDLK_k;
            case FLM_l : return SDLK_l;
            case FLM_m : return SDLK_m;
            case FLM_n : return SDLK_n;
            case FLM_o : return SDLK_o;
            case FLM_p : return SDLK_p;
            case FLM_q : return SDLK_q;
            case FLM_r : return SDLK_r;
            case FLM_s : return SDLK_s;
            case FLM_t : return SDLK_t;
            case FLM_u : return SDLK_u;
            case FLM_v : return SDLK_v;
            case FLM_w : return SDLK_w;
            case FLM_x : return SDLK_x;
            case FLM_y : return SDLK_y;
            case FLM_z : return SDLK_z;

            case FLM_CAPSLOCK : return SDLK_CAPSLOCK;

            case FLM_F1 : return SDLK_F1;
            case FLM_F2 : return SDLK_F2;
            case FLM_F3 : return SDLK_F3;
            case FLM_F4 : return SDLK_F4;
            case FLM_F5 : return SDLK_F5;
            case FLM_F6 : return SDLK_F6;
            case FLM_F7 : return SDLK_F7;
            case FLM_F8 : return SDLK_F8;
            case FLM_F9 : return SDLK_F9;
            case FLM_F10 : return SDLK_F10;
            case FLM_F11 : return SDLK_F11;
            case FLM_F12 : return SDLK_F12;

            case FLM_PRINTSCREEN : return SDLK_PRINTSCREEN;
            case FLM_SCROLLLOCK : return SDLK_SCROLLLOCK;
            case FLM_PAUSE : return SDLK_PAUSE;
            case FLM_INSERT : return SDLK_INSERT;
            case FLM_HOME : return SDLK_HOME;
            case FLM_PAGEUP : return SDLK_PAGEUP;
            case FLM_DELETE : return SDLK_DELETE;
            case FLM_END : return SDLK_END;
            case FLM_PAGEDOWN : return SDLK_PAGEDOWN;
            case FLM_RIGHT : return SDLK_RIGHT;
            case FLM_LEFT : return SDLK_LEFT;
            case FLM_DOWN : return SDLK_DOWN;
            case FLM_UP : return SDLK_UP;

            case FLM_NUMLOCKCLEAR : return SDLK_NUMLOCKCLEAR;
            case FLM_KP_DIVIDE : return SDLK_KP_DIVIDE;
            case FLM_KP_MULTIPLY : return SDLK_KP_MULTIPLY;
            case FLM_KP_MINUS : return SDLK_KP_MINUS;
            case FLM_KP_PLUS : return SDLK_KP_PLUS;
            case FLM_KP_ENTER : return SDLK_KP_ENTER;
            case FLM_KP_1 : return SDLK_KP_1;
            case FLM_KP_2 : return SDLK_KP_2;
            case FLM_KP_3 : return SDLK_KP_3;
            case FLM_KP_4 : return SDLK_KP_4;
            case FLM_KP_5 : return SDLK_KP_5;
            case FLM_KP_6 : return SDLK_KP_6;
            case FLM_KP_7 : return SDLK_KP_7;
            case FLM_KP_8 : return SDLK_KP_8;
            case FLM_KP_9 : return SDLK_KP_9;
            case FLM_KP_0 : return SDLK_KP_0;
            case FLM_KP_PERIOD : return SDLK_KP_PERIOD;
        }
    };
} // namespace Flamingo