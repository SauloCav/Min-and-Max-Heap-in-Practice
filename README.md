# Min-and-Max-Heap-in-Practice

<strong>A scenario for managing queues and service counters using Heaps min and max</strong>

<strong>Activity proposal:</strong></br>
Consider the scenario of a company that provides services to the public through service counters.</br>
When the customer arrives at the establishment, he goes to the password menu informing:</br>
• the type of service you want, whether for Individuals (PF) or Legal Entities (PJ).</br>
• and if the service is a priority, when self-declaring as being: people with physical disabilities, elderly people aged over 60 years, pregnant women, nursing mothers and people   accompanied by infants.</br>
After including this information, the system will generate a password, respecting the service queue in which the customer will be allocated. This customer, like the others, will be attended to while everyone in front of him is called.</br>
The service at the establishment starts after the opening of at least two cashiers, one of which is exclusive for priority service (box 0). Once opened, the service process is started by calling customers from the queue.</br>
Points of observation:</br>
▪ Cashier 0 can perform non-priority service, if the priority queue is empty.</br>
▪ Non-priority cashiers will be able to attend priority customers if the non-priority queue is empty.</br>
▪ During the day, according to demand, new cashiers can be opened or closed, including cashier 0, which will have its function assumed by another cashier.</br>
▪ The minimum amount of active boxes, during the day, must be equal to one after the opening of the service.</br>
▪ If we have only one teller in operation, it must provide priority and non-priority services.</br>
▪ Closing of all service boxes can only occur after all customers have been serviced.</br>
The program must show at all times the current status of the cashiers (the passwords of the customers who are being served at that moment) and of the waiting line(s). It should also show a menu containing options for: generating a password for a new client; call of a new customer for assistance and opening/closing actions of a cashier.
