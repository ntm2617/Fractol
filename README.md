# 🌌 Fract-ol: Mathematical Fractal Rendering

*This project was created as part of the 42 curriculum.*

This Fract-ol project is a 2D graphical rendering program built in C. It uses complex number mathematics to generate and explore infinite fractal shapes, specifically the Mandelbrot and Julia sets. This project utilizes MiniLibX, the school's internal graphical library. MiniLibX provides the essential tools needed to render windowed graphics, manipulate pixels, and handle user interactions via keyboard and mouse events.

## 🛠️ Technologies

* **Language:** C
* **Graphics Library:** MiniLibX (school's internal graphical library)
* **Compilation:** Custom `Makefile` with cc flags (`-Wall -Wextra -Werror`)
* **Math:** `<math.h>` used for trigonometric functions (`sin`) to produce smooth periodic color gradients.
---

## 🚀 Features

* **Dual Fractal Engines:** Real-time generation of both the Mandelbrot set and Julia sets.
* **Cursor-Tracking Zoom:** Interactive zoom mapped to the mouse scroll wheel that dynamically centers on the cursor position rather than the viewport center.
* **Spatial Navigation:** Viewport panning mapped to the directional arrow keys to move across the complex plane.
* **Custom Parameters:** Supports customizable Julia sets by passing specific real and imaginary numbers via the command line. (e.g. `./fractol julia -0.8 0.156`).
* **Periodic Color Palette:** Smooth, sinusoidal RGB color mapping that reveals the mathematical depth and iteration boundaries of each fractal.

---

## 🧠 The Process (How It Works)

* **Coordinate Scaling:** Translates $800 \times 800$ screen pixel coordinates into continuous mathematical coordinates on the complex plane.
* **Escape-Time Algorithm:** For each pixel, the program evaluates the complex quadratic recurrence:
  $$Z_{n+1} = Z_n^2 + c$$
  The loop iterates until the point escapes the bailout radius ($|Z| \ge 2 \iff x^2 + y^2 \ge 4$) or hits the maximum iteration count (this project uses 50).
* **Fast Framebuffer Rendering:** Instead of issuing slow per-pixel draw calls with `mlx_pix_put`, the program calculates raw memory offsets directly in the MiniLibX image buffer before pushing the entire frame to the window in a single pass.

---

## ⚙️ How to Run the Project

### 1. Compile the Program
Ensure you have the MiniLibX dependencies installed, then run the `Makefile` from the root directory:

```bash
make
```

### 2. Execution Commands
Launch the program by specifying the fractal type as an argument.

**Mandelbrot set:**
```bash
./fractol mandelbrot
```

**Julia set:**
Provide a complex parameter (a real and an imaginary number):
```bash
./fractol julia -0.4 0.6
./fractol julia -0.8 0.156
./fractol julia -0.7269 0.1889
```

### 3. Controls

| Input | Action |
| :--- | :--- |
| **Mouse Wheel Up / Down** | Zoom in / out towards mouse pointer position |
| **Arrow Keys** | Move Left, Right, Up, Down |
| **ESC Key or Window Cross (X)** | Clean exit (destroys images/windows and frees memory) |

---

## 📈 How it can be improved?

* **Dynamic Iteration Scaling:** Automatically increasing the maximum iteration count as zooming deeper to preserve boundary sharpness.
* **Color Palette Switching:** Adding keyboard hooks (e.g., the `C` or `SPACE` key) to switch dynamically between multiple color palettes during runtime.
* **Additional Fractals:** Implementing equations for other complex fractals like the Burning Ship, Tricorn, or Newton fractals.
* **Multi-threading:** Utilizing `pthreads` to divide the screen rendering across multiple CPU cores, which would significantly increase the frame rate during deep zooms where the iteration count is high.

### Pictures
**Mandelbrot set:**

<img width="811" height="832" alt="Screenshot 2026-10-07 153949" src="https://github.com/user-attachments/assets/922c52df-4014-4ee8-ad7b-44d5ec2d32b6" />

**Julia set:**

<img width="812" height="833" alt="Screenshot 2026-10-07 154131" src="https://github.com/user-attachments/assets/8f5f5123-e834-43b3-8274-020872a0c4cd" />

### 🎥 Video


https://github.com/user-attachments/assets/50ee2a53-237d-4b62-a0ed-f16ccfd9a0ab

