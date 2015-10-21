//#define MULTIPLE_PROBES
#define DATA_PIN        PTC16


#include "mbed-drivers/mbed.h"
#include "DS1820-mbedOS/DS1820.h"

#define MAX_PROBES      16
 
DS1820* probe[MAX_PROBES];
 
void app_start(int, char *[]) {
    // Initialize the probe array to DS1820 objects
    int num_devices = 0;
    while(DS1820::unassignedProbe(DATA_PIN)) {
        probe[num_devices] = new DS1820(DATA_PIN);
        num_devices++;
        if (num_devices == MAX_PROBES)
            break;
    }
    
    printf("Found %d device(s)\r\n\n", num_devices);
    while(1) {
        probe[0]->convertTemperature(true, DS1820::all_devices);         //Start temperature conversion, wait until ready
        for (int i = 0; i<num_devices; i++)
            printf("Device %d returns %0.1foC\r\n", i, probe[i]->temperature());
        printf("\r\n");
        wait(1);
    }
    
}

