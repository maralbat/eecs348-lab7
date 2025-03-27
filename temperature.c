#include <stdio.h>
#include "temperature.h"

//temperature conversions
float celsius_to_fahrenheit (float celsius) {
    return (9.0/5.0)*celsius + 32;
}
float fahrenheit_to_celsius (float fahrenheit) {
    return (5.0/9.0)*(fahrenheit - 32);
}
float celsius_to_kelvin (float celsius) {
    return celsius + 273.15;
}
float kelvin_to_celsius (float kelvin) {
    return kelvin - 273.15;
}
float fahrenheit_to_kelvin (float fahrenheit) {
    return (5.0/9.0)*(fahrenheit - 32) + 273.15; //formula is F->C->K
}
float kelvin_to_fahrenheit (float kelvin) {
    return (kelvin - 273.15)*(9.0/5.0) + 32; //formula is K->C->F
}

void categorize_temperature(float celsius) {
    if (celsius < 0) { //Freezing: Below 0°C (or equivalent in other scales)
        printf("Temperature Category: Freezing\nWeather Advisory: Dress warm. Be careful if driving.");
    }
    else if (celsius < 10 ) { //Cold: 0°C to 10°C (or equivalent)
        printf("Temperature Category: Cold\nWeather Advisory: Wear a jacket.");
    }
    else if (celsius < 25) { //Comfortable: 10°C to 25°C (or equivalent)
        printf("Temperature Category: Comfortable\nWeather Advisory: Nice day to go out.");
    }
    else if (celsius < 35) { //Hot: 25°C to 35°C (or equivalent)
        printf("Temperature Category: Hot\nWeather Advisory: Stay hydrated and wear sun protection.");
    }
    else { //Extreme Heat: Above 35°C (or equivalent)
        printf("Temperature Category: Extreme Heat\nWeather Advisory: Stay indoors. Be wary of heat stroke.");
    }
}