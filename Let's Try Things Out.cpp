#include <iostream>

using namespace std;

typedef struct LinkedList 
{
	LinkedList* pointed_backward;
	LinkedList* pointed_forward;
	int value;
}
Link;

Link list_link(Link* x, Link* y, int z)
{
	Link m = { x , y , z };
	return m;
}

Link list_link_alt(Link* x, int y, int z)
{
	Link m = { x+(y-1) , 0 , z };
	return m;
}

int number_of_occupied_array(Link x[] , int y)
{
	int iter = 0;
	for (int i = 0; i < y; i++)
	{
		if (x[i].value > 0)
			iter++;
	}
	return iter;
}

void link(Link* x, Link* y)
{
	x->pointed_forward = y;
}

int main()
{
	Link a[6];

	// Function that add a new link to the current linked list ( default : 0, 0, 1 )
	a[0] = list_link(0, 0, 1);

	// Function that add a new link to the current linked list ( Insert from the last )
	a[1] = list_link_alt(a , number_of_occupied_array(a,sizeof(a)/sizeof(a[0])) , 2);

	// Linking the back and forth
	link(a, a+1);

	// Test run 2
	a[2] = list_link_alt(a, number_of_occupied_array(a, sizeof(a) / sizeof(a[0])), 3);

	link(a + 1, a + 2);

	// If everything gets a 2, it means that the linked list is success
	cout << a[1].value << endl;
	cout << (a[0].pointed_forward)->value << endl;
	cout << (a[2].pointed_backward)->value;

}

