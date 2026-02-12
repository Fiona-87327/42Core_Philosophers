
# 42Core_Philosophers

A project about the classic **Dining Philosophers Problem**, part of the 42 Core Curriculum. This project focuses on the basics of process threading, mutexes, and how to avoid data races and deadlocks.

## 📖 Overview

The problem involves a number of philosophers sitting at a round table with a large bowl of spaghetti in the middle. The philosophers spend their time eating, thinking, and sleeping.
- There are as many forks as there are philosophers.
- A philosopher needs two forks to eat (the left and the right one).
- When a philosopher finishes eating, they put their forks back on the table and start sleeping.
- Once they wake up, they start thinking.
- The simulation stops if a philosopher dies of starvation.

The goal is to keep everyone alive as long as possible!

## 🛠️ Features

- **Threads**: Each philosopher is represented by a thread.
- **Mutexes**: Used to protect the state of the forks and prevent data races when printing or checking for death.
- **Monitoring**: A dedicated monitor thread ensures that the simulation stops immediately if a philosopher dies or if all philosophers have eaten enough.
- **Precision**: Uses custom microsecond-precision sleep and timing functions.

## 🚀 Getting Started

### Prerequisites

- A C compiler (like `cc` or `gcc`).
- `make` utility.
- A Unix-based system (Linux/macOS) for thread support (`pthread`).

### Compilation

Navigate to the `philo` directory and run:

```bash
cd philo
make
```

This will generate an executable named `philo`.

### Usage

Run the program with the following arguments:

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

- **number_of_philosophers**: The number of philosophers and also the number of forks. (Max: 200)
- **time_to_die** (ms): If a philosopher hasn't started eating within this time since their last meal or the start of the simulation, they die.
- **time_to_eat** (ms): The time it takes for a philosopher to eat.
- **time_to_sleep** (ms): The time a philosopher spends sleeping.
- **number_of_times_each_philosopher_must_eat** (optional): If all philosophers have eaten at least this many times, the simulation stops.

**Example:**
```bash
./philo 5 800 200 200
```

## 🧪 Debugging

The `Makefile` includes a shortcut for running the simulation under **Valgrind's Helgrind** tool to check for data races:

```bash
make v
```

## 📜 Project Structure

- `philo.c`: Main entry point and argument validation.
- `init.c`: Initialization of the program, philosophers, and mutexes.
- `thread.c`: Creation and joining of philosopher and monitor threads.
- `aktion.c`: Logic for philosopher actions (eating, sleeping, thinking).
- `monitor.c`: Logic for monitoring philosopher deaths and meal counts.
- `utils.c`: Helper functions for timing and string conversion.
- `philo.h`: Header file with structures and function prototypes.

---
Developed by **jiyawang** as part of the 42 project.
