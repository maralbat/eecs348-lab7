#include <stdio.h>
#include "temperature.h"

int main() {
    float temp;
    char temp_scale = '\0';
    char target_scale = '\0';
    float converted_temp;
    float converted_to_celsius;

    while (1) {
        printf("Enter the temperature value: ");
        scanf("%f", &temp);

        printf("Choose the temperature scale of the input value (F, C, or K): ");
        scanf(" %c", &temp_scale);

        printf("Choose the conversion target (F, C, or K): ");
        scanf(" %c", &target_scale);
    
        if (temp_scale == target_scale) {
            printf("Invalid conversion choice. Try again");
        }
        else if (temp_scale == 'K' && temp < 0) {
                printf("Invalid input for Kelvin.");
        }
        else if (temp_scale == 'C' && temp < -273.15) {
            printf("Invalid input for Celsius.");
        }
        else if (temp_scale == 'F' && temp < -459.67) {
            printf("Invalid input for Fahrenheit.");
        }
        else if (temp_scale == 'C' && target_scale == 'F') {
            converted_temp = celsius_to_fahrenheit(temp);
            printf("Converted temperature: %f\n", converted_temp);
            categorize_temperature(temp);
        }
        else if (temp_scale == 'F' && target_scale == 'C') {
            converted_temp = fahrenheit_to_celsius(temp);
            printf("Converted temperature: %f\n", converted_temp);
            categorize_temperature(converted_temp);
        }
        else if (temp_scale == 'C' && target_scale == 'K') {
            converted_temp = celsius_to_kelvin(temp);
            printf("Converted temperature: %f\n", converted_temp);
            categorize_temperature(temp);
        }
        else if (temp_scale == 'K' && target_scale == 'C') {
            converted_temp = kelvin_to_celsius(temp);
            printf("Converted temperature: %f\n", converted_temp);
            categorize_temperature(converted_temp);
        }
        else if (temp_scale == 'F' && target_scale == 'K') {
            converted_temp = fahrenheit_to_kelvin(temp);
            printf("Converted temperature: %f\n", converted_temp);
            converted_to_celsius = fahrenheit_to_celsius(temp);
            categorize_temperature(converted_to_celsius);
        }
        else if (temp_scale == 'K' && target_scale == 'F') {
            converted_temp = kelvin_to_fahrenheit(temp);
            printf("Converted temperature: %f\n", converted_temp);
            converted_to_celsius = kelvin_to_celsius(temp);
            categorize_temperature(converted_to_celsius);
        }
        else {
            printf("Invalid input for temperature conversion. Try again.");
        }

    return 0;
}
}