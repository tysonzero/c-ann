C-ANN
=====

An Artificial Neuron Network

Instructions:
-------------

Compile ann.c with your favorite C compiler.

Next run the output file.

The program will wait for 5 inputs in the following format:

    (int[3]) ANN input, (double) increment, (double) mutation increment

If you do not want to mutate the ANN just pass 0 as the last argument.

It will then print the output of the ANN and repeat the process.

Sticks Instructions:
--------------------

Compile sticks.c with your favorite C compiler.

Next run the output file.

The program will output the starting setup of a sticks game in the following format:

    Current Turn
    First Player's Hands
    Second Player's Hands

It will then wait for 3 inputs in the following format:

   (1/0) whether or not to attack
   if 1:
       (1/0) hand to use
       (1/0) hand to attack
   else:
       (1/0) 2, (1/0) 1: number of fingers to end with on first hand (sum the numbers)

If the move is not possible it will try and get as close as possible.

Next it will repeate the process.
