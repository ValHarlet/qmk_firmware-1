// Copyright 2022 Valentin Harlet 
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include <keymap_french.h>

//#define ENCODER_MAP_ENABLE

void keyboard_post_init_user(void) {
	autoshift_disable();
}

enum layers {
    _QWERTY,
    _NUM,
    _FN,
    _SYS,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_NUMERIC,
    KC_FUNCTION,
	KC_SYSTEM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
//      											     				_______       _______
// .----------.----------.----------.----------.----------.----------. /       \     /       \ .----------.----------.----------.----------.----------.----------.
// |   &      |    é     |    "    |    '    |    (     |    -     |(  Media  )   (  Media  )|    è     |    _     |    ç     |    à     |    )     |    =     |
      FR_AMPR, 	 FR_EACU, FR_DQUO,   FR_QUOT,	 FR_LPRN,  FR_MINS,  	KC_MPLY,      KC_MPLY,    FR_EGRV,  FR_UNDS, FR_CCED, FR_AGRV, FR_RPRN,    FR_EQL,
// |----------+----------+----------+----------+----------+----------| \_______/     \_______/ |----------+----------+----------+----------+----------+----------|
// |   Tab    |    A     |    Z     |    E     |    R     |    T     |                         |    Y     |    U     |    I     |    O     |    P     |   [ (Å)  |
      KC_TAB, 	 FR_A, 	    FR_Z,      FR_E,      FR_R,      FR_T,                     		       FR_Y,     FR_U,      FR_I,      FR_O,       FR_P,    KC_LBRC,
// |----------+----------+----------+----------+----------+----------|                         |----------+----------+----------+----------+----------+----------|
// |  Capslk  |    Q     |    S     |    D     |    F     |    G     |                         |    H     |    J     |    K     |    L     |  M       |  ù        |
  KC_LEFT_SHIFT, 	 FR_Q, 	    FR_S,       FR_D,      FR_F,    FR_G,                     			      FR_H, 	  FR_J,      FR_K,       FR_L,    FR_M,     FR_UGRV,
// |----------+----------+----------+----------+----------+----------+-----------. .-----------+----------+----------+----------+----------+----------+----------|
// | <-  Ctrl |    Z     |    X     |    C     |    V     |    B     |   Down    | |    Up     |    N     |    ,     |    ;     |    :     |    !     | *         |
LCTL_T(KC_LEFT), FR_W, 	    FR_X,      FR_C,      FR_V,       FR_B,     FR_LABK,      KC_ESC,     FR_N,	FR_COMM,    FR_SCLN,   FR_COLN,    FR_EXLM,      FR_ASTR,
// '----------'----------'----------+----------+----------+----------+-.---------' '---------.-+----------+----------+----------+----------'----------'----------'
//                                	|   Win    |   Lower  |   Alt    |/  Space  /   \  Enter  \|   AltGr  |  Raise   |   Bksp   |
//									|		   |	      |	         |  Shift  /     \  Shift  |          |          |          |
                                      KC_LGUI,   TG(_FN),   KC_LALT, LSFT_T(KC_SPC),RSFT_T(KC_ENT), KC_RALT, TG(_NUM), MT(MOD_RGUI,KC_BSPC)
//                                  '----------'----------'----------'--------'       '--------'----------'----------'----------'
),

//      											     				_______       _______
// .----------.----------.----------.----------.----------.----------. /       \     /       \ .----------.----------.----------.----------.----------.----------.
// |   Esc    |    1     |    2     |    3     |    4     |    5     |(  Media  )   (  Media  )|    6     |    7     |    8     |    9     |    0     |    -     |
// |----------+----------+----------+----------+----------+----------| \_______/     \_______/ |----------+----------+----------+----------+----------+----------|
// |   Tab    |    Q     |    W     |    E     |    R     |    T     |                         |    Y     |    U     |    I     |    O     |    P     |   [ (Å)  |
// |----------+----------+----------+----------+----------+----------|                         |----------+----------+----------+----------+----------+----------|
// |  Capslk  |    A     |    S     |    D     |    F     |    G     |                         |    H     |    J     |    K     |    L     |  ; (Ö)   |   ' (Ä)  |
// |----------+----------+----------+----------+----------+----------+-----------. .-----------+----------+----------+----------+----------+----------+----------|
// | <-  Ctrl |    Z     |    X     |    C     |    V     |    B     |   Down    | |    Up     |    N     |    M     |    ,     |    .     |    /     | Ctrl  -> |
// '----------'----------'----------+----------+----------+----------+-.---------' '---------.-+----------+----------+----------+----------'----------'----------'
//                                	|   Win    |   Lower  |   Alt    |/  Space  /   \  Enter  \|   AltGr  |  Raise   |   Bksp   |
//									|		   |	      |	         |  Shift  /     \  Shift  |          |          |          |
//                                  '----------'----------'----------'--------'       '--------'----------'----------'----------'


