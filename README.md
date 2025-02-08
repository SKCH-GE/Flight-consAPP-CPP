# Flight-consAPP-CPP

## Overview

Flight-consAPP-CPP is a **C++ application** developed using **Qt Creator IDE**. It manages interconnected data for **flights, airports, tickets, and passengers**, providing an efficient way to track and organize information using **Object-Oriented Programming (OOP) principles**.

## Features

- Manages flights, airports, tickets, and passengers
- Implements OOP concepts for modularity and maintainability
- Interconnectivity between classes for efficient data handling

## Classes Used

The project is structured using four main classes:

- **Vol**: Represents flight details
- **Aeroport**: Stores airport-related information
- **Passager**: Manages passenger data
- **Billet**: Represents a ticket and its details

Each class acts as a **blueprint** for managing related data efficiently, making it easier to track and process relevant information.

## Development & Setup

### Prerequisites

Ensure you have **Qt Creator IDE** and a **C++ compiler** installed.

### Compilation & Execution

#### Using Qt Creator

1. Open the project in **Qt Creator**.
2. Build the project using the built-in compiler.
3. Run the application.

#### Using MinGW via Command Line

1. Ensure MinGW is installed and added to your system PATH.
2. Navigate to the project directory in the terminal.
3. Compile the project using the following command:
   ```bash
   g++ -o flight_app *.cpp 
   ```
4. Run the application:
   ```bash
   ./flight_app
   ```

## Future Improvements

- Implement a GUI for better user interaction
- Add database support for persistent data storage
- Optimize class relationships for enhanced performance

## License

This project is open-source and available under the MIT License.

## Contributing

Feel free to contribute by submitting issues, pull requests, or feature suggestions.

