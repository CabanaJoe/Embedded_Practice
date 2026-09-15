//area and circumference of a circle

/**
 * psuedo code:
 * 1. variables (finished)
 * 2. user input
 * 3. area and circumference calculation
 * 4. output
 * 5. return
 */

#include<stdio.h> // for scanf and printf


// variables needed radius or diameter from user.
// area and circumference for output

float radius, diameter, area, circumference; // initialized to 0.0 since global variables
int userinput;

const float PI =  3.14159265;


float CircleStatsRadius(float CircleDimension)
{
    // calculating the circumference and area.
    circumference = 2.0 * PI * radius;
    area = PI * radius * radius;
    printf("(Calling Function) With a radius of %0.01f the cirlces Circumference is: %0.01f.\n", radius, circumference);
    printf("(Calling Function) With a radius of %0.01f the cirlces Area is: %0.01f.\n", radius, area);
}

float CircleStatsDiameter(float CircleDimension2)
{
        // calculating the circumference and area.
        circumference = (PI * diameter * diameter)/4.0;
        area = PI * diameter;

        //printing for the user to show them their results.
        printf("(Calling Function) With a diameter of %0.01f the cirlces Circumference is: %0.01f.\n", diameter, circumference);
        printf("(Calling Function) With a diameter of %0.01f the cirlces Area is: %0.01f.\n", diameter, area);
    
}


int main() 
{
    // asking user for input
    printf("Finding the area and circumference of a circle.\n");
    printf("Press 1 and Enter if you have a Radius.\n");
    printf("Press 2 and Enter if you have a Diameter.\n");

    // user letting us know if they have a radius or diameter.
    scanf("%d", &userinput);

    // if user has radius.
    if(userinput == 1)
    {
        // asking user to enter radius.
        printf("Enter your Radius up to using accracy up to the hundreths place.\n");

        // input radius from user.
        scanf("%f", &radius);

        // using a function instead.
        CircleStatsRadius(radius);

        // calculating the circumference and area.
        circumference = 2.0 * PI * radius;
        area = PI * radius * radius;

        //printing for the user to show them their results.
        printf("With a radius of %0.01f the cirlces Circumference is: %0.01f.\n", radius, circumference);
        printf("With a radius of %0.01f the cirlces Area is: %0.01f.\n", radius, area);

    }

    else
    {
        // asking user to enter Diameter.
        printf("Enter your Diameter up to using accracy up to the hundreths place.\n");

        scanf("%f", &diameter);

        // using function to find the circle stats
        CircleStatsDiameter(diameter);

        // calculating the circumference and area.
        circumference = (PI * diameter * diameter)/4.0;
        area = PI * diameter;

        //printing for the user to show them their results.
        printf("With a diameter of %0.01f the cirlces Circumference is: %0.01f.\n", diameter, circumference);
        printf("With a diameter of %0.01f the cirlces Area is: %0.01f.\n", diameter, area);
    }
    
    return 0;

}