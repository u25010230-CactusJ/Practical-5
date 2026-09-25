# CampusGuard: Emergency Response Coordination

## 1. Project Overview

CampusGuard is an emergency-response coordination platform designed for a large university campus.

The system coordinates campus security, medical responders, access-control services and communication systems during emergency incidents. It demonstrates how multiple Gang of Four design patterns can work together as one coherent application.

The system supports:

- Registering and managing emergency incidents.
- Changing the operational state of an incident.
- Dispatching campus security and medical responders.
- Restricting or unlocking building access.
- Broadcasting emergency alerts.
- Coordinating response components through a mediator.
- Integrating a legacy public-address system through an adapter.
- Executing high-level emergency workflows through a facade.
- Undoing operator actions represented as commands.

## 2. Design Patterns

The project uses the following six Gang of Four patterns:

- **Command** – represents operator actions as objects and supports undo operations.
- **Mediator** – coordinates communication between response services.
- **Adapter** – integrates the incompatible legacy public-address system.
- **Facade** – provides a simplified interface for multi-step emergency workflows.
- **State** – manages the operational state and behaviour of incidents.
- **Observer** – allows interested components to be notified when incident status changes.

## 3. Technologies and Requirements

The project is implemented using:

- C++11
- GNU Make
- Docker
- Docker Compose
- Git/GitHub

The Docker environment also includes:

- GDB
- Valgrind

## 4. Team Contributions (A toast to greatness!!)

### Tendai

- Task 1: Scenario analysis and system design
- Adapter implementation
- Facade implementation
- UML class diagram
- Two sequence diagrams
- Testing and integration for Task 6

### Munashe

- State implementation
- Observer implementation
- One end-to-end scenario
- UML state diagram
- Testing and integration for Task 6

### Lesego

- Command implementation
- Mediator implementation
- One end-to-end scenario
- Task 5 engineering requirements
- Testing and integration for Task 6

## 5. Building Locally

The project uses the provided Makefile.

To compile:

```
make
```

This produces the executable:

```
campusguard
```

To remove compiled files:

```
make clean
```

## 6. Running the Application

After compiling locally:

```
./campusguard
```

The assessed demonstration must, however, be launched using Docker.

## 7. Running with Docker

Build and start the application using:

```
docker compose up --build
```

This builds the Docker image, compiles the application inside the container and starts CampusGuard.

To stop the application:

```
docker compose down
```

## 8. Valgrind

The Makefile provides a Valgrind target:

```
make valgrind
```

Valgrind is used to identify memory leaks and invalid memory operations.

The project follows a clear ownership policy for dynamically allocated command objects. The OperatorControlPanel owns commands stored in its command history and destroys any remaining commands when the panel is destroyed.

## 9. GDB

The Makefile provides a GDB target:

```
make gdb
```

The application is compiled with debugging information using the `-g` compiler option.

GDB was used during development to investigate and document an actual execution bug.

## 10. Git and GitHub Workflow

The team uses a feature-based Git workflow.

- `main` – final stable version.
- `dev` – shared integration branch.
- `test/tendai` – Tendai's testing branch.
- `test/munashe` – Munashe's testing branch.
- `test/lesego` – Lesego's testing branch.
- `feat/<feature>` – individual feature-development branches.

Feature work is developed on `feat/*` branches, tested on the appropriate `test/*` branch, and then integrated into `dev`. Once the complete system has been tested and approved, `dev` will be merged into `main`.

## 11. Repository

GitHub repository:

https://github.com/u25010230-CactusJ/Practical-5.git

The repository contains the source code, tests, documentation, build configuration and development history.