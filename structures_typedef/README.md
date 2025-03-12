DOGSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS


 README.md for Structures and Typedef Project

# 🐶 Structures and Typedef in C

This project covers **structures (`struct`) in C**, including their **initialization, printing, memory allocation, and deallocation**.  
It also introduces **typedef (`dog_t`)** to simplify structure usage.

---

## 📂 **Project Structure**

holbertonschool-low_level_programming │── structures_typedef │ ├── dog.h # Header file containing struct and function prototypes │ ├── 0-main.c # Tests struct dog definition │ ├── 1-init_dog.c # Initializes a struct dog │ ├── 1-main.c # Tests init_dog function │ ├── 2-print_dog.c # Prints a struct dog │ ├── 2-main.c # Tests print_dog function │ ├── 3-main.c # Tests typedef dog_t │ ├── 4-new_dog.c # Creates a new dog_t dynamically │ ├── 4-main.c # Tests new_dog function │ ├── 5-free_dog.c # Frees memory for a dog_t │ ├── 5-main.c # Tests free_dog function │ ├── README.md # Project documentation


---

## 🚀 **Tasks Overview**

### ✅ **Task 0: Define `struct dog`**
- **File:** `dog.h`
- **Description:** Defines a struct `dog` with `name`, `age`, and `owner`.
- **Prototype:**
  ```c
  struct dog
  {
      char *name;
      float age;
      char *owner;
  };

    Compilation & Execution:

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c -o a
./a

Expected Output:

    My name is Poppy, and I am 3.5 :) - Woof!

✅ Task 1: Initialize struct dog

    Files: dog.h, 1-init_dog.c, 1-main.c
    Prototype:

void init_dog(struct dog *d, char *name, float age, char *owner);

Compilation & Execution:

    gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-init_dog.c -o b
    ./b

✅ Task 2: Print struct dog

    Files: dog.h, 2-print_dog.c, 2-main.c
    Prototype:

void print_dog(struct dog *d);

Compilation & Execution:

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-print_dog.c -o c
./c

Expected Output:

    Name: Poppy
    Age: 3.500000
    Owner: Bob

✅ Task 3: Define dog_t as typedef struct dog

    Files: dog.h, 3-main.c
    Prototype:

typedef struct dog dog_t;

Compilation & Execution:

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c -o d
./d

Expected Output:

    My name is Poppy, and I am 3.5 :) - Woof!

✅ Task 4: Create a New dog_t

    Files: dog.h, 4-new_dog.c, 4-main.c
    Prototype:

dog_t *new_dog(char *name, float age, char *owner);

Compilation & Execution:

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 4-new_dog.c -o e
./e

Expected Output:

    My name is Poppy, and I am 3.5 :) - Woof!

✅ Task 5: Free dog_t Memory

    Files: dog.h, 5-free_dog.c, 5-main.c, 4-new_dog.c
    Prototype:

void free_dog(dog_t *d);

Compilation & Execution:

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-free_dog.c 4-new_dog.c -o f
./f

Expected Output:

My name is Poppy, and I am 3.5 :) - Woof!

Memory Leak Check using Valgrind:

valgrind ./f

✅ Expected Valgrind Output:

    == HEAP SUMMARY ==
    All heap blocks were freed -- no leaks are possible

📌 Additional Notes
📝 Memory Management

    Functions like new_dog allocate memory dynamically using malloc().
    free_dog ensures that all allocated memory is properly freed to prevent memory leaks.

🔥 Error Handling

    Checks for NULL before dereferencing pointers to prevent segmentation faults.