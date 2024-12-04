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

// Define PWM properties
const int pwmPin = 13; // GPIO pin for PWM (can be changed as needed)
const int pwmChannel = 0; // PWM channel number (ESP32 supports 16 channels)
const int pwmFrequency = 5000; // PWM frequency (5 kHz is suitable for LED dimming)
const int pwmResolution = 8; // 8-bit resolution (0-255)


/*
HOME ASSISTANT CONFIGURATION (I have not yet figured out the device discovery thing, so it's manual)

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
            "led_strip_5002",
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
*/