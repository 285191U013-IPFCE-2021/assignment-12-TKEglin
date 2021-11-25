
#include "duration.h"
#include <stdio.h>
#include <assert.h>

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    Duration clock;

    if(clock.getDuration() == 0) 
        printf("\nDefault constructor and getDuration test successful.");


    Duration clock_5(5);

    if(clock_5.getDuration() == 5) 
        printf("\n\nConstructor with argument 5 test successful.");

    Duration clock_43295943(43295943);

    if(clock_43295943.getDuration() == 43295943) 
        printf("\nConstructor with argument 43295943 test successful.");

    Duration clock_0(0);

    if(clock_0.getDuration() == 0) 
        printf("\nConstructor with argument 0 test successful.");


    Duration clock_tick(0);
    assert(clock_tick.getDuration() == 0);

    clock_tick.tick(); printf("\n\ntick");
    clock_tick.tick(); printf("\n     tock");
    clock_tick.tick(); printf("\ntick");
    clock_tick.tick(); printf("\n     tock");

    printf("\n\nclock_tick.getDuration() = %d", clock_tick.getDuration());

    if(clock_tick.getDuration() == 4) printf("\nTick test successful.");


    clock_tick.tick(5); printf("\n\ntick tick tick tick tick");

    printf("\n\nclock_tick.getDuration() = %d", clock_tick.getDuration());

    if(clock_tick.getDuration() == 9) printf("\nTick(tock) test successful.");

    clock_tick.setAlarm(11);
    assert(!clock_tick.tick());
    assert(clock_tick.tick(2));

    printf("\n\nTick alarm bool return test successful");


    clock_tick.setAlarm(20);
    assert(!clock_tick.tick());
    assert(clock_tick.tick(9));

    clock_tick.setAlarm(25);
    assert(!clock_tick.tick());

    clock_tick.setAlarm(24);
    assert(clock_tick.tick());

    printf("\n\nsetAlarm test successful");


    clock_tick.setAlarm(30);
    assert(!clock_tick.tick());
    
    clock_tick.setAlarm(20);     //Since time is greater than 20, this function call should do nothing
    assert(!clock_tick.tick());  //if the alarm was changed by setAlarm, this assertion will fail
    assert(!clock_tick.tick(3));
    assert(clock_tick.tick());   //clock.tick time is now 30, the original setAlarm value

    assert(!clock_tick.tick());  //Alarm has been reset, so tick() should return false

    printf("\n\nsetAlarm precondition and checkAndUpdateAlarm test successful");

    printf("\n\n*****************************");
    printf("\n*** All tests successfull ***");
    printf("\n*****************************");

    return (0);
}