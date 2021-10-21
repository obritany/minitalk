# minitalk

Minitalk is a small data exchange program using only 2 signals (SIGUSR1 and SIGUSR2) to send a message.

## Description

Minitalk is a communication program in the form of a client and a server. The server must be started first, and must after launch show its PID.

The client takes as parameters:

- the server's PID

- a string of characters to transmit

The client communicates to the server the string passed in parameter. Once fully received, the server displays it.

- communication between processes are only done using UNIX signals (following POSIX).

The server is able to receive strings from multiple clients in a row, without restarting.

- only one global variable is allowed

- only the use of both signals SIGUSR1 and SIGUSR2 are allowed
