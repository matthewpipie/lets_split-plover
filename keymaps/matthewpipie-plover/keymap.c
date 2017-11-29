#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _PLOVER 1
#define _GAME 2
#define _NUMPAD 3
#define _RAISE 4
#define _FN 5
#define _NAV 10

enum custom_keycodes {
  PLOVER_ON = SAFE_RANGE,
  PLOVER_OFF,
  VOLZERO,
  PREV_SONG,
  NEXT_SONG,
  RAISE,
  NUMPAD_ON,
  NUMPAD_OFF,
  GAME_ON,
  GAME_OFF,
  SET_DEFAULT_TO_QWERTY,
  VLC_FASTER,
  VLC_SLOWER,
  VLC_RESET_SPEED,
  VLC_PAUSEPLAY,
  VLC_FINESLOWER,
  VLC_FINEFASTER,
  VLC_SMALLBACK,
  VLC_SMALLFWD,
  VLC_MEDBACK,
  VLC_MEDFWD
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Esc|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Bksp  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   Mod|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Vol0|  Vol-|  Vol+|   Alt|  Ctrl| Space|Space |Raise |Nav   |Game  |Plover|Numpad|
 * `-----------------------------------------------------------------------------------'
 */
  
[_QWERTY] = KEYMAP( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,  KC_I,     KC_O,    KC_P,      KC_BSPC,  \
  KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,  KC_K,     KC_L,    KC_SCLN,   KC_ENT,   \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,   KC_QUOT,  \
  VOLZERO, KC_VOLD, KC_VOLU, KC_LALT, KC_LCTL, KC_SPC, KC_SPC, RAISE, MO(_NAV), GAME_ON, PLOVER_ON, NUMPAD_ON \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  Tab |   ?  |   ?  |   ?  |   ?  |   ?  |   -  |   =  |   [  |   ]  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  Caps| Mute |   ?  |   ?  |   ?  |   ?  |   ?  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MPause| MPrev| MNext|      |      |      |      |      |      |XXXXXX|XXXXXX|  FN  |
 * `-----------------------------------------------------------------------------------'
 */
 
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_TAB,    KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DEL,  \
  KC_TRNS, KC_1,      KC_2,      KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
  KC_TRNS, KC_CAPS,   KC_MUTE,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_MPLY, PREV_SONG, NEXT_SONG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   MO(_FN)  \
),

/* FN
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |DEFQWR|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RESET| DEBUG|  NKRO|      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 
[_FN] = KEYMAP( \
  KC_TRNS, KC_TRNS,               KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_F1,                 KC_F2,             KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS, \
  KC_TRNS, SET_DEFAULT_TO_QWERTY, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  RESET,   DEBUG,                 MAGIC_TOGGLE_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
),
 
/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |XXXXXX|XXXXXX|XXXXXX|
 * `-----------------------------------------------------------------------------------'
 */
 
[_NAV] = KEYMAP( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO    \
),

/* Game
 * ,-----------------------------------------------------------------------------------.
 * |   Esc|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Bksp  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   Tab|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   /  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Ctrl|  Mod |  Alt |   1  |   2  | Space|  3   |  4   |  5   | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
 
[_GAME] = KEYMAP( \
  KC_ESC,  KC_Q,    KC_W,    KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_BSPC,  \
  KC_TAB,  KC_A,    KC_S,    KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,    KC_SLSH, KC_ENT,   \
  KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT,  KC_UP,   GAME_OFF, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_1, KC_2, KC_SPC, KC_3, KC_4, KC_5,    KC_LEFT, KC_DOWN, KC_RGHT   \
),
 
/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |   Esc|   Tab| PrSc |ScrlLk|PBreak|XXXXXX|XXXXXX|  7   |  8   |  9   |  /   | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   Mod|XXXXXX|  Ins | Home | PgUp |XXXXXX| NmLk |  4   |  5   |  6   |  *   |XXXXXX|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|XXXXXX|  Del |  End | PgDn |XXXXXX|XXXXXX|  1   |  2   |  3   |  -   |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |XXXXXX|XXXXXX|XXXXXX|   Alt|  Ctrl| Space|Space |  0   |  .   |Enter |  +   |XXXXXX|
 * `-----------------------------------------------------------------------------------'
 */
 
[_NUMPAD] = KEYMAP( \
  KC_ESC,  KC_TAB, KC_PSCR, KC_SLCK, KC_PAUS, KC_NO,  KC_NO,   KC_P7, KC_P8,   KC_P9,   KC_PSLS, KC_BSPC,    \
  KC_LGUI, KC_NO,  KC_INS,  KC_HOME, KC_PGUP, KC_NO,  KC_NLCK, KC_P4, KC_P5,   KC_P6,   KC_PAST, KC_NO,      \
  KC_LSFT, KC_NO,  KC_DEL,  KC_END,  KC_PGDN, KC_NO,  KC_NO,   KC_P1, KC_P2,   KC_P3,   KC_PMNS, NUMPAD_OFF, \
  KC_NO,   KC_NO,  KC_NO,   KC_LALT, KC_LCTL, KC_SPC, KC_SPC,  KC_P0, KC_PDOT, KC_PENT, KC_PPLS, KC_NO       \
),
 
