*This project has been created as part of the 42 curriculum by randrade.*

# so_long

*Rank 02 — a small 2D game, and the first project with a window.*

## Description

so_long reads a map from a `.ber` file, opens a window, and lets you walk a character
around it with the keyboard. Collect every collectible, then reach the exit. Each move
prints the running move count to the shell.

The graphics come from **MiniLibX**, the school's minimal X11 wrapper — it gives you a
window, an event loop, and the ability to blit an image, and nothing else. There is no
sprite system, no collision engine, no scene graph. Drawing the map means looping over
the grid and putting one 64×64 XPM tile per cell, every frame you care to redraw.

Most of the actual work, though, is in the parsing. Before a window ever opens the
program has to reject every malformed map the subject enumerates: wrong extension,
empty file, non-rectangular, not surrounded by walls, illegal characters, the wrong
number of players or exits, and — the interesting one — a map where the collectibles
or the exit are walled off from the player. That last check is a flood fill.

Three tile sets ship with the project, selected by the five `*_PATH` defines at the top
of `so_long.h`. The active one is **Nala** (32×32): the player is Nala, the
collectibles are balls, the walls are trees, the floor is grass, and the exit is a
portal. The alternatives are **42** (64×64 — a duck, 42 logos, rocks, water, a black
hole) and **Pirate** (64×64), both listed in the comment block at the bottom of the
header.

## Instructions

### Prerequisites

- `cc`, `make`
- **On Linux:** X11 development headers (`libx11-dev`, `libxext-dev` on
  Debian/Ubuntu)
- **On macOS:** the Xcode command line tools (AppKit and OpenGL ship with them)

### Build

```sh
make          # auto-detects the host
make linux    # force the X11 build
make mac      # force the Cocoa/OpenGL build
```

Both MiniLibX variants are vendored, so there is nothing to install. `make` picks the
platform from `uname -s`; `make linux` and `make mac` override it.

The two builds keep their objects in separate directories (`src/obj/linux` and
`src/obj/mac`), so switching platforms never reuses stale objects and no `fclean` is
needed in between.

### Makefile targets

| Target        | Effect                                                      |
|---------------|-------------------------------------------------------------|
| `make`        | Build for the detected host (same as `all`)                  |
| `make linux`  | Force the Linux/X11 build                                    |
| `make mac`    | Force the macOS/Cocoa build                                  |
| `make clean`  | Remove object files here, in `Library/` and in MiniLibX      |
| `make fclean` | `clean` + remove `so_long` and `libft.a`                     |
| `make re`     | `fclean` then `all`                                          |

### Usage

```sh
./so_long maps/valid/classic.ber
```

Run it from the repository root — the texture paths in `so_long.h` are relative to the
working directory, not to the binary.

| Key | Action |
|-----|--------|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `ESC` | Quit cleanly |

Clicking the window's close button also exits cleanly. Walls block movement; the exit
stays shut until every collectible is picked up.

### Platform

The two platforms differ in three places, all driven by a single `-D SO_LONG_MAC` /
`-D SO_LONG_LINUX` define that the Makefile passes:

| | Linux | macOS |
|---|---|---|
| MiniLibX | `minilibx/mlx_linux/` | `minilibx/mlx/` |
| Link flags | `-lXext -lX11` | `-framework OpenGL -framework AppKit` |
| Keycodes | X11 (`ESC` = `65307`) | Cocoa (`ESC` = `53`) |

