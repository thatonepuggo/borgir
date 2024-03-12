#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "colors.h"
#include "ingredients.c"

const char FORMAT[] = "%s\n";

#define NUM_INGREDIENTS 11

#define ISARG(x) (strcmp(argv[i], x) == 0)

#define DEFAULTS_SIZE 8

typedef struct {
  const char* name;
  const char* value;
  const char* fmt; // only one formatter cuz c is funny and memory allocation is hard
} Ingredient;

const Ingredient INGREDIENTS[NUM_INGREDIENTS] = {
  {
    .name = "crown",
    .value = CROWN,
  },
  {
    .name = "bottom",
    .value = BOTTOM,
  },
  {
    .name = "lettuce",
    .value = LETTUCE,
  },
  {
    .name = "pickles",
    .value = PICKLES,
  },
  {
    .name = "cheese",
    .value = CHEESE,
  },
  {
    .name = "beef",
    .value = BEEF,
  },
  {
    .name = "ketchup",
    .value = SAUCE,
    .fmt = RED,
  },
  {
    .name = "mustard",
    .value = SAUCE,
    .fmt = YELLOW,
  },
  {
    .name = "mayo",
    .value = SAUCE,
    .fmt = WHITE,
  },
  {
    .name = "please",
    .value = PLEASE,
  },
  {
    .name = "cookie",
    .value = COOKIE,
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

void defaultBorgir(void);

int countFormatters(const char *str) {
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '%' && str[i + 1] != '%') {
            count++;
        }
        i++;
    }

    return count;
}

void printBorgir(int argc, const char* argv[], bool recursiveBorgir) {
  int startI = 0;
  if (recursiveBorgir) startI = 1;
  for (int i = startI; i < argc; ++i) {
    for (int ing = 0; ing < NUM_INGREDIENTS; ++ing) {
      // ingredient
      Ingredient ingredient = INGREDIENTS[ing];

      if (ISARG(ingredient.name)) {
        if (ingredient.fmt != NULL) {
          printf("%s%s\n", ingredient.fmt, ingredient.value);
        } else {
          printf("%s\n", ingredient.value);
        }
        break;
      }
    }

    // special command that adds the default borgir
    if (ISARG("borgir") && recursiveBorgir) defaultBorgir();

    printf("%s", RESET);
  }
}

void defaultBorgir(void) { printBorgir(DEFAULTS_SIZE, DEFAULTS, false); }

int main(int argc, const char* argv[]) {
  if (argc > 1) {
    printBorgir(argc, argv, true);
  } else {
    defaultBorgir();
  }

  return 0;
}
