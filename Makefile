#
# embedXcode
# ----------------------------------
# Embedded Computing on Xcode
#
# Copyright © Rei VILO, 2010-2014
# All rights reserved
# http://embedxcode.weebly.com
#
# Last update: May 08, 2014 release 156


# Libraries
# ----------------------------------
# Declare application Arduino/chipKIT/Digispark/Energia/Maple/Microduino/Teensy/Wiring
# and user's libraries used 
# Short-listing libraries speeds-up building
# Typing = 0 takes none (default for application and user)
# Otherwise, leaving empty considers all (default for local)

# List application Arduino/chipKIT/Digispark/Energia/Maple/Microduino/Teensy/Wiring libraries here
# default = 0 = none
#
# ARDUINO = EEPROM SoftwareSerial SPI Wire SPI Wire Audio 
#	Bridge Esplora Ethernet Firmata GSM LiquidCrystal 
#	Robot_Control Robot_Motor RobotIRremote Scheduler SD Servo 
#	SpacebrewYun Stepper Temboo TFT USBHost WiFi 
#
APP_LIBS_LIST = 0

# List user's libraries here 
# default = 0 = none
#
# USER = _Stub AD7746 Adafruit_GFX Adafruit_TFTLCD ADS1115 
#	ADXL345 ADXL_345 AK8975 avr BMA150 BMP085 CalLib DS1307 
#	DueFlash EEPROM Ethernet FastSPI_LED Fat16 HMC5843 HMC5883L 
#	I2Cdev i2cdevlib IAQ2000 ITG3200 Kalman L3G4200D 
#	Libraries_for_Music_Shield_20120619 LM73 MotionDriver MPR121 MPU6050 MPU9150Lib 
#	MusicShieldNewSDLib NewSoftSerial NewSPI parallaxLCD PololuLedStrip 
#	RTIMULib RTIMULib_Arduino SSD1308 Streaming TCA6424A TFT TinyGPS 
#	TouchScreen 
#
USER_LIBS_LIST = 0

# List local libraries here
# default = empty = all
#
LOCAL_LIBS_LIST =

# List core, application and user's libraries to be excluded
# For example, WiFi may crash on Arduino 1.0.2, Esplora on Arduino 1.0.3, Firmata on Teensy 3.0,
#   OneWire on MPIDE 0023, HardwareSerial may conflict with MarlinSerial
#
#EXCLUDE_LIBS = Firmata WiFi Esplora OneWire Robot_Control Robot_Control/utility Robot_Motor


# Warning options
# ----------------------------------
# Contrary to errors, warnings don't stop compilation but they point at possible cause of errors.
# For example, unused variables with unused-variable.
#
# If 0, no warnings
# If empty, all warnings, same as WARNING_OPTIONS = all
# WARNING_OPTIONS = all no-missing-braces no-conversion-null no-pointer-arith
# WARNING_OPTIONS = unused-variable unused-function unused-label unused-value no-conversion-null no-pointer-arith
#
WARNING_OPTIONS = 0


# Applications path folder
# ----------------------------------
# Path to the folder where the IDEs are located
# By default, = /Applications
#
APPLICATIONS_PATH = /Applications


# Serial console for Fast target
# ----------------------------------
# = 0 or = empty or comment: open serial console
# = 1: don't open serial console
#
NO_SERIAL_CONSOLE =


# Teensy USB options
# ----------------------------------
# TEENSY_USB = USB_SERIAL USB_HID USB_SERIAL_HID USB_DISK USB_DISK_SDFLASH USB_MIDI USB_RAWHID USB_FLIGHTSIM
# TEENSY_LAYOUT = LAYOUT_US_ENGLISH LAYOUT_CANADIAN_FRENCH LAYOUT_CANADIAN_MULTILINGUAL LAYOUT_DANISH
#   LAYOUT_FINNISH LAYOUT_FRENCH LAYOUT_FRENCH_BELGIAN LAYOUT_FRENCH_SWISS LAYOUT_GERMAN LAYOUT_GERMAN_MAC
#   LAYOUT_GERMAN_SWISS LAYOUT_ICELANDIC LAYOUT_IRISH LAYOUT_ITALIAN LAYOUT_NORWEGIAN
#   LAYOUT_PORTUGUESE LAYOUT_PORTUGUESE_BRAZILIAN LAYOUT_SPANISH LAYOUT_SPANISH_LATIN_AMERICA
#   LAYOUT_SWEDISH LAYOUT_TURKISH LAYOUT_UNITED_KINGDOM LAYOUT_US_INTERNATIONAL
#
TEENSY_USB = USB_SERIAL
TEENSY_LAYOUT = LAYOUT_US_ENGLISH


# Parameters
# ----------------------------------
# Xcode takes BOARD_TAG and BOARD_PORT from the .xcconfig file
# For other IDEs than Xcode,

# BOARD_TAG is required
# If not defined, error BOARD_TAG not defined
#
#BOARD_TAG  = mega2560

# BOARD_PORT is optional
# If not defined, BOARD_PORT = /dev/tty.usb* (default)
#
BOARD_PORT = /dev/tty.usb*

# Xcode takes SKETCHBOOK_DIR from preferences.txt
# If not defined, each IDE has its own SKETCHBOOK_DIR (default)
# To share the same SKETCHBOOK_DIR along all IDEs, define
#
#SKETCHBOOK_DIR =

# SERIAL_BAUDRATE for the serial console, 9600 by default
# Uncomment and specify another speed
#
#SERIAL_BAUDRATE = 19200


# Miscellaneous
# ----------------------------------
# Manage path with space in the name
#
CURRENT_DIR   := $(shell pwd)
CURRENT_DIR   := $(shell echo '$(CURRENT_DIR)' | sed 's/ /\\\ /g')

# C-compliant project name
#
PROJECT_NAME_AS_IDENTIFIER = _0140803_invertedPendulem_robot

MAKEFILE_PATH  = $(CURRENT_DIR)/Makefiles
UTILITIES_PATH = $(CURRENT_DIR)/Utilities

include $(MAKEFILE_PATH)/Step1.mk