[_NUM] = LAYOUT(
  FR_1,   FR_2,   FR_3,    FR_4,   FR_5,   FR_6,  _______,      _______, FR_7,    FR_8,    FR_9,    FR_0, FR_DEG, FR_PLUS,
  _______, XXXXXXX,   KC_UP,  XXXXXXX, XXXXXXX, XXXXXXX,                         KC_HASH,    KC_KP_4,    KC_KP_5,    KC_KP_6, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_LBRC, KC_RBRC,                         KC_AMPR,    KC_KP_1,    KC_KP_2,    KC_KP_3, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, KC_PAST,  KC_PPLS, KC_PSLS,  KC_EQL, _______,       _______,  KC_DLR,    KC_KP_0, KC_KP_DOT, KC_COLN, KC_PMNS, _______,
							  _______, _______, _______, _______,       _______, _______, _______, _______ 
),

[_FN] = LAYOUT(
//      											     				_______       _______
// .----------.----------.----------.----------.----------.----------. /       \     /       \ .----------.----------.----------.----------.----------.----------.
// |   Esc    |    1     |    2     |    3     |    4     |    5     |(  Media  )   (  Media  )|    6     |    7     |    8     |    9     |    0     |    -     |
	    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6, _______,      _______,        KC_F7,    KC_F8,      KC_F9,     KC_F10,    KC_F11,   KC_F12, 
// |----------+----------+----------+----------+----------+----------| \_______/     \_______/ |----------+----------+----------+----------+----------+----------|
// |   Tab    |    Q     |    W     |    E     |    R     |    T     |                         |    Y     |    U     |    I     |    O     |    P     |   [ (Å)  |
     _______,   _______,   _______,   _______,   _______,   _______,                             _______,   _______,   _______,   _______,   _______,   _______,
// |----------+----------+----------+----------+----------+----------|                         |----------+----------+----------+----------+----------+----------|
// |  Capslk  |    A     |    S     |    D     |    F     |    G     |                         |    H     |    J     |    K     |    L     |  ; (Ö)   |   ' (Ä)  |
     _______,   _______,   _______,   FR_DLR,   _______,   _______,                             _______,   _______,   _______,   _______,   _______,   _______,
// |----------+----------+----------+----------+----------+----------+-----------. .-----------+----------+----------+----------+----------+----------+----------|
// | <-  Ctrl |    Z     |    X     |    C     |    V     |    B     |   Down    | |    Up     |    N     |    M     |    ,     |    .     |    /     | Ctrl  -> |
     _______,   _______,   _______,   _______,   _______,   _______,    _______,      _______,   _______,   _______,   _______,   _______,   _______,   _______,
// '----------'----------'----------+----------+----------+----------+-.---------' '---------.-+----------+----------+----------+----------'----------'----------'
//                                	|   Win    |   Lower  |   Alt    |/  Space  /   \  Enter  \|   AltGr  |  Raise   |   Bksp   |
//									|		   |	      |	         |  Shift  /     \  Shift  |          |          |          |
            					      _______,   _______,   _______,  _______,         _______,  _______,   _______,   _______
//                                  '----------'----------'----------'--------'       '--------'----------'----------'----------'
),

[_SYS] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX ,  XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_SAI, RGB_TOG,
  QK_BOOT, XXXXXXX, KC_QWERTY, XXXXXXX, XXXXXXX, KC_ASTG,                       XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD, RGB_SAD, RGB_M_P,
  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_CAPS,                       XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_VAI, RGB_M_B,
  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_VAD, RGB_M_R,
								_______, _______, _______, _______,     _______, _______, _______, _______  \
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [_FN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_SYS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) }
};
#endif


