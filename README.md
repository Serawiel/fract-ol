*This project has been created as part of the 42 curriculum by [your_login].*

# fract-ol

> Infinite mathematical beauty — fractal exploration in C.

## Description

fract-ol is an interactive fractal explorer built in C with the MiniLibX library. It renders fractals in real time using complex number mathematics and lets the user navigate and explore them with the mouse and keyboard.

Fractals supported:
- **Mandelbrot set** — `./fractol mandelbrot`
- **Julia set** — `./fractol julia <real> <imaginary>` (e.g. `./fractol julia -0.7 0.27`)

Features:
- Mouse wheel zoom (centered on cursor)
- Arrow key navigation
- Color palette shifting
- Smooth window management (ESC or window close to exit)

## Instructions

**Prerequisites:** MiniLibX must be installed on your system.

On Linux:
```bash
# Install MiniLibX dependencies
sudo apt-get install libx11-dev libxext-dev libbsd-dev

# Clone and build (MiniLibX sources included in the repo)
git clone [your_repo] && cd [your_repo]
make
```

On macOS:
```bash
# MiniLibX is available via the school machines or from sources
git clone [your_repo] && cd [your_repo]
make
```

**Run:**
```bash
./fractol mandelbrot
./fractol julia -0.4 0.6
./fractol julia -0.7 0.27
```

If no argument or an invalid one is provided, the program displays available options and exits cleanly.

## Resources

- [Mandelbrot set — Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia set — Wikipedia](https://en.wikipedia.org/wiki/Julia_set)
- [Complex number arithmetic](https://mathworld.wolfram.com/ComplexNumber.html)
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [MiniLibX sources — 42 GitHub](https://github.com/42Paris/minilibx-linux)
- [Smooth coloring algorithm](https://www.iquilezles.org/www/articles/mset_smooth/mset_smooth.htm)
- **AI usage:** Claude was used to clarify the smooth coloring formula and complex number iteration logic. All rendering and event handling were implemented manually.