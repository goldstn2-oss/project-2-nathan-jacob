#include "driver/gpio.h"
#include "stdio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "freertos/task.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"


// Defining GPIO pins, loop delay
#define LED_green GPIO_NUM_10
#define LED_red GPIO_NUM_12
#define ALARM GPIO_NUM_1
#define BUTTON_DS GPIO_NUM_4
#define BUTTON_PS GPIO_NUM_5
#define BUTTON_DSSB GPIO_NUM_6
#define BUTTON_PSSB GPIO_NUM_7
#define BUTTON_IG GPIO_NUM_15
#define LOOP_DELAY_MS 25

//Defining ADC parameters 

#define ADC_CHANNEL_GPIO16   ADC_CHANNEL_5   
#define ADC_CHANNEL_GPIO17   ADC_CHANNEL_6   
#define ADC_ATTEN           ADC_ATTEN_DB_12
#define BITWIDTH            ADC_BITWIDTH_12
#define DELAY_MS 250


#define HEADLIGHT_PIN 18
#define BRIGHT_PIN 14   


#define OFF  0
#define ON   1
#define AUTO 2


adc_oneshot_unit_handle_t adc2_handle;
adc_cali_handle_t cali_gpio16;
adc_cali_handle_t cali_gpio17;

// function to specify delays in milliseconds
void delay_ms(int t) {
   vTaskDelay(pdMS_TO_TICKS(t));
}

