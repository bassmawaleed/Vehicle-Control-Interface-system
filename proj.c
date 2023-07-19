/*
 * proj.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Basma Walid
 */

#include<stdio.h>

char display_menu();
char sensor_set();
void traffic_lights(float *ptr_vehicle_speed,float *(ptr_engine_temp));
void ac_status(char *ptr_ac_state , float * ptr_temperature);
void engine_temperature(float *(ptr_engine_temp) , char *(ptr_temp_controller) );
void vehicle_speed_controller(char *(ptr_ac_state) ,float * (ptr_temperature),char *(ptr_temp_controller),float * (ptr_engine_temp));


int main(void)
{
	//declaring input and inputt2 for inputs of display_menu and sensor_set
	char input;
	char inputt2;

	//defining system variables
	char ac_state=0;
	char temp_controller=0;
	float vehicle_speed=0.0;
	float temperature=35.0;
	float engine_temp=0.0;

	//Displaying the main menu
	input=display_menu();


	//Corner Case when user doesn't enter a or b or c and enter any other thing

	while(input != 'a' && input != 'b' && input !='c')
	{
		printf("WRONG ENTRY \n");
		printf("Please Enter a or b or c based on your requirement \n \n");
		input=display_menu();
	}

	//If user chose to terminate the system
	if(input == 'c')
	{
		printf("System State : Terminated \n");
		return 0;
	}

	//If user chose to turn off the engine
	while( input == 'b')
	{
		printf("System State : Engine is off \n \n \n");
		input=display_menu();
		if(input == 'c')
		{
			printf("System State : Terminated \n \n");
			return 0;
		}
	}

	//If user chose to turn on the engine
	if(input == 'a')
		printf("System State : Engine is on \n \n");


	while ( input == 'a')
		while(1)
	{
		inputt2=sensor_set();
		while(inputt2 == 'a' )
		{
			printf("System State : Engine is off \n \n \n");
			input=display_menu();
			if(input == 'c')
			{
				printf("System State : Terminated \n \n");
				return 0;
			}
			if(input == 'a')
				break;
		}


		//Traffic Light Colour
		if(inputt2 == 'b' )
		{
			//Calling the function responsible for setting the traffic lights
			traffic_lights(&vehicle_speed,&engine_temp);
		}

		//Room Temperature
		if(inputt2 == 'c')
		{
			ac_status(&(ac_state) , &temperature);
		}

		//Engine Temperature
		if(inputt2 == 'd')
		{
			engine_temperature(&(engine_temp),&(temp_controller));
		}

		//Vehicle Speed
		if(vehicle_speed == 30)
		{
			vehicle_speed_controller(&(ac_state),&(temperature),&(temp_controller),&(engine_temp));
		}



	//Printing Current Vehicle Status
	printf("Current Vehicle State : \n \n");
	if(input == 'b')
		printf("Engine is off \n");
	if(input == 'a')
	{
		//Displaying Engine State
		printf("Engine is on \n");
		if(ac_state == 1)
			printf("AC is on \n");
		else
			printf("AC is off \n");

		//Displaying Vehicle Speed
		printf("The vehicle speed is %f km/hr \n",vehicle_speed);

		//Displaying Room Temperature
		printf("Room temperature is %f C \n",temperature );

		//Displaying Engine Temperature Controller State
		if(temp_controller == 1)
			printf("Engine Controller state is on \n ");
		else
			printf("Engine Controller state is off \n ");

		//Displaying Engine Temperature
		printf("Engine Temperature is %f \n \n",engine_temp);
	}
	}
	return 0;
}

char display_menu()
{
	char input;
	printf("Please, Choose what you want to do : \n");
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	fflush(stdout);
	scanf(" %c",&input);
	return input;
}

char sensor_set()
{
	char input2;
	printf("Sensors Set Menu :\n");
	printf("a. Turn off the vehicle engine. \n");
	printf("b. Set the traffic light color. \n");
	printf("c. Set the room temperature (Temperature Sensor) \n");
	printf("d. Set the engine temperature (Engine Temperature Sensor) \n");
	fflush(stdout);
	scanf(" %c" , &input2);
	return input2;
}


void traffic_lights(float *ptr_vehicle_speed,float *(ptr_engine_temp))
{
	char traffic_colour;
	printf("Enter the traffic light colour : \n");
	printf("g (for green) \n");
	printf("o (for orange) \n");
	printf("r (for red) \n");
	fflush(stdout);
	scanf(" %c",&traffic_colour);
	while( (traffic_colour != 'g') && (traffic_colour != 'o') && (traffic_colour != 'r'))
	{
		printf("Traffic colour is %c \n",traffic_colour);
		printf("WRONG ENTRY \n");
		printf("Enter the traffic light colour : \n");
		printf("g (for green) \n");
		printf("o (for orange) \n");
		printf("r (for red) \n");
		fflush(stdout);
		scanf(" %c",&traffic_colour);
	}
	if(traffic_colour == 'r')
	{
		*ptr_vehicle_speed= 0;
		*(ptr_engine_temp)=20.0;
	}
	else if (traffic_colour == 'o')
	{
		*ptr_vehicle_speed=30;
		*(ptr_engine_temp)=90.0;
	}
	else if(traffic_colour == 'g')
	{
		*ptr_vehicle_speed=100;
		*(ptr_engine_temp)=90.0;
	}

}

void ac_status(char *ptr_ac_state , float * ptr_temperature)
{
	printf("Enter the temperature : \n");
	fflush(stdout);
	scanf(" %f" , &(*(ptr_temperature)));
	if(*(ptr_temperature) < 10 || *(ptr_temperature) > 30)
	{
		printf("AC is ON \n");
		*ptr_ac_state=1;
		*(ptr_temperature)=20;
	}
	else
	{
		printf("AC is off \n");
		*ptr_ac_state=0;
	}
}

void engine_temperature(float *(ptr_engine_temp) , char *(ptr_temp_controller) )
{
	printf("Enter Engine temperature : \n");
	fflush(stdout);
	scanf(" %f" , &(*(ptr_engine_temp)));
	if(*(ptr_engine_temp) <100 || *(ptr_engine_temp) >150)
	{
		*(ptr_temp_controller)=1;
		*(ptr_engine_temp)=125;
	}
	else
		*(ptr_temp_controller)=0;
}

void vehicle_speed_controller(char *(ptr_ac_state) ,float * (ptr_temperature),char *(ptr_temp_controller),float * (ptr_engine_temp))
{
	if(*(ptr_ac_state) == 0)
	{
		*(ptr_ac_state)=1;
		* (ptr_temperature)=(* (ptr_temperature) )* 5 / 4 +1 ;
	}
	if(*(ptr_temp_controller) == 0)
	{
		*(ptr_temp_controller)=1;
		* (ptr_engine_temp)= (* (ptr_engine_temp)) * 5 /4 + 1;
	}
}


