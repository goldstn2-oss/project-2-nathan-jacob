Nathan Goldstein and Jacob Zeltser

This is a simulated safety system designed for under 21 Drivers Ed students who need to have direct supervision per New York's driving regulations.
By using a light indicator and buzzer it ensures an instuctor is present and buckled before the cars ignition can be pressed. If the cars ignition is pressed before 
these requirements are met, a buzzer goes off, however the user can disable the alarm by having both driver and passenger seated and buckled (turning back on the ligth indicator).
Once the ignition is on, for safety and usability we added a headlight system. This headlight system has an off setting, an on setting, and an auto setting. The auto setting turns
on the lights when it is dark out, turns off the lights when it is light out, and when it is somewhere inbetween (midlight mode) it maintains its previous state). Finally, when 
the headlights are on we added a switch to turn on the high beams.

Starting Repository
[(https://github.com/goldstn2-oss/Project-1-218-N-M)]

+--------------------------------------------------------------------------------------+
|                      Table of Testing Results For the Ignitions                      |
+----------------------+---------------------------+-----------------------------------+
| Specification        | Test Process              | Results                           |
+----------------------+---------------------------+-----------------------------------+
| Turn Green LED on    | 4 total switches:         | 1.'Welcome to                     |
| -->Igntion is able   | (DS,PS,DSSB,PSSB)         | enhanced                          |
| to be pushed safely  | 1. All switches on        | alarm system                      |
|                      | 2. All switches but 1     | model 218-W26'                    |
|                      | 3. No buttons pressed     | 2. No Green light                 |
|                      |                           | for All cases.                    |
|                      |                           | Only special case                 |
|                      |                           | is no driver                      |
|                      |                           | --> the welcome                   |
|                      |                           | message not printed               |
|                      |                           | 3. No Green light                 |
|                      |                           | or welcome message                |
+----------------------+---------------------------+-----------------------------------+
| Try to start the     | 1. When all the           | 4 Error Message:                  |
| engine               | switches are on           |    a. Driver seat                 |
| by pressing          | ( green led is on         |       is not occupies             |
| the ignition button  | and the welcome           |    b. Passenger seat              |
|                      | message is up)            |       is not occupied             |
|                      |                           |    c. Driver seatbelt             |
|                      | 2. When 1 or              |       not fastened                |
|                      | multiple of the           |    d Passenger seatbelt           |
|                      | switches is off           |      not fastened                 |
|                      | (green light is off       |                                   |
|                      | and no                    | 1. Red Light turns on,            |
|                      | welcome message           | 'Engine started',                 |
|                      | if driver isn't           | the switches states               |
|                      | seated).                  | don't change                      |
|                      |                           | anything about the system.        |
|                      | 3. When 1 or multiple     |                                   |
|                      | switches are off          | 2. Error message                  |
|                      | (green light is off       | a, b, c, and/or d is              |
|                      | and maybe no welcome      | printed based on which            |
|                      | message if driver         | switch is not on.                 |
|                      | isn't seated).            | The buzzer goes off.              |
|                      | The ignition is pressed,  | 'Ignition Inhibited'              |
|                      | then the switches         | is printed.                       |
|                      | not on are turned         |                                   |
|                      | on again. Finally,        | 3. Error message a, b, c,         |
|                      | the ignition              | and/or d is printed               |
|                      | is pressed again.         | based on which switch is not on.  |
|                      |                           | The buzzer goes off.              |
|                      |                           | 'Ignition                         |
|                      |                           | Inhibited' is printed.            |
|                      |                           | Then, when the switches are       |
|                      |                           | turned back on                    |
|                      |                           | that were previously              |
|                      |                           | off, the green                    |
|                      |                           | light turns back on               |
|                      |                           | (the welcome                      |
|                      |                           | message is printed                |
|                      |                           | if the driver                     |
|                      |                           | hasn't already sat down),         |
|                      |                           | and the buzzer then turns off.    |
|                      |                           | When the ignition                 |
|                      |                           | button is pressed again -->       |
|                      |                           | Red Light turns on,               |
|                      |                           | 'Engine started', and             |
|                      |                           | the switches states               |
|                      |                           | don't change anything             |
|                      |                           | about the system.                 |
+----------------------+---------------------------+-----------------------------------+
| Turning off          | 1. All                    | 1. Red light turns off,           |
| the engine           | switches are              | 'Engine Off!'.                    |
| by pressing          | still in                  | Green light turns                 |
|  the ignition button | the on position           | back on indicating it             |
|                      |                           | is safe to turn                   |
|                      | 2. 1 of the 4             | the car back on.                  |
|                      | switches is off.          |                                   |
|                      | This may be               | 2. Red light turns off,           |
|                      | because the               |  'Engine Off!'.                   |
|                      | passenger got out for     | Green light does                  |
|                      | example.                  | not turn back on.                 |
+----------------------+---------------------------+-----------------------------------+
