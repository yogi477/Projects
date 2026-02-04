#include <mcp_can.h>
#include <SPI.h>

const int SPI_CS_PIN = 10;
MCP_CAN CAN0(SPI_CS_PIN);

void setup() {
  Serial.begin(115200);
  if (CAN0.begin(MCP_ANY,CAN_500KBPS,MCP_16MHZ) == CAN_OK)
    Serial.println("CAN BUS UNO Initialized Successfully!");
  else
    Serial.println("CAN BUS Initialization Failed!");

  CAN0.setMode(MCP_NORMAL);
}

void loop() {
  int sensorValue = analogRead(A0);
  float temperature = (sensorValue * 4.88) / 10;  // for LM35
  byte data[2];
  int tempInt = (int)temperature;
  data[0] = tempInt >> 8;
  data[1] = tempInt & 0xFF;

  CAN0.sendMsgBuf(0x100, 0, 2, data);
  Serial.print("Sent Temperature: ");
  Serial.println(temperature);
  delay(1000);
}