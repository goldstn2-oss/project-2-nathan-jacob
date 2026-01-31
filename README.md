Nathan Goldstein and Jacob Zeltser

This is a simulated safety system designed for under 21 Drivers Ed students who need to have direct supervision per New York's driving regulations.
By using a light indicator and buzzer it ensures an instuctor is present and buckled before the cars ignition can be pressed. If the cars ignition is pressed before 
these requirements are met, a buzzer goes off, however the user can disable the alarm by having both driver and passenger seated and buckled (turning back on the ligth indicator).
Once the ignition is on, for safety and usability we added a headlight system. This headlight system has an off setting, an on setting, and an auto setting. The auto setting turns
on the lights when it is dark out, turns off the lights when it is light out, and when it is somewhere inbetween (midlight mode) it maintains its previous state). Finally, when 
the headlights are on we added a switch to turn on the high beams.

Starting Repository
[(https://github.com/goldstn2-oss/Project-1-218-N-M)]

+------------------------------------------------------------------------------------------------------------------+
|                                    Table of Testing Results For the Ignitions                                    |
+----------------------+-----------------------------------------+-------------------------------------------------+
| Specification        | Test Process                            | Results                                         |
+----------------------+-----------------------------------------+-------------------------------------------------+
| Turn Green LED on    | 4 total switches:                       | 1.'Welcome to enhanced                          |
| -->Igntion is able   | (DS,PS,DSSB,PSSB)                       | alarm system model 218-W26'                     |
| to be pushed safely  | 1. All switches on                      | 2. No Green light for All cases.                |
|                      | 2. All switches but 1                   | Only special case is no driver                  |
|                      | 3. No buttons pressed                   | --> the welcome message not printed             |
|                      |                                         | 3. No Green light or welcome message            |
+----------------------+-----------------------------------------+-------------------------------------------------+
| Try to start the     | 1. When all the switches are on         | 4 Error Message:                                |
| engine               | ( green led is on and the welcome       |    a. Driver seat is not occupies               |
| by pressing          | message is up)                          |    b. Passenger seat is not occupied            |
| the ignition button  |                                         |    c. Driver seatbelt not fastened              |
|                      | 2. When 1 or multiple of the            |    d passenger seatbelt not fastened            |
|                      | switches is off                         |                                                 |
|                      | (green light is off and maybe no        | 1. Red Light turns on, 'Engine started',        |
|                      | welcome message if driver isn't         | the switches states                             |
|                      | seated)                                 | don't change anything about the system.         |
|                      |                                         |                                                 |
|                      | 3. When 1 or multiple switches are off  | 2. Error message a, b, c, and/or d is           |
|                      | (green light is off                     | printed based on which                          |
|                      | and maybe no welcome                    | switch is not on. The buzzer goes off.          |
|                      | message if driver isn't seated).        | 'Ignition Inhibited' is printed.                |
|                      | The ignition is pressed,                |                                                 |
|                      | then the switches not on are turned     | 3. Error message a, b, c,                       |
|                      | on again. Finally,                      | and/or d is printed                             |
|                      | the ignition is pressed again.          | based on which switch is not on.                |
|                      |                                         | The buzzer goes off.                            |
|                      |                                         | 'Ignition Inhibited' is printed.                |
|                      |                                         | Then, when the switches are                     |
|                      |                                         | turned back on that were previously             |
|                      |                                         | off, the green light turns back on              |
|                      |                                         | (the welcome message is printed                 |
|                      |                                         | if the driver hasn't already sat down),         |
|                      |                                         | and the buzzer then turns off.                  |
|                      |                                         | When the ignition                               |
|                      |                                         | button is pressed again -->                     |
|                      |                                         | Red Light turns on,                             |
|                      |                                         | 'Engine started', and                           |
|                      |                                         | the switches states                             |
|                      |                                         | don't change anything                           |
|                      |                                         | about the system.                               |
+----------------------+-----------------------------------------+-------------------------------------------------+
| Turning off          | 1. All switches are                     | 1. Red light turns off,                         |
| the engine           | still in the on position                | 'Engine Off!'.                                  |
| by pressing          |                                         | Green light turns                               |
|  the ignition button | 2. 1 of the 4 switches is off.          | back on indicating it                           |
|                      | This may be                             | is safe to turn                                 |
|                      | because the passenger got out for       | the car back on.                                |
|                      | example.                                |                                                 |
|                      |                                         | 2. Red light turns off,                         |
|                      |                                         |  'Engine Off!'.                                 |
|                      |                                         | Green light does                                |
|                      |                                         | not turn back on.                               |
+----------------------+-----------------------------------------+-------------------------------------------------+
      



