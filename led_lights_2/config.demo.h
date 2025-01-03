// default led state
bool default_state = true;
int brightness = 255; // 0-255
bool lightOn = default_state; // ignore this

// WiFi credentials
const char* ssid = "WIFI_NAME";
const char* password = "WIFI_PASSWORD";

// OTA settings
bool otaEnabled = true;
const char* otaPassword = "INSECURE_PASSWORD";

// mDNS name for OTA identification (the name that appears in the arduino IDE)
const char* mdnsName = "esp32-led-lights";

// MQTT Broker settings
const char* mqtt_server = "192.168.x.x"; // IP of your Home Assistant or MQTT Broker
const int mqtt_port = 1883;                // Default MQTT port
const char* mqtt_user = "USERNAME";    // MQTT Username
const char* mqtt_password = "1234";        // MQTT Password

// MQTT Topics
const char* brightness_command_topic = "room/led_strip_brightness";
const char* state_announce_topic = "room/led_strip_state_announce";
const char* led_state_topic = "room/led_strip_state";
const char* reboot_topic = "room/led_strip_reboot";

// HA Self Healing (to prevent any random issues and all, just make an automation to reboot), disabling this stops listening to the remote reboot topic
#define SELF_HEALING_REBOOT
const int self_healing_default_timer = 1000; // in milliseconds

// Define PWM properties
const int pwmPin = 13; // GPIO pin for PWM (can be changed as needed)
const int pwmChannel = 0; // PWM channel number (ESP32 supports 16 channels)
const int pwmFrequency = 5000; // PWM frequency (5 kHz is suitable for LED dimming)
const int pwmResolution = 8; // 8-bit resolution (0-255)


// DHT22 sensor shenanigans happen here
//#define DHT22_CONNECTED // if commented out, the 2 other ones below will be off as well

// DHT22 sensor shenanigans happen here
#define DHT22_TEMP // uncomment if you want temp readings (off by default since the main define is commented out)
#define DHT22_HUMIDITY // uncomment if you want humidity readings (off by default since the main define is commented out)
#define DHT22_PIN 14 // (off by default since the main define is commented out)
#define DHT22_UPDATE_RATE 5000 // in milliseconds
const char* dht22_humidity_topic = "room/humidity";
const char* dht22_temp_topic = "room/temperature";

/*
HOME ASSISTANT CONFIGURATION (I have not yet figured out the device discovery thing)

mqtt:
  light:
    - unique_id: "1234" # change this
      name: "Led Strip"
      command_topic: "room/led_strip_brightness"
      state_topic: "room/led_strip_state_announce"
      payload_on: "ON"
      payload_off: "OFF"
      brightness_command_topic: "room/led_strip_brightness"
      brightness_state_topic: "room/led_strip_state"
      brightness_value_template: "{{ value | int }}"
      
      device:
        name: "ESP32 Led Strip"
        identifiers: [
            "led_strip",
            "esp32",
            "esp32_led_strip",
            "esp32 led strip",
            "led strip",
            "led",
          ]
        manufacturer: ""
        model: ""
        sw_version: "1.0"
        via_device: "mqtt"

  # \/ OPTIONAL (Paste theese in for DHT22 functionality, you can only paste either temperature or humidity blocks and it will still work) \/
  sensor:
    - unique_id: "dht22_temperature"
      name: "DHT22 Temperature"
      state_topic: "room/dht22_temperature"
      unit_of_measurement: "°C"
      device_class: "temperature"
      value_template: "{{ value | float }}"
      device:
        name: "Room temperature"
        identifiers:
          [
            "led_strip",
            "esp32",
            "esp32_led_strip",
            "esp32 led strip",
            "led strip",
            "led",
            "strip",

            "DHT22",
            "DHT",
            "TEMP"
          ]
        manufacturer: ""
        model: ""
        sw_version: "1.0"
        via_device: "mqtt"

    - unique_id: "dht22_humidity"
      name: "DHT22 Humidity"
      state_topic: "room/dht22_humidity"
      unit_of_measurement: "%"
      device_class: "humidity"
      value_template: "{{ value | float }}"
      device:
        name: "My room humidity"
        identifiers:
          [
            "led_strip",
            "esp32",
            "esp32_led_strip",
            "esp32 led strip",
            "led strip",
            "led",
            "strip",

            "DHT22",
            "DHT",
            "HUMIDITY"
          ]
        manufacturer: ""
        model: ""
        sw_version: "1.0"
        via_device: "mqtt"
*/



/*
HOME ASSISTANT LIGHT CARD CONFIGURATION (I use "Big Slider Card" from the HACS store, config below)

type: custom:big-slider-card
entity: light.led_strip
name: Led Strip
attribute: brightness
transition: 0.3
height: 80
background_color: "#1c1c1c"
text_color: "#ff"
border_color: "#1c1c1c"
border_radius: 10px
border_width: 5px
icon_color: "#2c4244"
colorize: true
icon: mdi:lamp
show_percentage: true
bold_text: true
min: 1
max: 100
hold_time: 600
settle_time: 3000
tap_action:
  action: call-service
  service: light.toggle
  data:
    entity_id: light.led_strip
hold_action:
  action: more-info
  data:
    entity_id: light.led_strip
*/