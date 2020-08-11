TR069 CPE APPLICETION
------------------------------------------------------
TR69C version 1.0
This program is in CPE side that implements some TR069 protocol functions.
About TR069 protocol, Can get detail from http://www.dslforum.org.

Use 'make' to get cpe binary file named 'tr69c'. 

The 'cpetools' directory include two tools.
The cpesend can send simulate packet to server or application.
put the simulate packet file in 'message' directory, named XXX.txt, and follow this usage:
./cpesend www.server.com 8080 XXX;
Then you can see the received message in screen.

The cpeserver can receive simulate packet from client or application.
Usage:
./cpeserver 9090 XXX
The XXX is mean message/XXX.txt, if cpeserver receive any packet, it will send back the XXX.txt.
All information will print in screen.
