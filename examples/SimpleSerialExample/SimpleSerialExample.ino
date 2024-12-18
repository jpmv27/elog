#include <Elog.h>
#define MYLOG 0
#define RANDOM 1

void randomLog()
{
    if (random(0, 5) == 0) {
        Logger.log(RANDOM, ELOG_LEVEL_WARNING, "Random message");
    }
}

void setup()
{
    Serial.begin(115200);
    Logger.registerSerial(MYLOG, ELOG_LEVEL_DEBUG, "tst"); // We want messages with DEBUG level and lower
    Logger.registerSerial(RANDOM, ELOG_LEVEL_WARNING, "rnd"); // We want messages with WARNING level and lower
}

void loop()
{
    for (int i = 0; i < 1000; i++) {
        Logger.log(MYLOG, ELOG_LEVEL_DEBUG, "Counter is %d", i);
        if (i % 10 == 0) {
            Logger.log(MYLOG, ELOG_LEVEL_NOTICE, "Counter divisible by 10");
        }
        randomLog();
        delay(500);
    }
}
