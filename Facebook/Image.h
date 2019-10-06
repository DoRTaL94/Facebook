#ifndef IMAGE
#define IMAGE

#include "Status.h"

class Image : virtual public Status
{
protected:
	bool isImgUploaded;

public:
	Image();
	Image(const Entity *statusCreator);
	
	virtual void printStatus() const;
	virtual bool operator==(const Status& other) const;
	virtual bool operator!=(const Status& other) const;
	bool isImgExist() const;
	void uploadImage();
	
	virtual ~Image();
};

#endif // !IMAGE
