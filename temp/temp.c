#include <stdio.h>

//functions for conversions
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temperature(float celsius);

//main definition
int main() {
    //define typed for input output
    float temp_input, converted_temp;
    int input_scale, target_scale;
    //ask for temperature, save to temp_input
    while (1) {
        printf("Enter the temperature (negative to exit): ");
        scanf("%f", &temp_input);
        if (temp_input < 0) break;

        //ask for scale, save to input_scale
        printf("Choose the type of the input (1: Fahrenheit, 2: Celsius, 3: Kelvin): ");
        scanf("%d", &input_scale);

        //ask for output scale, save to target_scale
        printf("Choose what to convert to (1: Fahrenheit, 2: Celsius, 3: Kelvin): ");
        scanf("%d", &target_scale);

        //can't convert to same type
        if (input_scale == target_scale) {
            printf("Input type and output type cannot be the same.\n");
            continue;
        }

        //call correct function for each combo
        if (input_scale == 1 && target_scale == 2) {
            converted_temp = fahrenheit_to_celsius(temp_input);
        } else if (input_scale == 1 && target_scale == 3) {
            converted_temp = fahrenheit_to_kelvin(temp_input);
        } else if (input_scale == 2 && target_scale == 1) {
            converted_temp = celsius_to_fahrenheit(temp_input);
        } else if (input_scale == 2 && target_scale == 3) {
            converted_temp = celsius_to_kelvin(temp_input);
        } else if (input_scale == 3 && target_scale == 1) {
            converted_temp = kelvin_to_fahrenheit(temp_input);
        } else if (input_scale == 3 && target_scale == 2) {
            converted_temp = kelvin_to_celsius(temp_input);
        } else {
            printf("Invalid selection!\n");
            continue;
        }

        //output the converted temperature
        printf("Converted temperature: %.2f\n", converted_temp);

        //categorize
        categorize_temperature(target_scale == 1 ? fahrenheit_to_celsius(converted_temp) : 
                                target_scale == 3 ? kelvin_to_celsius(converted_temp) : 
                                converted_temp);
    }

    printf("Exiting program.\n");
    return 0;
}

//conversion functions
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

//needn't rewrite constants
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

//categorization function
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing. \nStay indoors!!\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold. \nWear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable. \nWear anything!\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot. \nDrink water!\n");
    } else {
        printf("Temperature category: Extreme Heat. \nStay indoors!!\n");
    }
}

