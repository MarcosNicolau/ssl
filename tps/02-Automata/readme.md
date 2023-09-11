# T.P 2

The goal of this assignment was to develop two programs.

One which could validate a string composed of octal, decimal, and hexadecimal numbers, separated by a '$'.

And another, given a string composed of decimal numbers and the 4 essential operators, should calculate and return the result.

You can read the full assignment [here](./assignment.md).

## Automata

To validate the strings the following automata were used:

-   [first exercise](./assets/automata_1.png)
-   [third exercise](./assets/automata_2.png)

The failure states were ignored in the graphics because it became a real mess. :)

### Disclaimer

The autómatas were drawn using [graphviz](http://magjac.com/graphviz-visual-editor/).

## Run the programs

1. Give permission to the script: `chmod +x ./run.sh`
2. Execute it: `$ ./run.sh <PROGRAM> <ARGUMENT>` or run `./run.sh --help` for help.
