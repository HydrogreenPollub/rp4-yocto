# Overview
This project is a `Linux` distribution designed for the `raspberry pi 4` board using the `Yocto` build system.

# Requirements
The system will serve two distinct tasks. It will act as a vehicle telemetry module, as well as, a body controller. In the following section, we will discuss the responsibilities in greater detail.

- ### Telemetry

It will collect data from the vehicle and send it to a base station.
The functioning of the base station is outside the scope of this project.
All we need to know about it, is that it collects the data we send it and processes it
in a way which makes it useful for analytics purposes.

- ### Body Controller

For now the only planned functionality as a **body controller** is displaying the image from external cameras onto screen inside of the cabin to act as "mirrors".
Depending on project deadlines this may expand to cover more features.

# Additional Requirements
It is important to mention that we need some additional features not strictly related to the module operation. Those features would be:

- Ability to connect over **SSH** as a convenient way to diagnose the system.