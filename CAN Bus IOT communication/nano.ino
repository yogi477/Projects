#include <mcp_can.h>
#include <SPI.h>

const int SPI_CS_PIN = 10;
MCP_CAN CAN0(SPI_CS_PIN);

void setup() {
  Serial.begin(115200);
  if (CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK)
    Serial.println("CAN BUS NANO Initialized Successfully!");
  else
    Serial.println("CAN BUS Initialization Failed!");

  CAN0.setMode(MCP_NORMAL);
}

void loop() {
  int sensorValue = analogRead(A1);
  float voltage = (sensorValue * 5.0) / 1023.0;
  byte data[2];
  int voltInt = (int)(voltage * 100); // scaled to 2 decimals
  data[0] = voltInt >> 8;
  data[1] = voltInt & 0xFF;

  byte sentmsg = CAN0.sendMsgBuf(0x200, 0, 2, data);
  Serial.print("Sent Voltage: ");
  Serial.println(voltage);
  if(sentmsg == CAN_OK)
    Serial.println("Frame accepted");
  else
    Serial.println("Frame rejected");
  delay(1000);
}










// // #include <SPI.h>
// // #include <mcp_can.h>

// // #define CAN_CS 10

// // MCP_CAN CAN(CAN_CS);

// // void setup() {
// //   Serial.begin(115200);
// //   delay(1000);

// //   Serial.println("MCP2515 Loopback Test...");

// //   if (CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK) {
// //     Serial.println("MCP2515 Init OK");
// //   } else {
// //     Serial.println("MCP2515 Init Fail");
// //     while (1);
// //   }
// // }
// //   // Set Loopback Mode
// //   CAN.setMode(MCP_LOOPBACK);

// //   Serial.println("Loopback Mode Enabled");
// // }

// // void loop() {
// //   // SEND
// //   byte data[2] = {0x11, 0x22};
// //   CAN.sendMsgBuf(0x200, 0, 2, data);
// //   Serial.println("Sent CAN Frame: 11 22");

// //   delay(200);

// //   // RECEIVE
// //   if (!digitalRead(2)) { // INT pin optional, or skip check
// //     long unsigned int rxId;
// //     unsigned char len;
// //     unsigned char buf[8];

// //     CAN.readMsgBuf(&rxId, &len, buf);

// //     Serial.print("Received ID: 0x");
// //     Serial.println(rxId, HEX);

// //     Serial.print("Data: ");
// //     for (int i = 0; i < len; i++) {
// //       Serial.print(buf[i], HEX);
// //       Serial.print(" ");
// //     }
// //     Serial.println();
// //   }

// //   delay(1000);
// // }

