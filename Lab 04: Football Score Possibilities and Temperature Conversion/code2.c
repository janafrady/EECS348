
/*
Name: Jana Frady
KUID: 3085051
Lab Session: Thursday 4 p.m.
Lab Assignment Number: 04
Program Description: This program converts temperatures and outputs weather warnings
Collaborators: None
*/

#include <stdio.h>


float celsius_to_fahrenheit(float celsius){
    // converts celsius to fahrenheit
    return (9.0 / 5.0 * celsius) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit){
    // converts fahrenheit to celsius
    return 5.0/9.0 * (fahrenheit-32.0);
}

float celsius_to_kelvin(float celsius){
    // converts celsius to kelvin
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin){
    // converts kelvin to celsius
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit){
    // converts fahrenheit to kelvin
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin){
    // converts kelvin to fahrenheit
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius){
    // categorizes given temperature
    if (celsius < 0){
        printf("Temperature category: Freezing\nWeather advisory: Don't leave your house... brrr.\n");
    } else if (0 <= celsius && celsius <= 10){
        printf("Temperature category: Cold\nWeather advisory: Wear a jacket.\n");
    } else if (10 < celsius && celsius <= 25){
        printf("Temperature category: Comfortable\nWeather advisory: You'll be fine.\n");
    } else if (25 < celsius && celsius <= 35){
        printf("Temperature category: Hot\nWeather advisory: It's hot outside.\n");
    } else {
        printf("Temperature category: Extreme Heat\nWeather advisory: Extreme heat outside. Try to fry an egg on the sidewalk.\n");
    }
}

int main(){
    // initializes the program
    int err = 0;
    while (err == 0){
        err = 1;
        float temp, newTemp;
        int current, convert;

        // user input
        printf("\nEnter the temperature: ");
        scanf("%f", &temp);
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &current);
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &convert);

        if (current == 3 && temp < 0){  // checks to see if any Kelvin entry is nonnegative
            err = 0;
            printf("Kelvin cannot be negative\n");
        }

        if (err == 1){
            // changes temperature into desired one
            if (current == 1){  // Initial temperature Celsius
                if (current == convert){
                    printf("Cannot convert Celsius to Celsius\n");
                    err = 0;
                } else {
                    if (convert == 2){  // convert to Fahrenheit
                        newTemp = celsius_to_fahrenheit(temp);
                        printf("\nConverted temperature: %f degrees Fahrenheit\n", newTemp);
                    } else if (convert == 3){   //convert to Kelvin
                        newTemp = celsius_to_kelvin(temp);
                        printf("\nConverted temperature: %fK\n", newTemp);
                    }
                    categorize_temperature(temp);
                }
            } else if (current == 2){   // Initial temperature Fahrenheit
                if (current == convert){
                    printf("Cannot convert Fahrenheit to Fahrenheit\n");
                    err = 0;
                } else {
                    if (convert == 1){  // convert to Celsius
                        newTemp = fahrenheit_to_celsius(temp);
                        printf("\nConverted temperature: %f degrees Fahrenheit\n", newTemp);
                    } else if (convert == 3){   // converts to Kelvin
                        newTemp = fahrenheit_to_kelvin(temp);
                        printf("\nConverted temperature: %fK\n", newTemp);
                    }
                    categorize_temperature(fahrenheit_to_celsius(temp));
                }
            } else if (current == 3){   // Initial temperature Kelvin
                if (current == convert){
                    printf("Cannot convert Kelvin to Kelvin\n");
                    err = 0;
                } else {
                    if (convert == 1){  // convert to Celsius
                        newTemp = kelvin_to_celsius(temp);
                        printf("\nConverted temperature: %f degrees Celsius\n", newTemp);
                    } else if (convert == 2){   // convert to Fahrenheit
                        newTemp = kelvin_to_fahrenheit(temp);
                        printf("\nConverted temperature: %f degrees Fahrenheit\n", newTemp);
                    }
                    categorize_temperature(kelvin_to_celsius(temp));
                }
            }
        }
    }
}
