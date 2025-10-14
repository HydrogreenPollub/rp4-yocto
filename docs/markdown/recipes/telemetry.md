The `telemetry.bb` recipe provides an application written in `C++` responsible for receiving the data from all of the peripherals, as well as for sending it to the base station.

The source code of this application is stored in a [separate repository](https://github.com/HydrogreenPollub/rp4-telemetry).

Logs from the application are stored in `/home/root/logs/telemetry_<timestamp>.log`.

The application is multithreaded. Each peripheral has a separate thread. All of the **input** threads save their data to a shared data structure, which is then serialized to a **cap'n proto buffer** and transmitted by the **output** threads.

The serialization library that we settled on is a fork of **cap'n proto**.