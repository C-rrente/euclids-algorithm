//r-knott.surrey.ac.uk/Fibonacci/cflNTRO.html
#include <iostream>
#include <numeric>
#include <ctime>
#include "/public/colors.h"

using namespace std;

class Tile{
	public:
		int r = 0, g = 0, b = 0;
		int num = 0; //The number it represents
		int num_boxes = 0;
};

void die(){
	cout << "Rectangle doesn't fit my brain yet\n";
	exit(1);
}
vector<Tile> world;


void print_visual(){
	clearscreen();
	resetcolor();
	movecursor(0,0);
	for(Tile t: world){
		//Need to make it so they have some sort of boxes of actual size
		for(int i = 0; i < t.num_boxes; i++){
			setbgcolor(t.r,t.g,t.b);
			if(i == t.num_boxes-1) cout << t.num;
			else cout << t.num << "|";
		}
		cout << endl;
	}
}

void algorithm(int width, int height){
	if(height == 0) return; 
	int new_width = 0;
	int step = width/height; //45/16 -> 2
	int step_result = step*height; //2(16)
	int remainder = width - step_result; //45 - 32 = 13
	Tile a;
	a.num = height;
	a.num_boxes = step;
	a.r = rand() % 200;
	a.g = rand() % 200;
	a.b = rand() % 200;
	world.push_back(a);
	int new_height = remainder;
	algorithm(height, new_height);
}

int main(){
	srand(time(NULL));
	int width = 0;
	int height = 0;
	int rectangle_size = 0;

	system("figlet Welcome to Euclids Dungeon");
	cout << endl << "Please enter the width and height of your rectangle: \n";
	cin >> width >> height;

	if(width > 100 or height > 100) die();
	if(width == height) die();

	rectangle_size = width * height;

	algorithm(width, height);
	print_visual();
	resetcolor();
}	
