  ---
  portfolio: true
  status: completed
  ---

  # Get Next Line

  42 Cursus — Circle 1 project (C / Piscine common core)

  ## Goal

  Write a function, `get_next_line`, that returns one line at a time from a
  file descriptor — including from standard input — without using `fgets`.

  The exercise is really about handling a file of unknown size while reading
  it in small, fixed-size chunks: the function has to keep track, between
  calls, of what has already been read but not yet returned to the caller.

  ## Language & constraints

  - **Language:** C
  - Norm-compliant (42 Norm)
  - No forbidden functions; allowed: `read`, `malloc`, `free`
  - Must not leak memory, must not crash on edge cases (empty file, no
    trailing newline, `BUFFER_SIZE` of 1, huge `BUFFER_SIZE`, invalid `fd`...)
  - `BUFFER_SIZE` is set at compile time with `-D BUFFER_SIZE=n` and the
    function must work correctly for any strictly positive value.

  ## How it works

  `get_next_line(fd)` reads `BUFFER_SIZE` bytes at a time from `fd` with
  `read()` and accumulates them in a static buffer (`tamp`) that persists
  between calls. Each call:

  1. Pulls whatever was already buffered from the previous call (`firstfill`).
  2. Keeps `read`-ing and appending (`ft_readline`, `ft_strjoin`) until a
    `\n` or EOF is found.
  3. Splits what was read: the current line is returned, and anything read
    past the `\n` is saved back into the static buffer for the next call
    (`lastfill`).
  4. Cleans up and returns `NULL` once there is nothing left to read.

  | File | Role |
  |---|---|
  | `get_next_line.c` / `.h` | Mandatory part: one file descriptor at a time |
  | `get_next_line_bonus.c` / `.h` | Bonus part: multiple file descriptors handled in parallel (static buffer is an array indexed by `fd`), using a single static variable overall |
  | `get_next_line_utils.c` / `get_next_line_utils_bonus.c` | Helper functions: `ft_strlen`, `ft_calloc`, `ft_strjoin`, `ft_check`, `lastfill` |
  | `main.c` | Small manual test program reading a local `test` file |

  ## Usage

  ```c
  #include "get_next_line.h"

  int main(void)
  {
      int fd = open("test", O_RDONLY);
      char *line;

      line = get_next_line(fd);
      while (line)
      {
          printf("%s", line);
          free(line);
          line = get_next_line(fd);
      }
      close(fd);
  }
  ```

  ## Compiling

  ```sh
  # mandatory part
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

  # bonus part
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
  ```

  ## Author

  Maxime Pirt — 42 Cursus
