#include <stdio.h>
struct Time {
	int hour;
	int minute;
	int second;
};
int main() {
	struct Time now, next;
	printf("Please enter the time now (h m s):");
	scanf("%d%d%d", &now.hour, &now.minute, &now.second);

	next.hour = (now.hour + 1) % 24;
	next.minute = now.minute; 
	next.second = now.second;

	printf("The time in 1 hour will be: %d:%d:%d\n",
		next.hour, next.minute, next.second);
}
