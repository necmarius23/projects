#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::endl;


//Creating a template class T
template <class T>
//Using the new class T to create a container that will manage a vector of objects
class Container
{
private:
	//Using the standard template library vector to create the container
	std::vector<T> container;
	//A string that will determine the type of the video that is stored
	std::string videoType;
public:
	// Default Constructor
	Container() = default;
	//Constructor with parameters
	Container(std::string videoType)
	{
		this->videoType = videoType;
	}
	//Get Method for video Type attribute
	std::string getVideoT()
	{
		return this->videoType;
	}
	//A method that allows adding elements to the container
	void addElement(T element)
	{
		this->container.push_back(element);
	}
	//A method that prints the elements of the container
	void printContainer()
	{
		std::cout << "This container stores videos depicting: " << getVideoT() << endl;
		for (int i = 0; i < this->container.size(); i++)
		{
			std::cout << container[i] << endl;
		}
	}
};
//A class that simulates a video uploaded on an online platform
class Videos {
private:
	char* videoName;
	int videoNumber;
	int* viewsNumber;
	const int idVideo;
public:
	//Declaring constructors for the class
	Videos():idVideo(0)
	{
		videoName = NULL;
		viewsNumber = NULL;
		videoNumber = 0;
	}
	Videos(int idVideo, const char* videoName, int videoNumber, int* viewsNumber) :idVideo(idVideo)
	{
		this->videoNumber = videoNumber;
		this->videoName = new char[strlen(videoName) + 1];
		strcpy_s(this->videoName,strlen(videoName)+ 1, videoName);
		if (viewsNumber != NULL)
		{
			this->viewsNumber = new int[videoNumber];
			for (int i = 0; i < videoNumber; i++)
			{
				this->viewsNumber[i] = viewsNumber[i];
			}
		}
		else
		{
			this->viewsNumber = NULL;
			this->videoNumber = 0;
		}
	}
	Videos(const char* videoName, int videoNumber, int* viewsNumber) :idVideo(2)
	{
		this->videoNumber = videoNumber;
		this->videoName = new char[strlen(videoName) + 1];
		strcpy_s(this->videoName, strlen(videoName) + 1, videoName);
		if (viewsNumber != NULL)
		{
			this->viewsNumber = new int[videoNumber];
			for (int i = 0; i < videoNumber; i++)
			{
				this->viewsNumber[i] = viewsNumber[i];
			}
		}
		else
		{
			this->viewsNumber = NULL;
			this->videoNumber = 0;
		}
	}
	Videos(const Videos& v) : idVideo(v.idVideo)
	{
		this->videoNumber = v.videoNumber;
		this->videoName = new char[strlen(v.videoName) + 1];
		strcpy_s(this->videoName, strlen(v.videoName) + 1, v.videoName);
		if (v.viewsNumber != 0)
		{
			this->viewsNumber = new int[v.videoNumber];
			for (int i = 0; i < v.videoNumber; i++)
			{
				this->viewsNumber[i] = v.viewsNumber[i];
			}
		}
	}
	//Overloading the operator =
	Videos& operator=(const Videos& v)
	{
		this->setVideoName(v.videoName);
		this->setNrVideos(v.videoNumber);
		this->setViewsNumber(v.videoNumber, v.viewsNumber);
		return *this;
	}
	//Get and set methods
	int getNrVideos()
	{
		return this->videoNumber;
	}
	char* getVideoName()
	{
		char* aux = new char[strlen(this->videoName) + 1];
		strcpy_s(aux, strlen(this->videoName) + 1, this->videoName);
		return aux;
	}
	int* getViewsNumber()
	{
		int* aux = new int[getNrVideos()];
		for (int i = 0; i < getNrVideos(); i++)
		{
			aux[i] = this->viewsNumber[i];
		}
		return aux;
	}
	void setNrVideos(int videoNumber)
	{
		if (videoNumber > 0)
			this->videoNumber = videoNumber;
		else
			this->videoNumber = 0;
	}
	void setViewsNumber(int nr, int* views)
	{
		if (this->viewsNumber)
			delete[] this->viewsNumber;
		if (views != NULL)
		{
			this->viewsNumber = new int[nr];
			for (int i = 0; i < nr; i++)
			{
				this->viewsNumber[i] = views[i];
			}
		}
		else
		{
			this->viewsNumber = NULL;
			this->videoNumber = 0;
		}
	}
	void setVideoName(const char* video)
	{
		if (videoName != NULL)
			delete[] this->videoName;
		if (video != NULL)
		{
			this->videoName = new char[strlen(video) + 1];
			strcpy_s(this->videoName, strlen(video) + 1, video);
		}
	}
	//A method that computes the total nr of videos
	int sum()
	{
		int sum = 0;
		for (int i = 0; i < this->getNrVideos(); i++)
		{
			sum += this->viewsNumber[i];
		}
		return sum;
	}
	// Destructor 
	~Videos()
	{
		if (videoName != NULL)
		{
			delete[] this->videoName;
		}
		if (this->viewsNumber)
			delete[] viewsNumber;
	}
	//Overloading operators
	explicit operator int()
	{
		return this->sum();
	}
	int operator()()
	{
		return this->sum();
	}
	//Creating a virutal method 
	virtual void isVideo()
	{
		std::cout << "Video is cool" << endl;
	}

};
// Overload of operator << for file management
std::ofstream& operator<<(std::ofstream& o, Videos& v)
{
	if (o.is_open())
	{
		o << v.getNrVideos();
		o << v.getVideoName();
		int* vect = v.getViewsNumber();
		for (int i = 0; i < v.getNrVideos(); i++)
		{
			o << vect[i];
			o << " ";
		}
		delete[] vect;
	}
	return o;
}
// Overload of operator << for object printing
std::ostream& operator<<(std::ostream& out, Videos v)
{
	out << v.getVideoName() << endl;
	out << v.getNrVideos()<< endl;
	int* views = v.getViewsNumber();
	for (int i = 0; i < v.getNrVideos(); i++)
	{
		out << views[i];
		out << endl;
	}
	delete[] views;
	out << endl;
	return out;
}
// Overload of operator >> for object creation
std::istream& operator>>(std::istream& in, Videos& v)
{
	std::cout << "Enter the name of the video"<< endl;
	char name[31];
	in.getline(name, 31);
	v.setVideoName(name);
	std::cout << "Enter the nr of videos " << endl;
	int nrVideos;
	in >> nrVideos;
	nrVideos > 0;
	v.setNrVideos(nrVideos);

	std::cout << "Enter the views nr for the videos" << endl;
	int* viewsNumber = new int[nrVideos];
	for (int i = 0; i < nrVideos; i++)
	{
		in >> viewsNumber[i];
		std::cout << " ";
	}
	v.setViewsNumber(nrVideos, viewsNumber);
	delete[] viewsNumber;
	in.clear();
	in.ignore(INT_MAX, '\n');
	return in;
}
//Overload of bool operator > 
bool operator>(Videos v, Videos o)
{
	if (v.sum() > o.sum())
		return true;
	else
		return false;
}
//A class that simulates pet videos
class PetVideos: public Videos {
private:
	std::string petType;
public:
	//Constructor declaration and implementation
	PetVideos() = default;
	PetVideos(std::string petType, const char* videoName, int videoNumber, int* viewsNumber) :
		Videos(videoName, videoNumber, viewsNumber)
	{
		this->petType = petType;
	}
	//Overload of operator = 
	PetVideos& operator=(const PetVideos p)
	{
		Videos::operator=(p);
		petType = p.petType;
		return *this;
	}
	//get method for petType attribute
	std::string getPet()
	{
		return this->petType;
	}
	//Overriding of isVideo method
	void isVideo()
	{
		std::cout << "Video is cute" << endl;
	}
	//declaration of operator<< for PetVideos class
	friend std::ostream& operator<<(std::ostream&, PetVideos& p);
};
//Implementation of operator<< for PetVideos class
std::ostream& operator<<(std::ostream& out, PetVideos& p)
{
	out << p.getPet() << endl;
	out << (Videos)p;
	return out;
}

