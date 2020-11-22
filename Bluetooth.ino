// communication bluetooth

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// https://www.uuidgenerator.net/
BLECharacteristic *pCharacteristic;
bool deviceConnected = false;
#define SERVICE_UUID "888a44c8-1296-11ea-8d71-362b9e155667"
// UART service UUID
#define CHARACTERISTIC_UUID_RX "888a44c9-1296-11ea-8d71-362b9e155667"
#define CHARACTERISTIC_UUID_TX "888a44d0-1296-11ea-8d71-362b9e155667"

// callback serveur
class ServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};


// callbacks characteristics
class CharacteristicsCallbacks: public BLECharacteristicCallbacks {
    
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rxValue = pCharacteristic->getValue();

      if (rxValue.length() > 0) {
        Serial.println("*********");
        Serial.print("Received Value: ");


        for (int i = 0; i < rxValue.length(); i++) {
          Serial.print(rxValue[i]);
        }
        
        Serial.println();

        selectedEffect = atoi(rxValue.c_str());
        
      }
    }
};

void initialiserBluetooth()
{
  // Create the BLE Device
  BLEDevice::init("Sapin de noel"); // Give it a name

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new ServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID_TX,
                      BLECharacteristic::PROPERTY_NOTIFY
                    );
                      
  pCharacteristic->addDescriptor(new BLE2902());

  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID_RX,
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setCallbacks(new CharacteristicsCallbacks());

  // Start the service
  pService->start();

  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Attente d un client");

}
