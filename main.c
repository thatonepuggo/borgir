#include <stdio.h>
#include <string.h>
#include "colors.h"
#include "ingredients.c"

void borgir() {
  printf(CROWN, ORANGE);

  printf(LETTUCE, GREEN);
  printf(CHEESE, YELLOW);
  printf(BEEF, BROWN);
  printf(SAUCE, RED);
  printf(SAUCE, YELLOW);

  printf(BOTTOM, ORANGE);

  printf("%s", RESET);
}

#define ISARG(str) (strcmp(argv[i], str) == 0)

int main(int argc, char* argv[]) {
  if (argc > 0) {
	for (int i = 0; i < argc; ++i) {
	  if (ISARG("crown")) {
		printf(CROWN, ORANGE);
	  } else if (ISARG("lettuce")) {
		printf(LETTUCE, GREEN);
	  } else if (ISARG("cheese")) {
		printf(CHEESE, YELLOW);
      } else if (ISARG("beef")) {
		printf(BEEF, BROWN);
	  } else if (ISARG("ketchup")) {
		printf(SAUCE, RED);
	  } else if (ISARG("mustard")) {
		printf(SAUCE, YELLOW);
	  } else if (ISARG("mayo")) {
		printf(SAUCE, WHITE);
	  } else if (ISARG("bottom")) {
		printf(BOTTOM, ORANGE);
	  } else if (ISARG("please")) {
		printf(PLEASE);
	  } else if (ISARG("borgir")) {
		borgir();
	  }
	  printf("%s", RESET);
	}
  } else {
	borgir();
  }

  return 0;
}
