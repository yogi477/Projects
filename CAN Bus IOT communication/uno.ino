#include <mcp_can.h>
#include <SPI.h>

const int SPI_CS_PIN = 10;
MCP_CAN CAN(SPI_CS_PIN);

void setup() {
  Serial.begin(9600);
  if (CAN.begin(MCP_ANY, 500000, MCP_8MHZ) == CAN_OK)
    Serial.println("CAN BUS UNO Initialized Successfully!");
  else
    Serial.println("CAN BUS Initialization Failed!");

  CAN.setMode(MCP_NORMAL);
}

void loop() {
  int sensorValue = analogRead(A0);
  float temperature = (sensorValue * 4.88) / 10;  // for LM35
  byte data[2];
  int tempInt = (int)temperature;
  data[0] = tempInt >> 8;
  data[1] = tempInt & 0xFF;

  CAN.sendMsgBuf(0x100, 0, 2, data);
  Serial.print("Sent Temperature: ");
  Serial.println(temperature);
  delay(1000);
}