#ifndef DURATION_H
#define DURATION_H

class Duration
{
private:
    int time;
    int alarm;
    bool alarmHasBeenSet;

public:
    Duration();
    Duration(int t);
    ~Duration();
    
    int getDuration();
    bool checkAndUpdateAlarm();
    bool tick();
    bool tick(int tock);
    void setAlarm(int t);
};

#endif
