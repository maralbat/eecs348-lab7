#include <stdio.h>
#include "temperature.h"

int main() {
    //initialize variables with their appropriate types
    float temp;
    char temp_scale = '\0';
    char target_scale = '\0';
    float converted_temp;
    float converted_to_celsius;

    while (1) {
        printf("Enter the temperature value: "); //prompt user for temperature
        scanf("%f", &temp); //scan formatted string

        printf("Choose the temperature scale of the input value (F, C, or K): "); //prompt user for input scale
        scanf(" %c", &temp_scale); //a space is needed before the "%c" to ensures we skip any leading whitespace characters, 
                                    //including the leftover newline.

        printf("Choose the conversion target (F, C, or K): "); ////prompt user for target scale
        scanf(" %c", &target_scale); //a space is needed before the "%c". see reasoning above.
    
        if (temp_scale == target_scale) { //if the user makes a redundant conversion choice.
            printf("Invalid conversion choice."); //error message
        }
        //all subsequent F, C, or K is wrapped in signle quotes, instead of double quotes to signify a single character with 
        //char data type instead of a string of characters.
        else if (temp_scale == 'K' && temp < 0) { //if the user submits a temperature below absolute zero.
                printf("Invalid input for Kelvin."); //error message
        }
        else if (temp_scale == 'C' && temp < -273.15) { //if the user submits a temperature below absolute zero.
            printf("Invalid input for Celsius."); //error message
        }
        else if (temp_scale == 'F' && temp < -459.67) { //if the user submits a temperature below absolute zero.
            printf("Invalid input for Fahrenheit."); //error message
        }
        else if (temp_scale == 'C' && target_scale == 'F') { //C->K
            converted_temp = celsius_to_fahrenheit(temp); //temp in targer scale
            printf("Converted temperature: %f F\n", converted_temp); //print conversion
            categorize_temperature(temp); //weather category and advisory
        }
        else if (temp_scale == 'F' && target_scale == 'C') { //F->C
            converted_temp = fahrenheit_to_celsius(temp); //temp in targer scale
            printf("Converted temperature: %f C\n", converted_temp); //print conversion
            categorize_temperature(converted_temp); //weather category and advisory. use converted temp since it is in celsius
        }
        else if (temp_scale == 'C' && target_scale == 'K') { //C->K
            converted_temp = celsius_to_kelvin(temp); //temp in targer scale
            printf("Converted temperature: %f K\n", converted_temp); //print conversion
            categorize_temperature(temp); //weather category and advisory
        }
        else if (temp_scale == 'K' && target_scale == 'C') { //K->C
            converted_temp = kelvin_to_celsius(temp); //temp in targer scale
            printf("Converted temperature: %f C\n", converted_temp); //print conversion
            categorize_temperature(converted_temp); //weather category and advisory. use converted temp since it is in celsius
        }
        else if (temp_scale == 'F' && target_scale == 'K') { //F->K
            converted_temp = fahrenheit_to_kelvin(temp); //temp in targer scale
            printf("Converted temperature: %f K\n", converted_temp); //print conversion
            converted_to_celsius = fahrenheit_to_celsius(temp); //convert to celsius
            categorize_temperature(converted_to_celsius); //weather category and advisory
        }
        else if (temp_scale == 'K' && target_scale == 'F') { //K->F
            converted_temp = kelvin_to_fahrenheit(temp); //temp in targer scale
            printf("Converted temperature: %f F\n", converted_temp); //print conversion
            converted_to_celsius = kelvin_to_celsius(temp); //convert to celsius
            categorize_temperature(converted_to_celsius); //weather category and advisory
        }
        else { //if the user enters any other characters for the scales e.g. H or J etc.
            printf("Invalid input for temperature conversion."); //error message
        }

    return 0; //finish running program
}
}