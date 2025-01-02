# A simple project to automate annoying stuff
###### At least the ones that are about battery powered led strips
## Why?
I made this project, because I was annoyed at having to change coin batteries in a cheap led strip I had, EVERY FEW HOURS (unless I wanted them to be dim),
So I grabbed some electronics and started experimenting, some time after I came up with this, don't ask me how, even I don't know.
## Requirements to flash to esp32:
Make sure you install this library and board:                                                                                                                                        
(tested with arduino ide V2.4.3)                                                                                                                                                                                                                                  
<img src="https://raw.githubusercontent.com/PR1NT3R/esp32-based-led-lights/refs/heads/main/docs/libraries%20and%20boards.png" height="" width="" alt="libraries and boards"></img>                                                                                

(you don't need the older board version, I'm pretty sure the newest one will work too)
## Stuff to change before flashing:
rename "config.demo.h" to "config.h", and change the values within based on your needs
## Wiring, slightly annoying but a neccesity:
In my case, the led's take in 5V but the esp32 outputs 3.3V, so I'll use an "IRLZ44N N-MOSFET"
<img src="https://raw.githubusercontent.com/PR1NT3R/esp32-based-led-lights/refs/heads/main/docs/mosfet-irlz44n-technical.jpg" height="" width="" alt="libraries and boards"></img>

based on the diagram provided above, we need to wire it up like this:
5V power source > ESP32 5V and led's positive terminal
MOSFET Gate > 1kΩ resistor > ESP32's pwm pin of your choice
MOSFET Source > Ground shared with ESP32
MOSFET Drain > led's negative terminal
## Home Assistant configuration:
You'll need the "Mosquitto broker" addon, and set up a login in it's configuration, it'll allow the esp32 and HA to communicate together
I have not figured out the discovery devices so you'll need to paste the HA config from "configuration.demo.h"
For the light card... it's in the same place as the HA config
## Contributing:
 * if you have an issue with the code or find a bug, please explain it clearly so that we all can understand it
 * in case of any feature ideas, just pop in a new discussion
## Plans for the future:
 * Static MAC adress functionality (for reserving the adress in your router) - V1.1
 * Custom "MESH" System (I have some ideas, basically plug and play sensors into any node, as I plan many other devices using simmiliar code but for different stuff, and they'd share bluetooth/wifi and sensor data)
 * Proper device discovery in Home Assistant - V1.2
 * Simple/Advanced setup via bluetooth (and a simple webpage to eaisly configure the device for people that aren't technical) - V2
 * Fully remote debbuding - V1.1 or V1.3
 * Simpler controll without the need for MQTT (exposing HTTP endpoints, mostly for very niche situations where you want to controll the device from your own local web server or something) - V2

## Issues I plan to fix asap:
 * Overloading the esp32 with MQTT data causes it to freeze for unknown durations of time, making it impossible to even send a remote reboot command to kill the command queqe. (encountered this when making low delay smooth brightness down/up controll loop in HA, possibly gonna add a built in function to only send a single command to achieve the same).
