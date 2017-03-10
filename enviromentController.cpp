/*
 * enviromentController.cpp -- A library for enviromental control.
 * Created by Johan Hägglund, 10 March 2017
 * A Fontänhuset production.
 * Released in to the public domain.
 */

//#include "DHT.h"


EnviromentController::EnviromentController(int sensPin, int rpmPin) {
    _sensPin = sensPin;
    pinMode(_sensPin, INPUT);
    _dht = dht(sensPin);
    _dht.Begin();
    FanController _fanController(rpmPin);

}

float EnviromentController::GetTemp() {
    delay(2000);
    float t = _dht.ReadTemprature();
    if(isnan(t)) {
        return nil;
    }
    return t;
}

void EnviromentController::SetTemp(float desiredTemp) {
    _desiredTemp = desiredTemp;
}

float EnviromentController::GetHumid() {
    delay(2000);
    float h =_dht.ReadHumidity();
    if(isnan(h)) {
        return nil;
    }
    return h;
}

FanController::FanController(int rpmPin) {
    _rpmPin = rpmPin;
}
void FanController::spin(int rpm) {
    analogWrite(_rpmPin, rpm);
}

void FanController::SetRPM(int rpm) {
    _rpm = constrain(rpm, 2500, 12000); //dummy values, figure out the correct min and max values for the specific fan
    spin(_rpm;)
}

int FanController::GetRPM() {
    return _rpm;
}
