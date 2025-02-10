# Changes to config.txt
ENABLE_UART = "1"
BOOT_DELAY = "0"
DISABLE_SPLASH = "1"

# CAN settings
ENABLE_SPI_BUS = "1"
RPI_EXTRA_CONFIG += "dtoverlay=mcp2515-can0,ocillator=12000000,interrupt=25,spimaxfrequency=2000000"

# Waveshare display rp4 setup
HDMI_GROUP = "2"
HDMI_MODE = "87"
HDMI_CVT = "1024 600 60 6 0 0 0"
HDMI_DRIVE = "1"

# Allow higher power draw for USB devices
# MAX_USB_CURRENT = "1"