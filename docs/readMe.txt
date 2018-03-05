Sawaiba Sial
0990358
2017-10-22

HOSPITAL EMERGENCY ROOM SIMULATION

Description: This program uses a priority queue ADT to simulate the management of an emergency medical clinic.
The application will simulate the prioritization and processing of clients as they arrive at the minor emergency clinic. 
Each simulated client will have a client number, an emergency priority number, and a symptom code provided inside a text file. 
The program will place each client in a queue and use a priority sceduling algorithm to process the clients. A main menu allows you to add new patients, process the simulation or exit. If you are adding a new patient please make sure you enter a valid symptom code (use data.txt for examples). If you wish to process the simulation, an output table containing information about patient's id, priority number, symptom code and time finished will be displayed.

Instructions for running:

To run main program which contains the simulation, enter the following commands:
make main
cd bin
./runMe data.txt

To run testMain.c which contains all the tests used to ensure priority queue is funcitonal, enter the following commands:
make test
cd bin
./run