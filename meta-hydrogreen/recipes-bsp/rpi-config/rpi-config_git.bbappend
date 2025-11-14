# Changes to config.txt
BOOT_DELAY = "0"
DISABLE_SPLASH = "1"
RPI_EXTRA_CONFIG:append = "dtoverlay=disable-dt\n"

# LORA settings
ENABLE_UART = "1"

# CAN settings
RPI_EXTRA_CONFIG:append = "dtoverlay=mcp2515-can0,oscillator=16000000,interrupt=25,,spimaxfrequency=1000000\n"

# RS485 settings
ENABLE_SPI_BUS = "1"
RPI_EXTRA_CONFIG:append = "dtoverlay=sc16is752-spi1,int_pin=24\n"

# TODO disable bluetooth and audio

# Waveshare display rp4 setup
HDMI_GROUP = "2"
HDMI_MODE = "87"
HDMI_CVT = "1024 600 60 6 0 0 0"
HDMI_DRIVE = "1"

# Allow higher power draw for USB devices
# MAX_USB_CURRENT = "1"
