#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT_THRESHOLD 40
#define GREEN_LIGHT_THRESHOLD 20
#define YELLOW_LIGHT_LOWER_THRESHOLD 25
#define YELLOW_LIGHT_UPPER_THRESHOLD 35

void delay(int seconds);
void simulateTrafficLight(int vehicles[], int timeLimit, int maxCycles);

int main() {
    int vehicles[4];  // Array to store the number of vehicles for North, South, East, West
    int timeLimit, maxCycles;

    const char *directions[] = {"North", "South", "East", "West"};

    // Get the number of vehicles from the user
    for (int i = 0; i < 4; i++) {
        printf("Enter the number of vehicles at %s: ", directions[i]);
        scanf("%d", &vehicles[i]);
    }

    // Get the time limit for each traffic light
    printf("Enter the time limit for each traffic light (in seconds): ");
    scanf("%d", &timeLimit);

    // Get the maximum number of cycles
    printf("Enter the maximum number of cycles to run: ");
    scanf("%d", &maxCycles);

    // Simulate the traffic light system
    simulateTrafficLight(vehicles, timeLimit, maxCycles);

    return 0;
}

void delay(int seconds) {
    int milliseconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

void simulateTrafficLight(int vehicles[], int timeLimit, int maxCycles) {
    int currentCycle = 1;
    const char *directions[] = {"North", "South", "East", "West"};

    while ((vehicles[0] > 0 || vehicles[1] > 0 || vehicles[2] > 0 || vehicles[3] > 0) && currentCycle <= maxCycles) {
        printf("Cycle %d:\n", currentCycle);

        for (int i = 0; i < 4; i++) {
            if (vehicles[i] > RED_LIGHT_THRESHOLD) {
                printf("%s Red Light.\n", directions[i]);
            } else if (vehicles[i] < GREEN_LIGHT_THRESHOLD) {
                printf("%s Green Light for %d seconds.\n", directions[i], timeLimit);
                delay(timeLimit); // Simulate the time passing for the green light
                int vehiclesPassed = (timeLimit > vehicles[i]) ? vehicles[i] : timeLimit;
                vehicles[i] -= vehiclesPassed;
                printf("%d vehicle(s) passed from %s. Remaining: %d\n", vehiclesPassed, directions[i], vehicles[i]);
            } else if (vehicles[i] >= YELLOW_LIGHT_LOWER_THRESHOLD && vehicles[i] <= YELLOW_LIGHT_UPPER_THRESHOLD) {
                printf("%s Yellow Light for %d seconds.\n", directions[i], timeLimit);
                delay(timeLimit); // Simulate the time passing for the yellow light
                int vehiclesPassed = (timeLimit > vehicles[i]) ? vehicles[i] : timeLimit;
                vehicles[i] -= vehiclesPassed;
                printf("%d vehicle(s) passed from %s. Remaining: %d\n", vehiclesPassed, directions[i], vehicles[i]);
            }
        }

        currentCycle++;
    }

    printf("Simulation ended after %d cycle(s).\n", currentCycle - 1);
    printf("Remaining vehicles - North: %d, South: %d, East: %d, West: %d\n", vehicles[0], vehicles[1], vehicles[2], vehicles[3]);
	printf("Hello world");
}
