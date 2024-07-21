# Conway's Game of Life
>"The **Game of Life**, also known simply as **Life**, is a cellular automaton devised by the British mathematician  John Horton Conway  in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete  and can simulate a universal constructor or any other Turing machine."

Reference: [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

# How to run?
Install the dependencies:
```bash
# Debian, Ubuntu and deriveds
sudo apt-get install libncurses5-dev libncursesw5-dev
```
Clone repository:
```bash
git clone https://github.com/rafaelcarvalhoj/game-of-life.git && \
	cd game-of-life
```
Build program:
```bash
make # ignore warnings 😜
```
Run **Game of Life**:
```bash
./main patterns/<some pattern>
```
Conway's Game of Life can transition through an infinite number of states. To stop the game, press `Ctrl + C`. Alternatively, you can wait until the game reaches a repeated state, where it executes the same state twice in a row.

# Exemple Patterns
- **Glider:** `patterns/glider`
- **Blinker:** `patterns/blinker`

You can create your own patterns by placing a configuration of cells in a text file. Each cell is represented by a `*`, and empty spaces are represented by a space character.

# Contact
For any questions or issues, please contact *rrafaelcarvalhoj@gmail.com* or open an issue on [GitHub](https://github.com/rafaelcarvalhoj/game-of-life/issues).





