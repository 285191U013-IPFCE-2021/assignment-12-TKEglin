#include "duration.h"
#include <assert.h>

Duration::Duration() {
    time = 0;
    alarm = 12;
    alarmHasBeenSet = false;
}

Duration::Duration(int t) {
    assert(t >= 0);

    time = t;
    alarm = 12;
    alarmHasBeenSet = false;
}

Duration::~Duration() {

}

int Duration::getDuration() {
    return time;
}

bool Duration::checkAndUpdateAlarm() {
    if(time >= alarm) {
        alarm = 0;
        return true;
    }
    else return false;
}

bool Duration::tick() {
    time++;

    return checkAndUpdateAlarm();
}

bool Duration::tick(int tock) {
    assert(tock >= 0);

    time += tock;

    return checkAndUpdateAlarm();
}

void Duration::setAlarm(int t) {
    if(t <= time)
        return;
    else
        alarm = t;
}