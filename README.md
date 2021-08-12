# Data-Structures-Project

A system for Uber Technologies. System is divided into two parts. Car Hailing and Bus Transport Service. program that reads information from a text file “city data.txt”. The input format is described in detail below.
5
Lahore 	Faisalabad	9	2
Lahore 	Multan	12	1
Faisalabad	Islamabad	18	0.5
Faisalabad	Multan	6	10
Faisalabad	Sheikhupura	20	5
Multan	Sheikhupura	15	6

That says that there are five cities. The distance between Lahore and Faisalabad is 9 and cost/passenger on that route is 2.The output for this input would be as follows. 

(Lahore ,Faisalabad) distance 9 km and cost/passenger is 2 for Bus Service.
(Lahore ,Multan) weights 12km and cost/passenger is 1 for Bus Service.
(Faisalabad,Islamabad) weights 18km and cost/passenger is 0.5 for Bus Service.
(Faisalabad,Multan) weights 6km and cost/passenger is 10 for Bus Service.
(Faisalabad,Sheikhupura) weights 20km and cost/passenger is 5 for Bus Service.
(Multan,Sheikhupura) weights 15km and cost/passenger is 6 for Bus Service.

The program 
•	Calculate shortest path from each city to another city
•	Find the path from one city to another city with minimum number of hops
•	The user can generate request for a ride. There are two types of user: Normal User and Premium User. The Premium user has priority over Normal user. Premium user will be assigned car first. The normal user will be assigned car later according to their position in file. 
•	After assigning the ride your system will find the shortest path from user’s current location to destination in O(1) time and will print it on console

2.	The company is facing a financial crisis in its Bus Transport Service and wants to minimize its Bus Service Operational Cost. Given the cost per passenger from one city to another. Find the route between all cities whose cost is minimum among all routes.

