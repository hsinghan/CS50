// Helper functions for music
#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    // Example: "1/1", "1", "1/2", "1/4", "3/8"
    int molecular = fraction[0] - '0';
    int denominator = fraction[2] - '0';
    return (molecular * (8 / denominator));
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    // A4 is 440.0hz
    // Example : A4, A#4
    // 1. Consider that they are in the same obtave.
    // i.e., C4, D4, ...,A4, B4
    double freq = 0.0;
    switch (note[0])
    {
        case 'C':
            freq = 440.0 / pow(2.0, 9.0 / 12.0);
            break;
        case 'D':
            freq = 440.0 / pow(2.0, 7.0 / 12.0);
            break;
        case 'E':
            freq = 440.0 / pow(2.0, 5.0 / 12.0);
            break;
        case 'F':
            freq = 440.0 / pow(2.0, 4.0 / 12.0);
            break;
        case 'G':
            freq = 440.0 / pow(2.0, 2.0 / 12.0);
            break;
        case 'A':
            freq = 440.0;
            break;
        case 'B':
            freq = 440.0 * pow(2.0, 2.0 / 12.0);
            break;
    }

    // tips: char - '0'  is used to change from char type to int type
    // 2. Consider the distance
    if (isdigit(note[1]))
    {
        freq = (note[1] - 4 > 0 ? freq * pow(2.0, note[1] - '0' - 4) : freq / pow(2.0, abs(note[1] - '0' - 4)));
    }
    else if (isdigit(note[2]))
    {
        freq = (note[2] - 4 > 0 ? freq * pow(2.0, note[2] - '0' - 4) : freq / pow(2.0, abs(note[2] - '0' - 4)));
    }

    // 3. Condiser if the sharp or flap exist to adjust the tone.
    if (note[1] == 'b')
    {
        freq /= pow(2, 1 / 12.0);
    }
    else if (note[1] == '#')
    {
        freq *= pow(2, 1 / 12.0);
    }
    return round(freq);

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    if (s[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