void app_main(void)
{
   int raw16, raw17;
    int mv16, mv17;
    int state;

    
    gpio_reset_pin(HEADLIGHT_PIN);
    gpio_set_direction(HEADLIGHT_PIN, GPIO_MODE_OUTPUT);
    gpio_reset_pin(BRIGHT_PIN);
    gpio_set_direction(BRIGHT_PIN, GPIO_MODE_OUTPUT);

    
    adc_oneshot_unit_init_cfg_t init_config = {
        .unit_id = ADC_UNIT_2,
    };
    adc_oneshot_new_unit(&init_config, &adc2_handle);

   
    adc_oneshot_chan_cfg_t config = {
        .atten = ADC_ATTEN,
        .bitwidth = BITWIDTH
    };
    adc_oneshot_config_channel(adc2_handle, ADC_CHANNEL_GPIO16, &config);
    adc_oneshot_config_channel(adc2_handle, ADC_CHANNEL_GPIO17, &config);

    
    adc_cali_curve_fitting_config_t cali16_cfg = {
        .unit_id = ADC_UNIT_2,
        .chan = ADC_CHANNEL_GPIO16,
        .atten = ADC_ATTEN,
        .bitwidth = BITWIDTH
    };
    adc_cali_curve_fitting_config_t cali17_cfg = {
        .unit_id = ADC_UNIT_2,
        .chan = ADC_CHANNEL_GPIO17,
        .atten = ADC_ATTEN,
        .bitwidth = BITWIDTH
    };
    adc_cali_create_scheme_curve_fitting(&cali16_cfg, &cali_gpio16);
    adc_cali_create_scheme_curve_fitting(&cali17_cfg, &cali_gpio17);

    // Initializing pins, setting directions and pull-ups, booleans, flags
   gpio_reset_pin(LED_green);
   gpio_set_direction(LED_green, GPIO_MODE_OUTPUT);


   gpio_reset_pin(LED_red);
   gpio_set_direction(LED_red, GPIO_MODE_OUTPUT);


   gpio_reset_pin(ALARM);
   gpio_set_direction(ALARM, GPIO_MODE_OUTPUT);


   gpio_reset_pin(BUTTON_DS);
   gpio_set_direction(BUTTON_DS, GPIO_MODE_INPUT);


   gpio_reset_pin(BUTTON_PS);
   gpio_set_direction(BUTTON_PS, GPIO_MODE_INPUT);


   gpio_reset_pin(BUTTON_DSSB);
   gpio_set_direction(BUTTON_DSSB, GPIO_MODE_INPUT);


   gpio_reset_pin(BUTTON_PSSB);
   gpio_set_direction(BUTTON_PSSB, GPIO_MODE_INPUT);


   gpio_reset_pin(BUTTON_IG);
   gpio_set_direction(BUTTON_IG, GPIO_MODE_INPUT);   
   gpio_set_level(LED_green, 0);
   gpio_set_level(LED_red, 0);
   gpio_set_level(ALARM, 0);
   gpio_pullup_en(BUTTON_DS);
   gpio_pullup_en(BUTTON_PS);
   gpio_pullup_en(BUTTON_DSSB);
   gpio_pullup_en(BUTTON_PSSB);
   gpio_pullup_en(BUTTON_IG);
   
   bool welcomeflag = true;
   bool enginestartedflag = true;
   bool ignitioninhibitflag = true;
   bool drivseatflag = true;
   bool passeatflag = true;
   bool drivbeltflag = true;
   bool pasbeltflag = true;
   bool loopflag = true;
   bool prevlev = true;

   bool lstate = false; // green light state to indicate when all of the checks are completed
   bool rlstate = false;// Red light state to indicate when the engine has been put on correctly 
  // Main loop



  while (1) {
   loopflag = true; // Reset loopflag at the beginning of each loop iteration


   if (!gpio_get_level(BUTTON_DS) && welcomeflag == true) { // Initial welcome message when driver seat is occupied
           printf("Welcome to enhanced alarm system model 218-W25\n");
           welcomeflag = false;
   }


   if (!gpio_get_level(BUTTON_DS) && !gpio_get_level(BUTTON_PS) && !gpio_get_level(BUTTON_DSSB) \
   && !gpio_get_level(BUTTON_PSSB) && rlstate == false) { // All conditions met for enabling engine start
           gpio_set_level(LED_green, 1); // Turn on green LED
           gpio_set_level(ALARM,0); // Disable alarm in case previously enabled
           lstate = true;
       }
   else {
           gpio_set_level(LED_green, 0); // Keep green LED off if conditions not met
           lstate = false;
       }


   if (!gpio_get_level(BUTTON_IG) && lstate == true){ // Engine start condition
           gpio_set_level(LED_green, 0);
           gpio_set_level(LED_red, 1);
        
           rlstate = true;
           while(!gpio_get_level(BUTTON_IG)){
            delay_ms(50);
           }
           delay_ms(100);
           if(enginestartedflag == true) {            // Send welcome message if engine started
               printf("Engine Started!\n");
               enginestartedflag = false;
           }
       }
   if (lstate == false && !gpio_get_level(BUTTON_IG) && rlstate == false) { // If engine start conditions not met,
           gpio_set_level(ALARM, 1); // Sound alarm
           // Send warning messages stating reason for ignition inhibition
           if(ignitioninhibitflag == true) {
               printf("Ignition Inhibited!\n");
               ignitioninhibitflag = false;
           }
               if(gpio_get_level(BUTTON_DS) && drivseatflag == true) {
                   printf("Driver seat not occupied!\n");
                   drivseatflag = false;
               }
               if(gpio_get_level(BUTTON_PS) && passeatflag == true) {
                   printf("Passenger seat not occupied!\n");
                   passeatflag = false;
               }
               if(gpio_get_level(BUTTON_DSSB) && drivbeltflag == true) {
                   printf("Driver seatbelt not fastened!\n");
                   drivbeltflag = false;
               }
               if (gpio_get_level(BUTTON_PSSB) && pasbeltflag == true) {
                   printf("Passenger seatbelt not fastened!\n");
                   pasbeltflag = false;
               }
            }

        if (rlstate == true) { // If engine is being turned off
            if (!gpio_get_level(BUTTON_IG) && rlstate == true ) {
                printf("Engine Off!\n");
                gpio_set_level(HEADLIGHT_PIN, 0);
                gpio_set_level(BRIGHT_PIN, 0);
                gpio_set_level(LED_red, 0);
                rlstate = false;
                enginestartedflag = true;
                ignitioninhibitflag = true;
                drivseatflag = true;
                passeatflag = true;
                drivbeltflag = true;
                pasbeltflag = true;
                gpio_set_level(ALARM, 0);
                gpio_set_level(LED_green, 0);
                lstate = false;
                delay_ms(100);
                while(!gpio_get_level(BUTTON_IG)){
            delay_ms(50);
           }
        }

       } 


        
adc_oneshot_read(adc2_handle, ADC_CHANNEL_GPIO16, &raw16);
adc_cali_raw_to_voltage(cali_gpio16, raw16, &mv16);


adc_oneshot_read(adc2_handle, ADC_CHANNEL_GPIO17, &raw17);
adc_cali_raw_to_voltage(cali_gpio17, raw17, &mv17);

if (mv16 >= 0 && mv16 < 1060) { //range for when light mode is set to off
    state = OFF;
} else if (mv16 >= 1060 && mv16 < 2120) { //range for when light mode is set to on
    state = ON;

} else { //final range for when mode is set to auto
    state = AUTO;
}

 if(rlstate == true){ // if ignition started run the following switch 
        switch (state) {// input chosen from above depending on pot condition
            case OFF: //set head lights off 
                gpio_set_level(HEADLIGHT_PIN, 0);
                gpio_set_level(BRIGHT_PIN, 0);
                
                break;
            case ON: //set headlights on 
                gpio_set_level(HEADLIGHT_PIN, 1);
                gpio_set_level(BRIGHT_PIN, 1);  
                
                break;
            case AUTO: // set lights to auto determined by light sensr
                if (mv17 < 150) { // if light range low turn on 
                    delay_ms(1000);
                    adc_oneshot_read(adc2_handle, ADC_CHANNEL_GPIO17, &raw17);
                    adc_cali_raw_to_voltage(cali_gpio17, raw17, &mv17);
                    if (mv17 < 150){
                        gpio_set_level(HEADLIGHT_PIN, 1); 
                        gpio_set_level(BRIGHT_PIN, 1);
                        prevlev = true; //remember previous state for dusk condition
                    }
                    else {}
                }  
                if (mv17 > 650){ //daylight turn light off
                    delay_ms(2000);
                    adc_oneshot_read(adc2_handle, ADC_CHANNEL_GPIO17, &raw17);
                    adc_cali_raw_to_voltage(cali_gpio17, raw17, &mv17);
                    if (mv17 > 650){
                        gpio_set_level(HEADLIGHT_PIN, 0);
                        gpio_set_level(BRIGHT_PIN, 0);
                        prevlev = false;  //remember previous state for dusk condition
                    }
                    else {

                    }
                }
                
                else {
                    gpio_set_level(HEADLIGHT_PIN, prevlev);
                    gpio_set_level(BRIGHT_PIN, prevlev);
                    
                }
                break;
        }
    }
    
        

delay_ms(LOOP_DELAY_MS);

}

}