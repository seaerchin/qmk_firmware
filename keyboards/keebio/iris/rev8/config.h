// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SPLIT_HAND_PIN GP4

#define USB_VBUS_PIN GP8

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP12
#define SERIAL_USART_RX_PIN GP13
#define SERIAL_USART_PIN_SWAP

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define I2C_DRIVER I2CD2
#define I2C1_SDA_PIN GP10
#define I2C1_SCL_PIN GP11
#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0
#define MK_KINETIC_SPEED
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 160

#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
/*#define QUICK_TAP_TERM 0*/
