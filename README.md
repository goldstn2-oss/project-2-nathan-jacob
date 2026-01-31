Nathan Goldstein and Jacob Zeltser

This is a simulated safety system designed for under 21 Drivers Ed students who need to have direct supervision per New York's driving regulations.
By using a light indicator and buzzer it ensures an instuctor is present and buckled before the cars ignition can be pressed. If the cars ignition is pressed before 
these requirements are met, a buzzer goes off, however the user can disable the alarm by having both driver and passenger seated and buckled (turning back on the ligth indicator).
Once the ignition is on, for safety and usability we added a headlight system. This headlight system has an off setting, an on setting, and an auto setting. The auto setting turns
on the lights when it is dark out, turns off the lights when it is light out, and when it is somewhere inbetween (midlight mode) it maintains its previous state). Finally, when 
the headlights are on we added a switch to turn on the high beams.

Starting Repository
[(https://github.com/goldstn2-oss/Project-1-218-N-M)]

+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                       Table of Testing Results For the Ignitions                                                                                       |
+---------------------------------------------------------+-----------------------------------------------------------------------+--------------------------------------------------------------------------------------+
| Specification                                           | |       Test Process                                                  | Results                                                                              |
+---------------------------------------------------------+-----------------------------------------------------------------------+--------------------------------------------------------------------------------------+
| Turn Green LED on                                       | 4 total switches:(DS,PS,DSSB,PSSB)                                    | 1.'Welcome to enhanced alarm system model 218-W26'                                   |
| -->Igntion is ableto be pushed safely                   | 1. All switches on                                                    | 2. No Green light for All cases. Only special case is no driver                      |
|                                                         | 2. All switches but 1                                                 | --> the welcome message not printed                                                  |
|                                                         | 3. No buttons pressed                                                 | 3. No Green light or welcome message                                                 |
+---------------------------------------------------------+-----------------------------------------------------------------------+--------------------------------------------------------------------------------------+
| Try to start the engine by pressing the ignition button | 1. When all the switches are on                                       | 4 Error Message:                                                                     |
|                                                         | ( green led is on and the welcome                                     |    a. Driver seat is not occupies                                                    |
|                                                         | message is up)                                                        |    b. Passenger seat is not occupied                                                 |
|                                                         |                                                                       |    c. Driver seatbelt not fastened                                                   |
|                                                         | 2. When 1 or multiple of the                                          |    d passenger seatbelt not fastened                                                 |
|                                                         | switches is off                                                       |                                                                                      |
|                                                         | (green light is off and maybe no                                      | 1. Red Light turns on, 'Engine started', the switches states                         |
|                                                         | welcome message if driver isn't                                       | don't change anything about the system.                                              |
|                                                         | seated)                                                               |                                                                                      |
|                                                         |                                                                       | 2. Error message a, b, c, and/or d is printed based on which                         |
|                                                         | 3. When 1 or multiple switches are off                                | switch is not on. The buzzer goes off. 'Ignition Inhibited' is                       |
|                                                         | (green light is off and maybe no welcome message if driver isn't      | printed.                                                                             |
|                                                         | seated). The ignition is pressed, then the switches not on are turned |                                                                                      |
|                                                         | on again. Finally, the ignition is pressed again.                     | 3. Error message a, b, c, and/or d is printed based on which switch is not on.       |
|                                                         |                                                                       | The buzzer goes off. 'Ignition Inhibited' is printed.                                |
|                                                         |                                                                       | Then, when the switches are turned back on that were                                 |
|                                                         |                                                                       | previously off, the green light turns back on (the welcome message                   |
|                                                         |                                                                       | is printed if the driver hasn't already sat down), the buzzer then turns off.        |
|                                                         |                                                                       | When the ignition button is pressed again --> Red Light turns on, 'Engine started',  |
|                                                         |                                                                       | the switches states don't change anything about the system.                          |
+---------------------------------------------------------+-----------------------------------------------------------------------+--------------------------------------------------------------------------------------+
| Turning off the engine by pressing the ignition button  | 1. All switches are still in the on position                          | 1. Red light turns off, 'Engine Off!'. Green light turns back on indicating it       |
|                                                         |                                                                       | is safe to turn the car back on.                                                     |
|                                                         | 2. 1 of the 4 switches is off.                                        |                                                                                      |
|                                                         | This may be because the passenger got out for                         | 2. Red light turns off, 'Engine Off!'. Green light does not turn back on.            |
|                                                         | example.                                                              |                                                                                      |
+---------------------------------------------------------+-----------------------------------------------------------------------+--------------------------------------------------------------------------------------+








