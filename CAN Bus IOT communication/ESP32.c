//receiver node
#include <SPI.h>
#include <mcp_can.h>

#define CAN_CS 5      // Chip Select pin for MCP2515
#define CAN_INT 4     // Interrupt pin from MCP2515 to ESP32

MCP_CAN CAN(CAN_CS);

void setup() {
  Serial.begin(115200);
  // Initialize MCP2515 at 500 Kbps
  while (CAN_OK != CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ)) {
    Serial.println("CAN BUS init Failed");
    delay(100);
  }
  Serial.println("CAN BUS init OK!");
  CAN.setMode(MCP_NORMAL); // Set to normal mode to receive data
}

void loop() {
  unsigned char len = 0;
  unsigned char buf[8];
  unsigned long canId = 0;

  if (CAN_MSGAVAIL == CAN.checkReceive()) { // Check if data is received
    CAN.readMsgBuf(&len, buf);              // Read data
    canId = CAN.getCanId();                 // Get message ID

    Serial.print("Received ID: 0x");
    Serial.println(canId, HEX);

    if (canId == 0x101) { // Temperature data
      int temp = (buf[0] << 8) | buf[1];
      Serial.print("Temperature: ");
      Serial.print(temp);
      Serial.println(" °C");
    } 
    else if (canId == 0x102) { // Voltage data
      int voltage = (buf[0] << 8) | buf[1];
      Serial.print("Voltage: ");
      Serial.print(voltage / 10.0);
      Serial.println(" V");
    }
  }
}