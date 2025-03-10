# 2D Pandemic Simulator

This project is a 2D Pandemic Simulator implementation that demonstrates inheritance and polymorphism concepts in C++.

## Project Structure

- **src/**: Contains the main source code for the pandemic simulator
- **lib/**: Stanford Graphics Library (SGL) - a graphics library used for visualization
- **res/**: Resource files (images, data files, etc.)
- **output/**: Generated output files and program results

## Dependencies

- C++11 or higher
- Qt5 (Widgets, Multimedia, Network components)
- pthread library

## Build Instructions

### Using CMake

```bash
mkdir build
cd build
cmake ..
make
```

The executable will be created in the project root directory.

### Using Qt/qmake

```bash
qmake
make
```

## Usage

Run the generated executable from the project root directory:

```bash
./StarterProject
```

## Technical Details

- This project uses the Stanford Graphics Library (SGL) for GUI components and visualization
- The codebase follows C++11 standards
- The project demonstrates OOP concepts including inheritance and polymorphism in the context of a pandemic simulation

## Project Configuration

- The build system is configured to treat warnings as errors for better code quality
- Main function is renamed internally to avoid conflicts with the library's entry point
- Graphics components include various interactive elements (buttons, canvas, checkboxes, etc.)

## License

See LICENSE file for details.
