/*
 * enviromentController.cpp -- A library for enviromental control.
 * Created by Johan Hägglund, 10 March 2017
 * A Fontänhuset production.
 * Released in to the public domain.
 */

class EnviromentController {
    public:
        EnviromentController(int sensPin, int rpmPin);
        float GetTemp();
        float GetHumid();
        void SetTemp(int desiredTemp);
        string ToString();
    private:
        int _sensPin;
        float _desiredTemp;
        FanController _fanController;
        DHT _dht;
}

class FanController {
    public:
        FanController(int rpmPin);
        int GetRPM();
        void SetRPM(int rpm);
    private:
        void spin(int rpm);
        int _rpmPin;
        int _rpm;
}