int main()
{
	//Creating different objects of type Videos
	Videos v1;
	int viewsNumber[3] = { 100000,20000, 3000000 };
	Videos v34("Influencer1", 3, viewsNumber);
	Videos v2(1, "Influencer2", 3, viewsNumber);
	Videos v3 = v2;
	int views[3] = { 1000, 20201, 23931 };
	//Testing of set methods
	v1.setNrVideos(3);
	v1.setViewsNumber(3, views);
	v1.setVideoName("InfluencerV2");
	// Testing operator = overload for ckass Videos
	v3 = v1;
	//Testing operator << overload for class Videos
	std::cout << v3;

	if (v2 > v1)
		std::cout << "V2 greater" << endl;
	else
		std::cout << "V1 greater" << endl;
	//Testing cast to int operator
	std::cout << (int)v2 << endl;
	//Testing cin operator
	Videos v4;
	std::cin >> v4;
	std::cout << v4;
	//Testing the () operator overload 
	std::cout << v4() << endl;
	//Testing the operator << for file management
	std::string file;
	std::cout << "Enter file name with extension .txt: " << endl;
	std::cin >> file;
	int viewsFirst[3] = { 111,222,333 };
	int viewsSecond[4] = { 121,111,1233,222 };
	Videos vp1(12, "Bla", 3, viewsFirst);
	Videos vp2(13, "Blo", 4, viewsSecond);
	Videos vp3(14, "Zi", 3, viewsFirst);
	Videos vp4(15, "Wws", 3, viewsFirst);
	Videos vp5(16, "Sad", 4, viewsFirst);
	Videos vector[5] = {vp1, vp2, vp3, vp4, vp5};
	std::ofstream fisierObj;
	fisierObj.open(file, std::ios::out);
	for (int i = 0; i < 5; i++)
	{
		if (vector[i].getNrVideos() < 4)
		{
				fisierObj << vector[i];
		}
	}
	fisierObj.close();
	//Creating an object of type PetVideos
	PetVideos p("Dog", "Doggo eats peanuts", 3, viewsFirst);
	//Testing the overload of operator << for PetVideos
	std::cout << p;
	//Testing the overriding of the method isVideo
	p.isVideo();
	v2.isVideo();
	//Creating a container for PetVideos class
	Container<PetVideos> p2("Dog");
	//Testing the methods
	p2.addElement(p);
	p2.printContainer();
	//Creating a vector of Videos 
	std::vector <Videos> videoArray;
	videoArray.push_back(v2);
	videoArray.push_back(v3);
	for (int i = 0; i < videoArray.size(); i++)
	{
		std::cout << videoArray[i] << endl;
	}
}