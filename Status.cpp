#include "Status.h"

struct Status{
    double temperature;
    double humidity;
}

void Status::runSensor(){

    Logging logging;
    Sensing sensing;
    Status status;

    bool isReadTemp;
    bool isReadHumid;

    int count = 0;

    while(1){

        isReadTemp = sensing.readTemperature(status.temperature);
        isReadHumid = sensing.readHumidity(status.humidity);

        //バッファに一時格納
        if(isReadTemp && isReadHumid){
            statusVector_.push_back(status);
        }

        //データベースにstatusを書き込み指示
        if(count >= 10){
            logging.writeLog(status);
        }
        

        count++ ;
    }
}