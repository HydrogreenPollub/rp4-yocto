# Telemetry

The telemetry function of the system is the most crucial aspect of it.

It is composed of multiple threads working at once in order to provide a reliable and responsive experience.

The threads can be split into two main groups:

* **Inputs**
    - `CAN` - Used to receive data from the steering wheel.
    - `RS485` - Used for receiving telemetry data from the **master** board.
    - `GPS usb-cdc` - Used to read the `NMEA` gps position and time.
* **Output**
    - `CAN` - Used to output the data to a steering wheel display.
    - `LORA` - Used to send the data to a base station.
    - `CSV` - Stored on SD card. Used to store data locally in case of connectivity issues.
