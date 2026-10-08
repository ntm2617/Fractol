# Fract-ol: Mathematical Fractal Rendering

*This project has been created as part of the 42 Bangkok curriculum.*

This Fract-ol project is a 2D graphical rendering program built in C. It uses complex number mathematics to generate and explore infinite fractal shapes, specifically the Mandelbrot and Julia sets. This project utilizes MiniLibX, the school's internal graphical library. MiniLibX provides the essential tools needed to render windowed graphics, manipulate pixels, and handle user interactions via keyboard and mouse events."

##  Visual Demos
A Julia set where the complex parameter c is equal to -0.4 + 0.6i:
<img width="812" height="833" alt="Screenshot 2026-10-07 154131" src="https://github.com/user-attachments/assets/0e3f05c3-7ba6-4104-8e2b-611831cdb39c" />

Mandelbrot set
<img width="811" height="832" alt="Screenshot 2026-10-07 153949" src="https://github.com/user-attachments/assets/a121bc21-aa6d-405a-8506-5838998fa560" />


## Features & Controls
*   **Dual Fractal Engines:** Generates both the Mandelbrot set and highly customizable Julia sets.
*   **Interactive Zoom:** Infinite zoom functionality mapped to the **mouse scroll wheel**, allowing deep exploration of fractal edges.
*   **Spatial Navigation:** Viewport panning mapped to the **arrow keys** (Left, Right, Up, Down) to move fluidly around the complex plane.
*   **Dynamic Calculation:** Renders pixels mathematically in real-time based on coordinate scaling.

## Compilation & Usage

### 1. Compile the Program
The project includes a `Makefile` for clean compilation. Run this command to build the executable:
```bash
make
```
### 2. Execution Commands
```bash
./fractol mandelbrot
```
or
```bash
# Example parameters for Julia set:
./fractol julia -0.4 0.6
./fractol julia -0.8 0.156
```
