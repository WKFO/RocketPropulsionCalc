#include <stdio.h>
#include <math.h>
#include <windows.h>

int menu; //only used for making menu selections

float Dx; //horizontal distance to centerline
float Dy; //what we want from the program

float teta; //angle of injector placement (rel. to vertical)

float v; //fluid velocity
float vx;
float vy;
float v_avg;

float tx; //time it takes for fuel flow to reach intersection point

float g; //accel

int main() {
	start_menu:
	printf("---OPPOSING INJECTOR FLOW INTERSECTION POINT CALCULATOR---\n");
	printf("\nPlease make a selection:\n1)Calculate\n8)Clear Screen\n9)Exit\n\n > ");
		
	scanf("%d", &menu);
	
	if (menu == 1){
		printf("\nDx(m): ");
		scanf("%f", &Dx);
		printf("\nTeta(rad): ");
		scanf("%f", &teta);
		printf("\nv(m/s): ");
		scanf("%f", &v);
		printf("\ng(m/s^2): ");
		scanf("%f", &g);
	
		tx = Dx/(v*sin(teta));
		Dy = (tx*(g*tx + 2*v*cos(teta)))/2;
		
		printf("\nDy(m) = %f\n\n", Dy);
	}
	else if (menu == 8){
		system("cls");
		goto start_menu;
	}
	else if (menu == 9){
		return 0;
	}
	else {
		printf("\nIllegal selection!\n\n");
		goto start_menu;
	}
		
	goto start_menu;
		
}
	