`so_long.h` selects the right MiniLibX header and keycode block from that define, and
`src/mlx_compat.c` absorbs the two functions the macOS MiniLibX does not provide (see
[Implementation notes](#implementation-notes)). Nothing needs uncommenting.

## Map format

A `.ber` file is a rectangular grid of five characters:

| Char | Meaning |
|------|---------|
| `0` | Empty floor |
| `1` | Wall |
| `C` | Collectible |
| `E` | Exit |
| `P` | Player start |

```
1111111111111
1001000000001
1000011111011
1P00011E00001
1111111111111
```

A map is valid only if it is rectangular, fully enclosed by walls, contains exactly one
`P` and one `E` and at least one `C`, uses no other characters, and has a path from the
player to every collectible and to the exit. Anything else exits with `Error\n`
followed by a specific description — `Map not rectangle!`, `Not winnable!`,
`Not a *.ber file!`, and so on.

`maps/valid/` holds eight playable maps from a 5×3 minimum up to a labyrinth;
`maps/invalid/` holds ten that each trip a different check, including a wrong
extension and a doubled `.ber.ber`.

## Project structure

```
so_long/
├── Makefile
├── src/
│   ├── so_long.h         # all structs, error strings, keycodes, texture paths
│   ├── so_long.c         # entry point: parse, then open the window
│   ├── check_file.c      # extension and readability checks
│   ├── alloc_map.c       # reads the file into a char ** with get_next_line
│   ├── map_parsing.c     # rectangularity, walls, content counts
│   ├── parsing_utils.c   # per-character counting, wall checks, flood fill
│   ├── draw_map.c        # XPM loading and tile blitting
│   ├── key_handler.c     # movement, collection, exit condition
│   ├── run_game_utils.c  # move counter, player position, screen-size guard
│   ├── error_handling.c  # the Error\n paths
│   ├── exit_handling.c   # clean teardown
│   ├── mlx_compat.c      # the two Linux-only MiniLibX calls, shimmed for macOS
│   └── utils.c
├── maps/
│   ├── valid/            # 8 playable maps
│   └── invalid/          # 10 maps, each failing a different validation rule
├── textures/
│   ├── Nala_32x32/       # the active theme (recovered from git history)
│   ├── 42_64x64/         # the duck theme
│   └── Pirate_64x64/     # a third theme
├── Library/              # libft + ft_printf + get_next_line
└── minilibx/             # vendored MiniLibX, both the Linux and macOS variants
```

## Implementation notes

- **Validation is a pipeline, and it runs before any window opens.** File extension,
  then readability, then the grid is read in, then shape and walls and content counts,
  and only then the reachability check. Every stage exits with its own message, so a
  rejected map tells you *which* rule it broke rather than just `Error`.
- **Reachability is a recursive flood fill on a copy.** `ft_flood_fill` marks visited
  cells with `'F'`, which destroys the map as it goes — so it runs against a duplicate
  made by `ft_array_dup`, leaving the real grid intact for the game. It counts
  collectibles as it spreads and sets `exit_reached`, so one traversal answers both
  "can the player reach everything?" and "can the player reach the door?".
- **The fill bounds-checks before it dereferences.** The guard clause is the first
  thing in the function, so a coordinate off the edge of the grid returns without ever
  touching `map[y][x]`. Walking off the top or left wraps the `unsigned` coordinate to
  a huge value, which the same `>= size` comparison catches — so the traversal is safe
  on its own terms rather than relying on the enclosing wall to stop it.
- **The exit is a state, not a tile swap.** `t_exit.is_open` flips once the collected
  count matches the total; the movement functions check it before allowing a step onto
  `E`. Walking into a closed exit is simply a rejected move.
- **Both WASD and the arrow keys are bound**, which the subject offers as an option.
  Keycodes live in `so_long.h` as named constants precisely because they are
  platform-specific.
- **The platform gap is two functions wide, and it lives in one file.** The macOS
  MiniLibX has no `mlx_destroy_display` (there is no X display to close) and no
  `mlx_get_screen_size`. Rather than scatter `#ifdef`s through the teardown and the
  size check, `mlx_compat.c` wraps both behind `ft_`-prefixed names and picks an
  implementation at file scope. On macOS the display teardown is a no-op — the caller
  still `free()`s the mlx pointer, which is the whole job there.
- **`ft_check_screen_map_size` guards against oversized maps.** A grid larger than the
  display would create a window you cannot use, so it is rejected up front with
  `Map too large!` rather than opening something unusable.
- **Every allocation has a matching teardown path.** `ft_perror_free_exit` and
  `ft_fderror_free_exit` take the map array along with the message, so a failure
  midway through setup still frees what has been built so far.

### Known limitations

- **The screen-size guard does not work on macOS.** The macOS MiniLibX exposes no way
  to query the display, so `ft_mlx_get_screen_size` reports `INT_MAX` and the check
  never fires. A map larger than the screen is rejected with `Map too large!` on Linux
  but opens an oversized window on macOS — `maps/invalid/big.ber` is exactly that case.
- **The flood fill is recursive, one frame per cell.** On a very large open map that is
  a deep call stack. The `Map too large!` guard bounds it in practice, but the bound is
  the screen size, not the recursion depth.
- **Texture paths are relative to the working directory**, so running the binary from
  anywhere other than the repository root fails to load images.
- **`IMG_RES` is not tied to the active theme.** It is a fixed `64`, but it is used as
  both the window-sizing factor and the blit pitch — so with the 32×32 Nala set every
  tile is drawn into the top-left quarter of a 64-pixel cell, leaving gaps, and the
  window comes out twice the size the art needs. Switching to Nala also means setting
  `IMG_RES` to `32`.
- **Two of the three tile sets are always unused.** The subject forbids turning in
  unused files, and the theme is picked by editing five `#define`s rather than by a
  build flag.
- **No bonus part.** Enemy patrols, sprite animation, and on-screen move count were not
  attempted.

## Resources

- MiniLibX man pages under [`minilibx/mlx_linux/man/`](minilibx/mlx_linux/man/)
- [Flood fill](https://en.wikipedia.org/wiki/Flood_fill) — the reachability check
- [`so_long.pdf`](../../../../Subjects/Rank_2/so_long.pdf) — the project subject
- [Libft](../../Rank_0/Libft), [ft_printf](../../Rank_1/ft_printf), [get_next_line](../../Rank_1/get_next_line) — bundled in `Library/`
