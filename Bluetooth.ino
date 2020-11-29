//// communication bluetooth

void initialiserBluetooth(){
  if(!SerialBT.begin("Sapin")){
    Serial.println("An error occurred initializing Bluetooth");
  }
}
