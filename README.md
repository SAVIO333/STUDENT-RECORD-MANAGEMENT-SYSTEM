# Student Record Management System

A menu-driven C application that manages student records using a **singly linked list**, **dynamic memory allocation**, **modular programming**, and **file handling**.

## Project Structure
- `student.h` — Structure definition (`struct student`) and function prototypes.
- `stud_main.c` — Main menu loop, startup loading, and exit handling.
- `stud_add.c` — Adds a new student with the smallest unused positive roll number.
- `stud_del.c` — Deletes a record by roll number or name.
- `stud_show.c` — Displays all student records in tabular format.
- `stud_mod.c` — Searches by roll number, name, or percentage to update records.
- `stud_save.c` — Saves records to `student.dat` and restores them at startup.
- `stud_sort.c` — Sorts records alphabetically by name or descending by percentage.
- `stud_delall.c` — Frees all nodes from memory.
- `stud_revlink.c` — Reverses the singly linked list in-place.

## Compilation
Compile all `.c` source files together into an executable named `student`:

```bash
gcc *.c -o student
```

## Execution
Run the compiled application:

- **Windows (PowerShell / CMD):**
  ```powershell
  .\student.exe
  ```
- **Linux / macOS:**
  ```bash
  ./student
  ```
