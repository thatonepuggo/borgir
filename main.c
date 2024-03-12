#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "colors.h"
#include "ingredients.c"

const char FORMAT[] = "%s%s\n";

#define NUM_FORMATS 10
#define NUM_INGREDIENTS 11

#define ISARG(x) (strcmp(argv[i], x) == 0)
#define BUFFER_SIZE 1024

#define DEFAULTS_SIZE 8

typedef struct {
  char* name;
  char* value;
  char* fmt[NUM_FORMATS];
} Ingredient;

const Ingredient INGREDIENTS[NUM_INGREDIENTS] = {
  {
    .name = "crown",
    .value = CROWN,
    .fmt = {ORANGE}
  },
  {
    .name = "bottom",
    .value = BOTTOM,
    .fmt = {ORANGE}
  },
  {
    .name = "lettuce",
    .value = LETTUCE,
    .fmt = {GREEN}
  },
  {
    .name = "pickles",
    .value = PICKLES,
    .fmt = {GREEN}
  },
  {
    .name = "cheese",
    .value = CHEESE,
    .fmt = {YELLOW}
  },
  {
    .name = "beef",
    .value = BEEF,
    .fmt = {BROWN}
  },
  {
    .name = "ketchup",
    .value = SAUCE,
    .fmt = {RED}
  },
  {
    .name = "mustard",
    .value = SAUCE,
    .fmt = {YELLOW}
  },
  {

    .name = "mayo",
    .value = SAUCE,
    .fmt = {WHITE}
  },
  {
    .name = "please",
    .value = PLEASE,
    .fmt = {RESET}
  },
  {
    .name = "cookie",
    .value = COOKIE,
    .fmt = {DARK_BROWN, TAN, DARK_BROWN, TAN, DARK_BROWN, TAN, DARK_BROWN, TAN}
  },
};


const char* DEFAULTS[DEFAULTS_SIZE] = {
  "crown",
  "lettuce",
  "pickles",
  "cheese",
  "beef",
  "ketchup",
  "mustard",
  "bottom",
};

void printBorgir(int argc, char* argv[], bool recursiveBorgir) {
  for (int i = 0; i < argc; ++i) {
    for (int ing = 0; ing < NUM_INGREDIENTS; ++ing) {
      // ingredient
      Ingredient ingredient = INGREDIENTS[ing];
      if (strcmp(argv[i], ingredient.name) == 0) {
        // make the buffer
        char buffer[BUFFER_SIZE];
        snprintf(buffer, sizeof(buffer), FORMAT, ingredient.fmt[0], ingredient.value);

        // loop through the ingredient formatters and apply them
        for (int index = 1; index < NUM_FORMATS && ingredient.fmt[index] != NULL; ++index) {
          char tempBuffer[BUFFER_SIZE];
          snprintf(tempBuffer, sizeof(tempBuffer), FORMAT, ingredient.fmt[index], ingredient.value);
          strncat(buffer, tempBuffer, sizeof(buffer) - strlen(buffer) - 1);
        }

        // print the buffer finally
        printf(buffer);
        break;
      }
    }
    if (ISARG("borgir") && recursiveBorgir) borgir();

    printf("%s", RESET);
  }
}

void borgir() { printBorgir(DEFAULTS_SIZE, DEFAULTS, false); }

int main(int argc, char* argv[]) {
  if (argc > 1) {
    printBorgir(argc, argv, true);
  } else {
    borgir();
  }

  return 0;
}
