// Buggy example for printf and debug50

#include <stdio.h>

int main(void)
{
    for (int i = 0; i <= 10; i++)
    {
        // printf("i is now %i: ", i);  // change 1
        printf("#\n");
    }
}

// run `make buggy2` in the command line and it runs with no errors

// then run `./buggy2` but it prints 11 #, not 10 which was the goal.

// then add `printf` to run diagnostics - noted as change 1 in above code.

// now when you run the code it looks a little different:
    // instead of just print the #'s it now adds "i is now 0:" in front of the #'s.
    // now you are able to see why there is 11 and not 10, it starts at 0, not 1.

// now you can remove the `=` from line 7 where `i <= 10;` now will be `i < 10;`

// Debugging with "Debugger" in CS50 IDE:

    // run `make buggy2` in the command line and it runs with no errors

    // then run `./buggy2` but it prints 11 #, not 10 which was the goal.

    // click on the left of a line number and you will see a red dot appear next to the number, this is adding a "breakpoint" to your code.

    // then run `debug50 ./buggy2` in the command line.

    // debug50 will then open a window on the right for the debugger and will highlight line 7 in the above code because that is the first line of code that will actually be ran.

    // in the debugger window it will tall you the variable, value, and type. at first it will be 0 for the value because i starts at 0.

    // in the top left of the debugger window is 5 icons.
        // - |> = a play button which runs the rest of the code (not useful if you are trying to walk through your code step by step)
        // - top half of a circle = Step over - will step over 1 line of code at a time and execute it.