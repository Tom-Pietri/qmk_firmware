#include QMK_KEYBOARD_H
#include "version.h"
#include "unicode_key.h"
#include "config.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

enum {
  TD_A,
  TD_C,
  TD_E,
  TD_O,
  TD_U
};


void a_tapdance (qk_tap_dance_state_t *state, void *user_data) { 
  switch (state->count)
  {
    case 2:
      unicode_input_start();
      register_hex(A_AIGU_HEX);
      unicode_input_finish();
      break;
  
    default:
        register_code(KC_A);
        unregister_code(KC_A);
      break;
  }
}

void c_tapdance (qk_tap_dance_state_t *state, void *user_data) { 
  switch (state->count)
  {
    case 2:
      unicode_input_start();
      register_hex(C_CEDILLE_HEX);
      unicode_input_finish();
      break;
  
    default:
        register_code(KC_C);
        unregister_code(KC_C);
      break;
  }
}

void e_tapdance (qk_tap_dance_state_t *state, void *user_data) { 
  switch (state->count)
  {
    case 2:
      unicode_input_start();
      register_hex(E_AIGU_HEX);
      unicode_input_finish();
      break;
    case 3:
      unicode_input_start();
      register_hex(E_GRAVE_HEX);
      unicode_input_finish();
      break;
    case 4:
      unicode_input_start();
      register_hex(E_CIRCONFLEX_HEX);
      unicode_input_finish();
      break;
  
    default:
        register_code(KC_E);
        unregister_code(KC_E);
      break;
  }
}

void o_tapdance (qk_tap_dance_state_t *state, void *user_data) { 
  switch (state->count)
  {
    case 2:
      unicode_input_start();
      register_hex(O_CIRCONFLEX_HEX);
      unicode_input_finish();
      break;
  
    default:
        register_code(KC_O);
        unregister_code(KC_O);
      break;
  }
}

void u_tapdance (qk_tap_dance_state_t *state, void *user_data) { 
  switch (state->count)
  {
    case 2:
      unicode_input_start();
      register_hex(U_GRAVE_HEX);
      unicode_input_finish();
      break;
  
    default:
        register_code(KC_U);
        unregister_code(KC_U);
      break;
  }
}


qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_A]  = ACTION_TAP_DANCE_FN(a_tapdance),
  [TD_C]  = ACTION_TAP_DANCE_FN(c_tapdance),
  [TD_E]  = ACTION_TAP_DANCE_FN(e_tapdance),
  [TD_O]  = ACTION_TAP_DANCE_FN(o_tapdance),
  [TD_U]  = ACTION_TAP_DANCE_FN(u_tapdance)
  // Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |  '   |           |  `   |   6  |   7  |   8  |   9  |   0  | BSPACE |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   A  |   Z  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Del   |   Q  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   M  | Enter  |
 * |--------+------+------+------+------+------| HOME |           | END  |------+------+------+------+------+--------|
 * | LShift |   W  |   X  |   C  |   V  |   B  |      |           |      |   N  |   ;  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Alt  |Windws|   '  | L1tmp|                                       |  Up  | Down | Left |Right |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.       ,-------------.
 *                                        |  [    |  ]   |       |      |Ctrl   |
 *                                 ,------|-------|------|       |------+-------+------.
 *                                 |      |       | L2tmp|       | PgUp |        |     |
 *                                 | Space|BSPACE |------|       |------| BSPACE |Space |
 *                                 |      |       | Shift|       | PgDn |        |     |
 *                                 `---------------------'        `--------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_ESCAPE,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_QUOTE,
  KC_TAB,         TD(TD_A),        KC_Z,          TD(TD_E),    KC_R,    KC_T,    TG(SYMB),
  KC_DELETE,         KC_Q,        KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,         KC_W, KC_X,          TD(TD_C),    KC_V,    KC_B,    KC_HOME,
  KC_LCTRL, KC_LALT,     KC_LGUI, KC_TRNS, MO(SYMB),
                                                           KC_LBRACKET, KC_RBRACKET,
                                                                          MO(MDIA),
                                                         KC_SPACE, KC_BSPC, KC_LSHIFT,
  // right hand
  KC_GRAVE,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_BSPACE,
  TG(SYMB),     KC_Y,    TD(TD_U),    KC_I,    TD(TD_O),              KC_P,           KC_TRNS,
  KC_H,         KC_J,    KC_K,    KC_L,    KC_M, KC_ENTER,
  KC_END, KC_N,    KC_SCLN,    KC_COMM, KC_DOT,            KC_SLSH, KC_RSFT,
  KC_UP,        KC_DOWN, KC_LEFT, KC_RIGHT, KC_TRNS,
  KC_TRNS, KC_LCTRL,
  KC_PGUP,
  KC_PGDN, KC_TAB, KC_SPACE
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |  _   |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------|  -   |   4  |   5  |   6  |   +  |  ENTER |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_LSHIFT, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
  KC_LCTRL,    KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_UNDERSCORE,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_MINUS, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_ENTER,
  KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Lclk | MsUp | Rclk |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                    KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_WBAK
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  set_unicode_input_mode(UC_LNX);
  #ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
