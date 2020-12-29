# naive-eavesdropper
Read raw digital signal from Arduino digital input.

There's plenty of libraries with exellent capabilities to read, send and decode digital signals, but what they offer is often too much. They are also usually specialized for radio, infrared or any other kind of sensors, which makes you reload the program every time the sensor is changed.

Here I propose a minimalistic reader class that reads raw data from selected pin and sends it to serial port. All the signal parsing and interpretation happens outside, in another program (possibly written in a more friendly language like python).