/* Plover
 * ,-----------------------------------------------------------------------------------.
 * |Faster|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Slower|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |ResetS|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Pause| Pause|FSlowe|FFaste|   C  |   V  |   N  |   M  |SmallB|SmallF|MedBak|MedFwd|
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = KEYMAP( \
  VLC_FASTER,      KC_Q,          KC_W,           KC_E,           KC_R, KC_T, KC_Y, KC_U, KC_I,          KC_O,         KC_P,        KC_LBRC,    \
  VLC_SLOWER,      KC_A,          KC_S,           KC_D,           KC_F, KC_G, KC_H, KC_J, KC_K,          KC_L,         KC_SCLN,     KC_QUOT,    \
  VLC_RESET_SPEED, KC_1,          KC_2,           KC_3,           KC_4, KC_5, KC_6, KC_7, KC_8,          KC_9,         KC_0,        PLOVER_OFF, \
  VLC_PAUSEPLAY,   VLC_PAUSEPLAY, VLC_FINESLOWER, VLC_FINEFASTER, KC_C, KC_V, KC_N, KC_M, VLC_SMALLBACK, VLC_SMALLFWD, VLC_MEDBACK, VLC_MEDFWD  \
),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void vlc_code(uint16_t keycode) {
	register_code(KC_LCTL);
	register_code(KC_LSFT);
	register_code(KC_LALT);
	register_code(keycode);
	unregister_code(keycode);
	unregister_code(KC_LALT);
	unregister_code(KC_LSFT);
	unregister_code(KC_LCTL);
}

void plover_off_keymap(void) {
  register_code(KC_E);
  register_code(KC_R);
  register_code(KC_F);
  register_code(KC_V);
  register_code(KC_Y);
  register_code(KC_U);
  
  unregister_code(KC_E);
  unregister_code(KC_R);
  unregister_code(KC_F);
  unregister_code(KC_V);
  unregister_code(KC_Y);
  unregister_code(KC_U);
}
void plover_on_keymap(void) {
  register_code(KC_E);
  register_code(KC_R);
  register_code(KC_F);
  register_code(KC_V);
  register_code(KC_H);
  register_code(KC_I);
  register_code(KC_K);
  
  unregister_code(KC_E);
  unregister_code(KC_R);
  unregister_code(KC_F);
  unregister_code(KC_V);
  unregister_code(KC_H);
  unregister_code(KC_I);
  unregister_code(KC_K);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case RAISE:
        layer_on(_RAISE);
        return false; break;
      case NUMPAD_ON:
        layer_on(_NUMPAD);
        return false; break;
	  case GAME_ON:
		layer_on(_GAME);
		return false; break;
	  case NUMPAD_OFF:
        layer_off(_NUMPAD);
        return false; break;
	  case GAME_OFF:
		layer_off(_GAME);
		return false; break;
      case VOLZERO:
        for (int i = 0; i < 50; i++) {
  	      register_code(KC_VOLD);
          unregister_code(KC_VOLD);
        }
        return false; break;
      case NEXT_SONG:
        register_code(KC_MNXT);
        unregister_code(KC_MNXT);
        register_code(KC_MFFD);
        unregister_code(KC_MFFD);
        return false; break;
      case PREV_SONG:
        register_code(KC_MPRV);
        unregister_code(KC_MPRV);
        register_code(KC_MRWD);
        unregister_code(KC_MRWD);
        return false; break;
      case PLOVER_OFF:
        plover_off_keymap();
        
        layer_off(_PLOVER);
        layer_off(_GAME);
        layer_off(_RAISE);
        layer_off(_FN);
        layer_off(_NAV);
        return false; break;
      case PLOVER_ON:
        plover_on_keymap();
        
        layer_on(_PLOVER);
        layer_off(_GAME);
        layer_off(_RAISE);
        layer_off(_FN);
        layer_off(_NAV);
        keymap_config.nkro = 1;
        return false; break;
      case SET_DEFAULT_TO_QWERTY:
        persistent_default_layer_set(1UL<<_QWERTY);
        return false; break;
	  case VLC_FASTER:
	    vlc_code(KC_2);
		return false; break;
	  case VLC_SLOWER:
	    vlc_code(KC_3);
		return false; break;
	  case VLC_RESET_SPEED:
	    vlc_code(KC_4);
		return false; break;
	  case VLC_PAUSEPLAY:
	    vlc_code(KC_1);
		return false; break;
	  case VLC_FINEFASTER:
	    vlc_code(KC_5);
		return false; break;
	  case VLC_FINESLOWER:
	    vlc_code(KC_6);
		return false; break;
	  case VLC_SMALLBACK:
	    vlc_code(KC_8);
		return false; break;
	  case VLC_SMALLFWD:
	    vlc_code(KC_9);
		return false; break;
	  case VLC_MEDBACK:
	    vlc_code(KC_0);
		return false; break;
	  case VLC_MEDFWD:
	    vlc_code(KC_7);
		return false; break;
	}
  }
  else {
    switch(keycode) {
      case RAISE:
        layer_off(_RAISE);
        layer_off(_FN);
        layer_off(_NUMPAD);
        return false; break;
      case NUMPAD_ON:
        layer_off(_RAISE);
        layer_off(_FN);
        return false; break;
    }
  }
  return true;
}
