# projects
video_app project

Necsoiu Marius

Through this application I wanted to describe the OOP concepts I learned.
I wanted to create an application that manages videos on an online platform.
Firstly, I created a class Video that has the following attributes: videoName (dynamic array of characters)
that will hold the name of a video,videoNumber, an integer that denotes the number of videos on the platform,
viewsNumber, a dynamic array of integers, describing the views of each video posted, idVideo,
a constant variable that holds the id of each video posted;

For the class I declared and implemented the default Constructor, a constructor with parameters,
a copy constructor and a destructor;
I implemented set and get methods for every attribute.The class has different methods such as:
The virtual method isVideo() that prints a statement, the sum() that returns the sum of the views;
While creating the app I found the need to overload the following operators:
The explicit operator int() that returns the sum of the views, the operator () that also returns the sum of the views,
the ostream << operator in order to be able to print objects of type Video; the istream >> operator in order to be able to read objects 
from the keyboard(to get input from the user), the ofstream operator << in order to be able to save objects of type Video to files,
the bool operator > in order to be able to compare objects of type Video;
Then I created a PetVideos class that inherits the Video class I defined earlier. This class has an attribute of type string called
petType that describes the type of pet that the video shows;
This class has a default constructor declared and a Constructor with parameters.The overload of operator= and was also implemented
for this class. A get method for the petType attribute was implemented.
I overriden the isVideo() method which now prints the statement "Video is cute";
Using friend functions I overloaded the ostream operator <<;
After that I used template classes to implement a class Container that will manage objects of any type;
The new Container class has two private attributes, one of type std::vector that will manage the objects
and one of type string, videoType, that describes the type of video contained;
For this class a default constructor and a constructor with parameters was implemented and a get method for the videoType attribute;
Another two methods were built, one that allows the user to add a new element to the container and one that prints the elements of 
the container;
In main you can find tests for all the methods implemented earlier;

