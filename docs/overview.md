# Overview
This goal of this project is to create a `Linux` distribution designed for the `raspberry pi 4` board using the `Yocto` build system.

# Requirements
The system will serve two distinct tasks. It will act as a vehicle telemetry module, as well as, a body controller. In the following section, we will discuss the responsibilities in greater detail.

- ### Telemetry
The goal of the telemetry is to collect data from the vehicle, serialize it and send it to a base station, which then processes it and sends it to `grafana`.
The functioning of the base station is outside the scope of this project.
All we need to know about it, is that it collects the data we send it and processes it
in a way which makes it useful for analytics purposes.

- ### Body Controller
Some of the functionality as a **body controller** is displaying the image from external cameras onto screens inside of the cabin to act as "mirrors".

# Additional Requirements
It is important to mention that we need some additional features not strictly related to the module operation. Those features would be:

- Ability to connect over **SSH** as a convenient way to diagnose the system.
- Saving data to a removable medium, such as the SD card it's running on.