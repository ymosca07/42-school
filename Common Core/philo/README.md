*This project has been created as part of the 42 curriculum by yamosca-.*

## Description
**Philosophers** is a project designed to resolve a classic concurrency problem: the *Dining Philosophers Problem*. The objective is to understand the fundamentals of threading a process, sharing resources, and synchronizing workflows using mutexes.

The simulation features a set of philosophers sitting around a table with a big bowl of spaghetti. There are as many forks as philosophers. To eat, a philosopher must take both their left and right forks. The challenge lies in managing threads so that philosophers alternate smoothly between eating, sleeping, and thinking without encountering a **deadlock** (unresolvable mutual blocking) or **starvation** (a philosopher dying of hunger due to timing inequalities).

## Instructions

### Compilation
The project compiles into an executable using a provided Makefile. Run the following command at the root of the repository:

Execution

The program accepts 4 or 5 arguments:
Bash

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

    number_of_philosophers: The number of philosophers and forks.

    time_to_die (in milliseconds): If a philosopher doesn't start eating within this timeframe since their last meal (or the start of the simulation), they die.

    time_to_eat (in milliseconds): The time it takes for a philosopher to eat while holding two forks.

    time_to_sleep (in milliseconds): The time a philosopher spends sleeping.

    number_of_times_each_philosopher_must_eat (optional): If all philosophers eat at least this many times, the simulation stops properly. If not specified, it stops only upon a death.

Example
Bash

./philo 5 800 200 200

## Resources

### Documentation & References

    POSIX Threads: pthread library documentation and standard Unix man pages (pthread_create, pthread_join, pthread_mutex_init, pthread_mutex_lock).

    Concurrency Theory: Classical academic documentation on the Dining Philosophers Problem (Dijkstra's synchronization problem).

    Debugging Tools: Valgrind suite (Memcheck for memory allocation tracking and Helgrind/DRD for detecting data races and deadlocks).
