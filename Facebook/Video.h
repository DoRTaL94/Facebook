#ifndef VIDEO
#define VIDEO

#include "Status.h"

class Video : virtual public Status
{
protected:
	bool isVidUploaded;

public:
	Video();
	Video(const Entity *statusCreator);
	
	virtual void printStatus() const;
	virtual bool operator==(const Status& other) const;
	virtual bool operator!=(const Status& other) const;
	bool isVideoExist() const;
	void uploadVideo();
	
	virtual ~Video();
};

#endif