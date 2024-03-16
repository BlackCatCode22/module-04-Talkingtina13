I defined the Animal class with properties name, age, and species. 

Subclasses Hyena, Lion, Tiger, and Bear are created, inheriting from Animal class. These subclasses have constructors to initialize specific attributes and call the base class constructor.

In main function, I read data from the input file line by line, creating instances of the appropriate subclass based on the species mentioned.

I used a std::vector to store pointers to Animal objects and a std::map to count the occurrences of each species.
