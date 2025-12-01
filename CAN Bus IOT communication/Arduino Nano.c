//Transmitter node 2
#include <mcp_can.h>
#include <SPI.h>

const int SPI_CS_PIN = 10;
MCP_CAN CAN(SPI_CS_PIN);

void setup() {
  Serial.begin(9600);
  if (CAN.begin(MCP_ANY, 500000, MCP_8MHZ) == CAN_OK)
    Serial.println("CAN BUS NANO Initialized Successfully!");
  else
    Serial.println("CAN BUS Initialization Failed!");

  CAN.setMode(MCP_NORMAL);
}

void loop() {
  int sensorValue = analogRead(A1);
  float voltage = (sensorValue * 5.0) / 1023.0;
  byte data[2];
  int voltInt = (int)(voltage * 100); // scaled to 2 decimals
  data[0] = voltInt >> 8;
  data[1] = voltInt & 0xFF;

  CAN.sendMsgBuf(0x200, 0, 2, data);
  Serial.print("Sent Voltage: ");
  Serial.println(voltage);
  delay(1000);
}