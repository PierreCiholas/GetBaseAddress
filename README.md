# GetBaseAddress
C++ function and PoC using Windows API to get the base address of a process (useful to then use pointers from base)

The source includes the function and a code in the main, prompting the user for a process ID (PID).
Once specified, the main function executes the GetBaseAddress function on this PID and prints the base address in console.

The iostream header is only required when prompting the user for his PID and printing it to the console, if used separately in a larger code, the iostream is optional.
