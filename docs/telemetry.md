# Telemetry

The telemetry function of the system is the most crucial aspect of it.

It is composed of multiple threads working at once in order to provide a reliable and responsive experience.

The threads can be split into two main groups:

* **Input** - Collect data from peripherals and store it in thread safe memory. Ideally each peripheral should have its own thread. Examples of peripherals include:
    - `CAN`
    - `RS485`
    - `GPS usb-cdc`
* **Output** - Take the data from thread safe memory, serialize it to a flatbuffer and either send it to a base station via `lora` or save it locally to non-volatile memory, such as a `sim` card.  